#include<stdio.h>

#define MAX 10

int a[MAX][MAX], indegree[MAX] = {0}, n;



void calculateIndegree(int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            indegree[i] += a[j][i];
        }
    }
    
}


void toplogicalSort(){

    int stack[MAX] = {0}, top = 0, k= 0 ,result[MAX] = {0}; 

    // Calc indegree
    calculateIndegree(n);

    // push all with 0
    for (int i = 0; i< n; i++){
        if (indegree[i] == 0){
            stack[top++] = i;
        }
    }

    while(top > 0){

        int u = stack[--top];

        result[k++] = u;

        for(int v = 0; v < n; v++){
            if(a[u][v]){
                if(--indegree[v]==0)
                stack[top++] = v;
            }
        }

    }

    printf("Topological Order:\n");
    for (int i = 0; i < k; i++)
        printf("%d ", result[i]);

}