// Design and implement C Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Prim's algorithm

#include <stdio.h>

#define MAX 20
#define INF 999

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int min, u, v;
    int edges = 1, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    visited[1] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n) {
        min = INF;

        for (int i = 1; i <= n; i++)
            if (visited[i])
                for (int j = 1; j <= n; j++)
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }

        printf("Edge %d: (%d,%d) Cost=%d\n", edges++, u, v, min);
        mincost += min;
        visited[v] = 1;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}

// Enter number of vertices: 6

// Enter adjacency matrix:
// 0 60 10 999 999 999
// 60 0 999 20 40 70
// 10 999 0 999 999 50
// 999 20 999 0 999 80
// 999 40 999 999 0 30
// 999 70 50 80 30 0

// Edges in Minimum Spanning Tree:
// Edge 1: (1,3) Cost=10
// Edge 2: (3,6) Cost=50
// Edge 3: (6,5) Cost=30
// Edge 4: (5,2) Cost=40
// Edge 5: (2,4) Cost=20
// Minimum Cost = 150