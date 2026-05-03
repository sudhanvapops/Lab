// 11. Design and implement C/C++ Program to sort a given set of n integer elements using Merge
// Sort method and compute its time complexity. Run the program for varied values of n> 5000,
// and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be
// read from a file or can be generated using the random number generator.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10005

int a[MAX];

/* ---------- Merge Function ---------- */
void merge(int low, int mid, int high) {
    int b[MAX];
    int i = low, h = low, j = mid + 1;

    while (h <= mid && j <= high) {
        if (a[h] < a[j])
            b[i++] = a[h++];
        else
            b[i++] = a[j++];
    }

    while (h <= mid)
        b[i++] = a[h++];

    while (j <= high)
        b[i++] = a[j++];

    for (int k = low; k <= high; k++)
        a[k] = b[k];
}

/* ---------- Merge Sort ---------- */
void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

/* ---------- Utility (DRY) ---------- */
void generateArray(int n) {
    for (int i = 0; i < n; i++)
        a[i] = 5000 + rand() % 999;
}

void printArray(int n, const char *msg) {
    printf("%s\n", msg);
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

double measureTime(int n) {
    clock_t start = clock();
    mergeSort(0, n - 1);
    clock_t end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}

/* ---------- Main ---------- */
int main() {
    int n;

    printf("Enter Max array size: ");
    scanf("%d", &n);

    generateArray(n);                // DRY
    printArray(n, "Input Array:");

    double time_taken = measureTime(n);   // DRY

    printArray(n, "Sorted Array (Merge Sort):");

    printf("\nTime taken for n=%d is: %f ms\n", n, time_taken);

    return 0;
}