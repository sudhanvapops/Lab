#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10005


void merge(int a[],int low, int mid, int high){

    int length = high - low + 1;
    int temp[length];

    int left = low;
    int right = mid + 1;
    int k = 0;

    while(left<=mid && right<=high){

        if (a[left] <= a[right]){
            temp[k++] = a[left++];
        }else{
            temp[k++] = a[right++];
        }

    }

    while (left <= mid)
        temp[k++] = a[left++];

    while (right <= high)
        temp[k++] = a[right++];

    for(int i = 0; i<length; i++)
        a[low+i] = temp[i];

}


void mergeSort(int a[], int low, int high){
    if(low>=high) return ;
    int mid = (low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
}