// 12. Design and implement C/C++ Program for N Queen's problem using Backtracking.

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int a[MAX], count = 0;

/* ---------- Check Safe Placement ---------- */
int isSafe(int pos) {
    for (int i = 1; i < pos; i++) {
        if (a[i] == a[pos] || abs(a[i] - a[pos]) == abs(i - pos))
            return 0;
    }
    return 1;
}

/* ---------- Print Solution ---------- */
void printSolution(int n) {
    count++;
    printf("\n\nSolution #%d:\n", count);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf(a[i] == j ? "Q\t" : "*\t");
        }
        printf("\n");
    }
}

/* ---------- Backtracking Core ---------- */
void solveNQueens(int n) {
    int k = 1;
    a[k] = 0;

    while (k != 0) {
        a[k]++;

        while (a[k] <= n && !isSafe(k))
            a[k]++;

        if (a[k] <= n) {
            if (k == n)
                printSolution(n);
            else {
                k++;
                a[k] = 0;
            }
        } else {
            k--;   // backtrack
        }
    }
}

/* ---------- Main ---------- */
int main() {
    int n;

    printf("Enter the number of Queens\n");
    scanf("%d", &n);

    solveNQueens(n);

    printf("\nTotal solutions = %d\n", count);
    return 0;
}