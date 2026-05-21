// Design and implement C Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's algorithm.

#include <stdio.h>

#define MAX 20
#define INF 999

// Cost: adj Matrix
// parent: tracks connected component 
// n: number of vertices
// INF means edge removed

int n, cost[MAX][MAX], parent[MAX];

// Find which group(vertex set) a node belongs to, find in the set
// Eg: parent[3] = 1; 3 belong to 1
int find(int i) {
    while (parent[i])
        i = parent[i];
    // When Parent[i] hit 0 means its the root, then i is the root
    return i;
}


// Unite the sets
// before: 1  3, after parent[3]: 1, Means  3(root) ------ 1(child)
void unite(int i, int j) {
    parent[j] = i;
}



int main() {
    int min, a, b, u, v;
    int edges = 1, mincost = 0;


    // Input 
    printf("Enter number of vertices: ");
    scanf("%d", &n);


    // Diagonal 0 and convert to INF: 999
    printf("Enter cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }


    // Calculate Min Spaning tree
    printf("\nEdges in Minimum Spanning Tree:\n");

    // Edge = vertex - 1: Edge < n (vertex)
    while (edges < n) {

        min = INF;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];

                    // a,b orignal copy: used for printing nd removing
                    // u,v representative(parent/root) after find()
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