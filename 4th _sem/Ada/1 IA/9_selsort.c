// Selsort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 50

void selSort(int n, int a[]){

    int pos=0,small=0,temp=0;

    for (int i = 0; i < n-1; i++) {
        small = a[i];
        pos=i;
        for(int j = i+1; j < n; j++){
            if (a[j] < small ){
                small = a[j];
                pos = j;
            }
        }

        // swap
        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;

    }

}

void generateArray(int a[],int n){
    for(int i=0; i<n; i++){
        a[i] = 500 + rand()%999;
    }
}


void printArray(int a[], int n, const char *msg){
    printf("\n%s\n",msg);
    for( int i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
}


double mesureTime(int a[],int n){
    clock_t start = clock();
    selSort(n,a);
    clock_t end = clock();
    return ((double)(end-start)) / CLOCKS_PER_SEC * 1000;
}


int main(){

    int a[MAX],n;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    srand(time(NULL));

    generateArray(a,n);

    printArray(a,n,"Input Array:");

    double time_taken = mesureTime(a,n);

    printArray(a,n,"Output Array:");

    printf("\ntime taken for execution: %f",&time_taken);
    
    return 0;
}