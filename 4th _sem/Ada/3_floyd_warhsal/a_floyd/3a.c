// 3a. Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem using Floyd's algorithm.

#include <stdio.h>
#define MAX 20

int a[MAX][MAX], n;

void readMatrix() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void floyd() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
}

void printMatrix() {
    printf("All Pair Shortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main() {
    printf("***** Floyd's Algorithm *****\n");
    readMatrix();
    floyd();
    printMatrix();
    return 0;
}



// *****FLOYD'S ALGORITHM*****
// Enter the number of vertices
// 4
// Enter the cost matrix of the graph:					
// 0	999	3	999
// 2	0	999	999
// 999	7	0	1
// 6	999	999	0

// All Pair Shortest path matrix
// 0	10	3	4
// 2	0	5	6
// 7	7	0	1
// 6	16	9	0


