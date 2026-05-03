// 10. Design and implement C/C++ Program to sort a given set of n integer elements using Quick
// Sort method and compute its time complexity. Run the program for varied values of n> 5000 and
// record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
// from a file or can be generated using the random number generator.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10005

int a[MAX];

/* ---------- Quick Sort ---------- */
void quickSort(int low, int high) {
    int i, j, pivot, temp;

    if (low < high) {
        pivot = a[low];
        i = low;
        j = high + 1;

        while (1) {
            do { i++; } while (a[i] < pivot && i < high);
            do { j--; } while (a[j] > pivot);

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } else {
                break;
            }
        }

        a[low] = a[j];
        a[j] = pivot;

        quickSort(low, j - 1);
        quickSort(j + 1, high);
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
    quickSort(0, n - 1);
    clock_t end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
}

/* ---------- Main ---------- */
int main() {
    int n;

    printf("Enter Max array size: ");
    scanf("%d", &n);

    generateArray(n);
    printArray(n, "Input Array:");
    double time_taken = measureTime(n);   // DRY

    printArray(n, "Sorted Array:");
    printf("\nTime taken for n=%d is: %.6f ms\n", n, time_taken);

    return 0;
}