// Design and implement C/C++ Program to obtain the Topological ordering of vertices in a given digraph.

#include <stdio.h>

#define MAX 10

int a[MAX][MAX], indegree[MAX], n;

// Calculate indegree of each node
void calculateIndegree() {
    for (int j = 0; j < n; j++) {
        indegree[j] = 0;
        for (int i = 0; i < n; i++)
            indegree[j] += a[i][j];
    }
}

// Perform Topological Sort
void topologicalSort() {
    int stack[MAX], top = -1, result[MAX], k = 0;

    calculateIndegree();

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            stack[++top] = i;

    while (top != -1) {
        int u = stack[top--];
        result[k++] = u;

        for (int v = 0; v < n; v++) {
            if (a[u][v]) {
                if (--indegree[v] == 0)
                    stack[++top] = v;
            }
        }
    }

    printf("Topological Order:\n");
    for (int i = 0; i < k; i++)
        printf("%d ", result[i]);
}

// Input function (modular)
void inputGraph() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

int main() {
    inputGraph();
    topologicalSort();
    return 0;
}

// Enter number of nodes: 6
// Enter adjacency matrix:
// 0 0 1 1 0 0
// 0 0 0 1 1 0
// 0 0 0 1 0 1
// 0 0 0 0 0 1
// 0 0 0 0 0 1
// 0 0 0 0 0 0
// Topological Order:
// 1 4 0 2 3 5