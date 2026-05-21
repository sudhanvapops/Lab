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


double messureTime(int a[], int n){
    
    clock_t start = clock();
    selsort(a, n);
    clock_t end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}


void main() {

    int a[10], n;

    printf("\nEnter the n value:");
    scanf("%d", &n);

    srand(time(NULL)); 
    
    generateArray(a, n);  

    printArray(a, n, "Input Array:");
    double time_taken = messureTime(a,n);
    printArray(a, n, "Sorted Array:");

    printf("\nTime taken is: %f ms\n", time_taken);


}