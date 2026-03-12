// 3b. Design and implement C/C++ Program to find the transitive closure using Warshal's algorithm.

#include <stdio.h>
#define MAX 20

int a[MAX][MAX], n;

void readMatrix() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void warshall() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
}

void printMatrix() {
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main() {
    printf("***** Warshall's Algorithm *****\n");
    readMatrix();
    warshall();
    printMatrix();
    return 0;
}



// *****WARSHALL'S ALGORITHM*****
// Enter the number of vertices
// 4
// Enter the adjacency matrix (1 if there is edge and 0 if there is no direct edge)		
// 0	1	0	0
// 0	0	0	1
// 0	0	0	0
// 1	0	1	0
	 
// The Transitive Closure Matrix is 
// 1	1	1	1
// 1	1	1	1
// 0	0	0	0
// 1	1	1	1