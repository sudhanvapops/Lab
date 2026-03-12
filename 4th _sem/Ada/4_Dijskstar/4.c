// 4. Design and implement C/C++ Program to find shortest paths from a given vertex in a weighted connected graph to other vertices using Dijkstra's algorithm.

#include <stdio.h>
#define MAX 10
#define INF 999

int n, graph[MAX][MAX];

void readGraph() {
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter cost adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
}

void dijkstra(int src, int dist[]) {
    int visited[MAX] = {0};

    for(int i=0;i<n;i++)
        dist[i] = graph[src][i];

    visited[src] = 1;

    for(int count=1; count<n; count++) {
        int min = INF, u = -1;

        for(int i=0;i<n;i++)
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for(int v=0; v<n; v++)
            if(!visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
}

void printDistances(int src, int dist[]) {
    for(int i=0;i<n;i++)
        if(i != src)
            printf("Shortest distance %d -> %d = %d\n", src+1, i+1, dist[i]);
}

int main() {
    int dist[MAX], src;

    readGraph();

    printf("Enter source vertex: ");
    scanf("%d",&src);
    src--;   // convert to 0-index

    dijkstra(src, dist);
    printDistances(src, dist);

    return 0;
}


// Enter the number of vertices:
// 5
// Enter the cost adjacency matrix:
// 0	3	999	7	999
// 3	0	4	2	999
// 999	4	0	5	6
// 7	2	5	0	4
// 999	999	6	4	0

// Enter the source vertex:
// 1

// Shortest distance from the path 1 --> 2 is 3
// Shortest distance from the path 1 --> 3 is 7
// Shortest distance from the path 1 --> 4 is 5
// Shortest distance from the path 1 --> 5 is 9
