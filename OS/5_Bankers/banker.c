#include <stdio.h>
#define MAX 10

int n, m;
int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
int avail[MAX], finish[MAX], safeSeq[MAX];

void readMatrix(int mat[MAX][MAX], char *name) {
    int i, j;
    printf("\nEnter %s Matrix:\n", name);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
}

void readAvailable() {
    int i;
    printf("\nEnter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);
}

void calculateNeed() {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int isSafe() {
    int i, j, k, count = 0;

    for (i = 0; i < n; i++)
        finish[i] = 0;

    while (count < n) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == m) { // process can run
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            return 0; // unsafe
    }
    return 1; // safe
}

int main() {
    int i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    readMatrix(alloc, "Allocation");
    readMatrix(max, "Maximum");
    readAvailable();

    calculateNeed();

    if (isSafe()) {
        printf("\nSystem is in SAFE state.\nSafe Sequence is: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
    } else {
        printf("\nSystem is in UNSAFE state! Deadlock possible.");
    }

    return 0;
}
