#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITY 999

int numVertices;
int cost[MAX_VERTICES][MAX_VERTICES];

void dijkstra(int source,int shortestDistance[]){

    int visited[MAX_VERTICES] = {0};
    visited[source] = 1;

    for(int i=0;i<numVertices;i++){
        shortestDistance[i] = cost[source][i];
    }

    for(int i=1; i<numVertices;i++){

        int minDist =INFINITY, u = -1;
        for(int j=0;j<numVertices;j++){
            if(!visited[j] && shortestDistance[j] < minDist){
                minDist = shortestDistance[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < numVertices; v++){
            if(!visited[v] && shortestDistance[u] + cost[u][v] < shortestDistance[v]){
                shortestDistance[v] = shortestDistance[u] + cost[u][v];
            }
        }

    }

}