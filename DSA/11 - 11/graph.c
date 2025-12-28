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
    int queue[MAX], front = 0, rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int v = queue[front++];
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

        printf("The nodes which are reachable from %d: ", start);
        for (int i = 1; i <= n; i++)
            if (visited[i])
                printf("%d ", i);
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
