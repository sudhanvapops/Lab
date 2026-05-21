// Prims

#include<stdio.h>

#define MAX 20
#define INF 999


typedef struct Edge{
    int src;
    int dest;
    int weight;
} Edge;


void input(int graph[MAX][MAX], int n) {
    printf("\nEnter Adj Matrix:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&graph[i][j]);
            // Ignore self-loops / absent edges.
            if(graph[i][j]==0)
                graph[i][j]=INF;
        }
    }
}


Edge findMinEdge( int graph[MAX][MAX], int visited[], int n ) {

    Edge minEdge;
    minEdge.weight = INF;

    for(int i=1;i<=n;i++){
        if(visited[i]){
            for(int j=1;j<=n;j++){
                if( !visited[j] && graph[i][j] < minEdge.weight ){
                    minEdge.src = i;
                    minEdge.dest = j;
                    minEdge.weight = graph[i][j];
                }
            }
        }
    }

    return minEdge;
}


void prim( int graph[MAX][MAX], int n ) {

    int visited[MAX]={0};
    visited[1]=1;

    int edgeCount=0;
    int minCost=0;

    printf("\nEdges in MST:\n");

    while(edgeCount < n-1){
        Edge edge = findMinEdge(graph,visited,n);
        visited[edge.dest] = 1;
        printf( "(%d,%d): Cost=%d\n", edge.src, edge.dest, edge.weight);
        minCost += edge.weight;
        edgeCount++;
    }
    printf("\nMinimum Cost=%d\n",minCost);
}


int main(){

    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d",&n);
    input(graph,n);
    prim(graph,n);

    return 0;
}

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