// Design and implement C Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's algorithm.

#include <stdio.h>

#define MAX 20
#define INF 999

int n, cost[MAX][MAX], parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

void unite(int i, int j) {
    parent[j] = i;
}

int main() {
    int min, a, b, u, v;
    int edges = 1, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n) {
        min = INF;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        u = find(u);
        v = find(v);

        if (u != v) {
            unite(u, v);
            printf("Edge %d: (%d,%d) Cost=%d\n", edges++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum Cost = %d\n", mincost);
    return 0;
}


// Output

// Vertices: 6

// 0 60 10 999 999 999
// 60 0 999 20 40 70
// 10 999 0 999 999 50
// 999 20 999 0 999 80
// 999 40 999 999 0 30
// 999 70 50 80 30 0

// Edges in Minimum Spanning Tree:
// Edge 1: (1,3) Cost=10
// Edge 2: (2,4) Cost=20
// Edge 3: (5,6) Cost=30
// Edge 4: (2,5) Cost=40
// Edge 5: (3,6) Cost=50
// Minimum Cost = 150