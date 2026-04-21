#include <stdio.h>

#define MAX 10

int s[MAX], x[MAX], d;

/* ---------- Print Subset ---------- */
void printSubset(int k) {
    for (int i = 1; i <= k; i++) {
        if (x[i] == 1)
            printf("%d ", s[i]);
    }
    printf("\n");
}

/* ---------- Backtracking Core ---------- */
void sumOfSubsets(int p, int k, int r) {
    x[k] = 1;

    if (p + s[k] == d) {
        printSubset(k);
    }
    else if (p + s[k] + s[k + 1] <= d) {
        sumOfSubsets(p + s[k], k + 1, r - s[k]);
    }

    if ((p + r - s[k] >= d) && (p + s[k + 1] <= d)) {
        x[k] = 0;
        sumOfSubsets(p, k + 1, r - s[k]);
    }
}

/* ---------- Utility ---------- */
int computeSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += s[i];
    return sum;
}

void inputSet(int n) {
    printf("Enter the set in increasing order: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
}

/* ---------- Main ---------- */
int main() {
    int n;

    printf("Enter the n value: ");
    scanf("%d", &n);

    inputSet(n);   // DRY

    printf("Enter the max subset value: ");
    scanf("%d", &d);

    int total = computeSum(n);

    if (total < d || s[1] > d)
        printf("No subset possible\n");
    else
        sumOfSubsets(0, 1, total);

    return 0;
}