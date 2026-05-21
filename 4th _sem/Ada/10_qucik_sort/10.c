// 10. Design and implement C/C++ Program to sort a given set of n integer elements using Quick
// Sort method and compute its time complexity. Run the program for varied values of n> 5000 and
// record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
// from a file or can be generated using the random number generator.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10005


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high){

    int pivot = arr[high];   // Pivot element
    int replace = low;       // boundary of smaller elements

    for(int i = low; i < high; i++){

        if(arr[i] <= pivot){
            swap(&arr[replace], &arr[i]);
            replace++;
        }
    }

    // put pivot into correct position
    swap(&arr[replace], &arr[high]);

    return replace;
}


void quickSort(int arr[], int low, int high){

    if(low < high){

        int pivotPos = partition(arr, low, high);

        quickSort(arr, low, pivotPos - 1);

        quickSort(arr, pivotPos + 1, high);
    }
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
    quickSort(a,0, n - 1);
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

    printArray(a,n, "Sorted Array:");
    printf("\nTime taken for n=%d is: %.6f ms\n", n, time_taken);

    return 0;
}