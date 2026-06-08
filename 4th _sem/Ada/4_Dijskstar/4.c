// 4. Design and implement C/C++ Program to find shortest paths from a given vertex in a weighted connected graph to other vertices using Dijkstra's algorithm.

#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITY 999

int numVertices;
int cost[MAX_VERTICES][MAX_VERTICES]; // cost adjacency matrix

void readGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter cost adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            scanf("%d", &cost[i][j]);
}

void dijkstra(int source, int shortestDist[]) {
    int visited[MAX_VERTICES] = {0}; // 0 = not yet finalized

    // Step 1: Initialize distances from source row of matrix
    for (int i = 0; i < numVertices; i++)
        shortestDist[i] = cost[source][i];

    visited[source] = 1; // source is already finalized

    // Step 2: Repeat (numVertices - 1) times
    for (int count = 1; count < numVertices; count++) {

        // Step 2a: Pick the unvisited vertex with the smallest current distance
        int minDist = INFINITY, u = -1;
        for (int i = 0; i < numVertices; i++)
            if (!visited[i] && shortestDist[i] < minDist) {
                minDist = shortestDist[i];
                u = i;
            }

        visited[u] = 1; // finalize vertex u

        // Step 2b: Relax (update) distances through u
        for (int v = 0; v < numVertices; v++)
            if (!visited[v] && shortestDist[u] + cost[u][v] < shortestDist[v])
                shortestDist[v] = shortestDist[u] + cost[u][v];
    }
}

void printResult(int source, int shortestDist[]) {
    for (int i = 0; i < numVertices; i++)
        if (i != source)
            printf("Shortest distance %d -> %d = %d\n",
                   source + 1, i + 1, shortestDist[i]);
}

int main() {
    int shortestDist[MAX_VERTICES], source;

    readGraph();

    printf("Enter source vertex: ");
    scanf("%d", &source);
    source--; // convert to 0-based index

    dijkstra(source, shortestDist);
    printResult(source, shortestDist);

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
