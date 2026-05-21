#include <stdio.h>

#define MAX 20
#define INF 999
// INF means edge removed


// Stores one edge.
struct Edge {
    int src, dest, weight;
};


// parent: tracks connected component 
int parent[MAX];

// Find component root
// Find which group(vertex set) a node belongs to, find in the set
// Eg: parent[3] = 1; 3 belong to 1
int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}


// Merge components
// Unite the sets
// before: 1  3, after parent[3]: 1, Means  3(root) ------ 1(child)
// Merge two sets parents casuse if no root b might not be the root
void unite(int a, int b) {
    parent[find(b)] = find(a);
    // parent[find(a)] = find(b); // Same since not merging by ranks
}



// Sort edges by weight
// Uses Bubble Sort.
void sortEdges(struct Edge edge[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edge[j].weight > edge[j + 1].weight) {
                struct Edge temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
}

int main() {

    // n: number of vertices
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    
    // Converting Adj Matrix to Edge List
    printf("Enter adjacency matrix:\n");

    struct Edge edge[MAX * MAX];

    // Pointer to Egde List
    int m = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            int value;
            scanf("%d", &value);

            // Since Undirected Graph
            // Edge (1,2) and (2,1) are the same edge.
            // Take only upper triangle
            if (j > i && value != 0 && value != INF) {
                edge[m].src = i;
                edge[m].dest = j;
                edge[m].weight = value;
                m++;
            }
        }
    }


    // Initialize parent
    // Initaily every one are seprate set
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // Sort the edges
    sortEdges(edge, m);


    int mincost = 0;

    // How many edges have been selected into the MST so far.
    int count = 0;

    printf("\nEdges in MST:\n");

    // Main Kruskal Logic 
    // Loop through sorted edges.
    for (int i = 0; i < m && count < n - 1; i++) {

        // u and v are parent node of the selected edges
        int u = find(edge[i].src);
        int v = find(edge[i].dest);

        // If both parents diffrent unite them
        if (u != v) {

            unite(u, v);

            printf("(%d,%d) Cost=%d\n",
                   edge[i].src,
                   edge[i].dest,
                   edge[i].weight);

            mincost += edge[i].weight;

            count++;
        }
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}