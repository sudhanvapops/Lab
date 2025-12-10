#!/usr/bin/env bash
# tomcat-enum.sh
# Gentle Tomcat URL enumerator (safe defaults).
# Usage: ./tomcat-enum.sh 51.20.136.98
# Output: ./results/all_urls.txt  (and other logs in ./results/)

set -eo pipefail
TARGET="$1"
if [[ -z "$TARGET" ]]; then
  echo "Usage: $0 <target-ip-or-host>"
  exit 1
fi

WORKDIR="results"
mkdir -p "$WORKDIR"
TIMESTAMP=$(date -u +%Y%m%dT%H%M%SZ)
HOMEPAGE_HTML="$WORKDIR/homepage.html"
WGET_LOG="$WORKDIR/wget_spider.log"
GOBUSTER_OUT="$WORKDIR/gobuster.txt"
WGET_URLS="$WORKDIR/urls_from_wget.txt"
GREP_URLS="$WORKDIR/urls_from_greps.txt"
ALL_URLS="$WORKDIR/all_urls.txt"
WORDLIST="/usr/share/wordlists/dirb/common.txt"
if [[ ! -f "$WORDLIST" ]]; then
  # small builtin fallback list
  WORDLIST="$WORKDIR/fallback-wordlist.txt"
  cat > "$WORDLIST" <<'EOF'
admin
manager
docs
examples
app
api
test
webapps
java
poly
ROOT
EOF
fi

echo "[+] Target: $TARGET"

# 1) Basic port check (nmap if available, otherwise curl ping)
if command -v nmap >/dev/null 2>&1; then
  echo "[+] Running light nmap scan (ports 80,443,8080,8009,8443)"
  nmap -sV -p 80,443,8080,8009,8443 "$TARGET" -oN "$WORKDIR/nmap.txt" || true
  echo "  -> nmap results saved to $WORKDIR/nmap.txt"
else
  echo "[!] nmap not found — skipping nmap scan. Install nmap for richer info."
fi

# 2) Fetch homepage (follow redirects) and save
echo "[+] Fetching homepage (HTTP)"
if command -v curl >/dev/null 2>&1; then
  curl -L --max-time 15 "http://$TARGET/" -sS -o "$HOMEPAGE_HTML" || true
else
  echo "[!] curl not found — try installing curl." >&2
fi

# 3) Extract links from homepage
echo "[+] Extracting links from homepage"
if [[ -f "$HOMEPAGE_HTML" ]]; then
  # extract href/src values — produce absolute-ish paths
  grep -Eoi '(href|src)=["'\''][^"'\'']+' "$HOMEPAGE_HTML" | sed -E 's/(href|src)=["'\'']//I' | sed -E 's/["'\'']$//' | sort -u > "$GREP_URLS"
  awk -v base="http://$TARGET" '{ if ($0 ~ /^http/) print $0; else if ($0 ~ /^\//) print base $0; else print base "/" $0 }' "$GREP_URLS" | sort -u > "$WORKDIR/links_from_homepage.txt" || true
  echo "  -> links saved to $WORKDIR/links_from_homepage.txt"
else
  echo "[!] Homepage not saved; skipping link extraction from homepage."
fi

# 4) Wget spider (gentle)
if command -v wget >/dev/null 2>&1; then
  echo "[+] Running wget spider (depth=3, gentle)"
  wget --spider -r -l 3 -w 1 --wait=0.5 "http://$TARGET/" -o "$WGET_LOG" || true
  # parse wget spider log for URLs
  grep -E "^--" "$WGET_LOG" | awk '{print $3}' | sort -u > "$WGET_URLS" || true
  echo "  -> wget discovered $(wc -l < "$WGET_URLS" 2>/dev/null || echo 0) urls (saved to $WGET_URLS)"
else
  echo "[!] wget not found — skipping wget spider."
fi

# 5) Probe a short list of common Tomcat paths
echo "[+] Probing common Tomcat paths"
COMMON=("/" "/manager/html" "/host-manager/html" "/docs/" "/examples/" "/ROOT/" "/index.jsp" "/index.html" "/favicon.ico" "/java/Poly.java" "/webapps/" "/META-INF/" "/WEB-INF/web.xml")
> "$WORKDIR/common_probe.txt"
for p in "${COMMON[@]}"; do
  url="http://$TARGET${p}"
  code=000
  if command -v curl >/dev/null 2>&1; then
    code=$(curl -s -o /dev/null -w "%{http_code}" --max-time 8 "$url" || echo 000)
  fi
  echo "$code $url" >> "$WORKDIR/common_probe.txt"
done

echo "  -> common probe saved to $WORKDIR/common_probe.txt"

# 6) Gentle directory discovery using gobuster if available
if command -v gobuster >/dev/null 2>&1; then
  echo "[+] Running gobuster (gentle). Wordlist: $WORDLIST"
  # run with conservative threads
  gobuster dir -u "http://$TARGET" -w "$WORDLIST" -x .jsp,.html,.war -t 20 -q -o "$GOBUSTER_OUT" || true
  echo "  -> gobuster output saved to $GOBUSTER_OUT"
else
  echo "[!] gobuster not installed — skipping dir brute-force."
fi

# 7) Consolidate discovered URLs
echo "[+] Consolidating results into $ALL_URLS"
> "$ALL_URLS"
for f in "$WORKDIR/links_from_homepage.txt" "$WGET_URLS" "$GOBUSTER_OUT" "$WORKDIR/common_probe.txt"; do
  if [[ -f "$f" ]]; then
    # normalize formats
    sed -E 's/^[0-9]{3}[[:space:]]*//g' "$f" | sed -E 's/\s+$//' >> "$ALL_URLS" || true
  fi
done

# also include raw gobuster URL hits (gobuster output format may contain ":" lines)
if [[ -f "$GOBUSTER_OUT" ]]; then
  # try to parse gobuster "Found: /path (Status: 200)" or similar
  grep -Eo '(http|https)://[^ ]+|/[^ ]+' "$GOBUSTER_OUT" 2>/dev/null | sed -E 's/$/\n/' >> "$ALL_URLS" || true
fi

# final cleanup and sort
if [[ -s "$ALL_URLS" ]]; then
  sort -u "$ALL_URLS" -o "$ALL_URLS"
  echo "[+] Done. Total unique URLs: $(wc -l < "$ALL_URLS")"
  echo "  -> $ALL_URLS"
else
  echo "[!] No URLs discovered (all_urls.txt is empty). Check logs in $WORKDIR/ for details."
fi

# 8) Helpful output: show top 30
if [[ -s "$ALL_URLS" ]]; then
  echo "\nTop results (first 30):"
  head -n 30 "$ALL_URLS"
fi

# End of script
echo "[+] Finished at $TIMESTAMP"
