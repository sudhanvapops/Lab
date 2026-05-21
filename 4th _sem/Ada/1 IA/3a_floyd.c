#include<stdio.h>
#define MAX 20


void floyd(int n,int a[MAX][MAX]){
    for(int k=0; k<n;k++)
        for(int i=0; i<n;i++)
            for(int j=0; j<n;j++)
                if(a[i][k] + a[k][j] < a[i][j] )
                    a[i][j] = a[i][k] + a[k][j];
}