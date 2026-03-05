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
    int i, j, min, a, b, u, v;
    int edges = 1, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n) {
        min = INF;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
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