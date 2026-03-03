#include <stdio.h>
#define MAX 10

int n, m;
int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
int avail[MAX], finish[MAX], safeSeq[MAX];

void readMatrix(int mat[MAX][MAX], char *name) {
    printf("\nEnter %s Matrix:\n", name);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
}

void readAvailable() {
    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);
}

/* Need = Max - Allocation */
void calculateNeed() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

/* Safety Algorithm */
int isSafe() {
    int work[MAX], count = 0;

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    for (int i = 0; i < n; i++)
        finish[i] = 0;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                // Check if process i can execute
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;
                
                if (j == m) {   // can execute
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                        // Release resources after execution

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0;   // unsafe
    }
    return 1;           // safe
}


int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    readMatrix(alloc, "Allocation");
    readMatrix(max, "Maximum");
    readAvailable();

    calculateNeed();

    if (isSafe()) {
        printf("\nSystem is in SAFE state\nSafe Sequence: ");
        for (int i = 0; i < n; i++)
            printf(i != n-1 ? "P%d -> ": "P%d", safeSeq[i]);
    } else {
        printf("\nSystem is in UNSAFE state (Deadlock possible)");
    }

    return 0;
}

// ! Output
// Enter number of processes: 5
// Enter number of resources: 3
// 
// Enter Allocation Matrix:
// 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 
// 
// Enter Maximum Matrix:
// 7 5 3 3 2 2 9 0 2 4 2 2 5 3 3
// 
// Enter Available Resources:
// 3 3 2
// 
// System is in SAFE state.
// Safe Sequence is: P1 P3 P4 P0 P2