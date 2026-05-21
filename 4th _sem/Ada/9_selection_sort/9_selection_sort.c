// 9. Design and implement C/C++ Program to sort a given set of n integer elements using Selection
// Sort method and compute its time complexity. Run the program for varied values of n> 5000 and
// record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
// from a file or can be generated using the random number generator.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void selsort(int a[], int n) {
    int small, pos;

    for(int i = 0; i < n - 1; i++) {
        small = a[i];
        pos = i;

        for(int j = i + 1; j < n; j++) {
            if(a[j] < small) {
                small = a[j];
                pos = j;
            }
        }

        int temp = a[i];
        a[i] = small;
        a[pos] = temp;
    }
}


void printArray(int a[], int n, const char *msg) {
    printf("%s\n", msg);
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}


void generateArray(int a[], int n) {
    for(int i = 0; i < n; i++)
        a[i] = 5000 + rand() % 999;
}


void main() {

    int a[10], n;
    clock_t start, end;
    

    printf("\nEnter the n value:");
    scanf("%d", &n);

    srand(time(NULL)); 
    
    generateArray(a, n);  

    printArray(a, n, "Input Array:");

    start = clock();
    selsort(a, n);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printArray(a, n, "Sorted Array:");

    printf("\nTime taken is: %f ms\n", time_taken);
}