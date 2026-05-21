// 11. Design and implement C/C++ Program to sort a given set of n integer elements using Merge
// Sort method and compute its time complexity. Run the program for varied values of n> 5000,
// and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be
// read from a file or can be generated using the random number generator.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10005


void merge(int a[], int low, int mid, int high) {

    int size = high - low + 1; // get length
    int temp[size]; // write back array


    int left = low;
    int right = mid + 1;
    int k = 0; // pointer for third array


    while (left <= mid && right <= high) {

        if (a[left] <= a[right])
            temp[k++] = a[left++];
        else
            temp[k++] = a[right++];
    }


    // remaing elements 
    while (left <= mid)
        temp[k++] = a[left++];

    while (right <= high)
        temp[k++] = a[right++];

    // Right back to original array
    for (int i = 0; i < size; i++)
        a[low + i] = temp[i];

}


void mergeSort(int a[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(a,low, mid);
    mergeSort(a,mid + 1, high);
    merge(a, low, mid, high);
}


void generateArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = 5000 + rand() % 999;
}


void printArray(int a[], int n, const char *msg) {
    printf("%s\n", msg);
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}


double measureTime(int a[], int n) {
    clock_t start = clock();
    mergeSort(a,0, n - 1);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}


int main() {
    int n;
    int a[MAX];

    printf("Enter Max array size: ");
    scanf("%d", &n);

    generateArray(a,n);                
    printArray(a,n, "Input Array:");

    double time_taken = measureTime(a,n);

    printArray(a,n, "Sorted Array (Merge Sort):");

    printf("\nTime taken for n=%d is: %f ms\n", n, time_taken);

    return 0;
}