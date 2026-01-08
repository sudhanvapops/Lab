#include <stdio.h>

int main() {
    char str[100], pat[100], rep[100], ans[200];
    int i = 0, j = 0, k, match;

    printf("Enter main string: ");
    fgets(str, 100, stdin);

    printf("Enter pattern: ");
    fgets(pat, 100, stdin);

    printf("Enter replace string: ");
    fgets(rep, 100, stdin);

    while (str[i] != '\0') {
        match = 1;

        // check pattern match
        for (k = 0; pat[k] != '\n' && pat[k] != '\0'; k++) {
            if (str[i + k] != pat[k]) {
                match = 0;
                break;
            }
        }

        if (match) {
            // copy replace string
            for (k = 0; rep[k] != '\n' && rep[k] != '\0'; k++)
                ans[j++] = rep[k];

            i += k;   // skip matched pattern
        } else {
            ans[j++] = str[i++];
        }
    }

    ans[j] = '\0';
    printf("Result: %s", ans);

    return 0;
}
