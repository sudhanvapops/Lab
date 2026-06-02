// Krushkal

#include<stdio.h>

#define MAX 20
#define INF 999

typedef struct Edge{
    int src;
    int dest;
    int weight;
} Edge;


void input(int n, Edge edge[], int *m){

    printf("\nEnter Adj Matrix:\n");

    int weight=0;

    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            scanf("%d",&weight);
            if (j > i && weight !=0 && weight != INF){
                edge[*m].src = i;      
                edge[*m].dest = j;      
                edge[*m].weight = weight;   
                (*m)++;
            }
        }
    }
    printf("\n");
}


int parent[MAX];


void initalizeParent(int n){
    for (int i = 0; i <= n; i++){
        parent[i] = i;
    }
}


void sortByWeight(Edge edge[],int *m){

    for (int i = 0; i < (*m) - 1; i++){
        for (int j = 0; j < (*m) - i - 1; j++){
            if ( edge[j].weight > edge[j+1].weight){
                Edge temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }
        
}



int find(int x){
    while(parent[x] != x)
        x = parent[x];
    return x;
}


void unite(int a, int b){
    parent[find(b)]=find(a);
}



int main(){
    
    int n=0,m=0;
    Edge edges[MAX*MAX];

    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    
    input(n,edges,&m);
    initalizeParent(n);
    sortByWeight(edges,&m);

    // Krushkal
    int u,v;
    int count=0, minCost=0;

    for(int i=0; i<m && count<n-1; i++){

        u = find(edges[i].src);
        v = find(edges[i].dest);

        if (u != v){
            unite(u,v);

            printf("Edges (%d,%d): Cost: %d\n",
                edges[i].src,
                edges[i].dest,
                edges[i].weight
            );

            minCost+=edges[i].weight;
            count+=1;
        }

    }

    printf("\nMinimum Cost: %d\n", minCost);
    
    return 0;
}


// Enter the number of vertices: 6
// Enter Adj Matrix:
// 0 60 10 999 999 999
// 60 0 999 20 40 70
// 10 999 0 999 999 50
// 999 20 999 0 999 80
// 999 40 999 999 0 30
// 999 70 50 80 30 0
// 
// Edges (1,3): Cost: 10
// Edges (2,4): Cost: 20
// Edges (5,6): Cost: 30
// Edges (2,5): Cost: 40
// Edges (3,6): Cost: 50
// 
// Minimum Cost: 150