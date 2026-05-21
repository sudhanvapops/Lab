#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 5000


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int low,int high){

    int pivot = a[high];
    int replace = low;

    for(int i=low; i<high; i++){
        if(a[i]<pivot){
            swap(&a[replace],&a[i]);
            replace++;
        }        
    }

    swap(&a[replace],&a[pivot]);
    return replace;
}


void quickSort(int a[],int low,int high){

    if (low >= high) return;

    int pivotPos = partition(a,low,high);
    quickSort(a,low,pivotPos-1);
    quickSort(a,pivotPos+1,high);

}