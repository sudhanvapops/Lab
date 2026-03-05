#include <stdio.h>

#define MAX 20
#define INF 999

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int i, j, min, u, v;
    int edges = 1, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    visited[1] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n) {
        min = INF;

        for (i = 1; i <= n; i++)
            if (visited[i])
                for (j = 1; j <= n; j++)
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