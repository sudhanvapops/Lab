// ## PROGRAM - 11 
// 11) Develop a Program in C for the following operations on Graph(G) of Cities   
// a. Create a Graph of N cities using Adjacency Matrix. 
// b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS methods

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int n;
int adj[MAX][MAX];
int visited[MAX];


void reset(int arr[]) {
    for (int i = 1; i <= n; i++)
        arr[i] = 0;
}


void readGraph() {
    printf("Enter graph data in matrix form:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
}


void dfs(int v, int *count) {
    visited[v] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            printf("%d->%d ", v, i);
            (*count)++;
            dfs(i, count);
        }
    }
}


void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear] = start;

    while (front <= rear) {
        int v = queue[front++];
        printf("%d ",v);
        for (int i = 1; i <= n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}


void menu() {
    printf("\n1. BFS\n2. DFS\n3. Exit\n");
}


int main() {
    int choice, start;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    readGraph();
    menu();
    scanf("%d", &choice);

    switch (choice) {

    case 1:
        printf("Enter the starting vertex:");
        scanf("%d", &start);

        if (start < 1 || start > n) {
            printf("BFS is not possible\n");
            break;
        }

        reset(visited);
        bfs(start);

        break;

    case 2: {
        int edgeCount = 0;
        reset(visited);
        dfs(1, &edgeCount);

        if (edgeCount == n - 1)
            printf("\nGraph is connected");
        else
            printf("\nGraph is not connected");
        break;
    }

    case 3:
        exit(0);

    default:
        printf("Invalid choice\n");
    }

    return 0;
}


// ### Output 1
// Enter the number of vertices:5
// Enter graph data in matrix form:
// 0 1 0 1 0 
// 1 0 1 0 1 
// 0 1 0 1 0 
// 1 0 1 0 0 
// 0 1 0 0 0 

// 1. BFS
// 2. DFS
// 3. Exit
// 2
// 1->2 2->3 3->4 2->5 
// Graph is connected

// ### Output 2

// Enter the number of vertices:5
// Enter graph data in matrix form:
//  0 1 0 1 0 1 0 1 0 0 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0

// 1. BFS
// 2. DFS
// 3. Exit
// 2
// 1->2 2->3 3->4 
// Graph is not connected

// ### Output 3

// Enter the number of vertices:5
// Enter graph data in matrix form:
// 0 1 1 0 0
// 0 0 0 1 0 
// 0 0 0 0 0 
// 0 0 1 0 0 
// 0 0 1 0 0

// 1. BFS
// 2. DFS
// 3. Exit
// 1
// Enter the starting vertex:1
// The nodes which are reachable from 1: 1 2 3 4 

// ### Output 4

// Enter the number of vertices:5
// Enter graph data in matrix form:
// 0 1 1 0 0 0 0 0 1 
// 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 

// 1. BFS
// 2. DFS
// 3. Exit
// 1
// Enter the starting vertex:0
// BFS is not possible