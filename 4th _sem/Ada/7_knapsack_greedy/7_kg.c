// 7. Design and implement C/C++ Program to solve discrete Knapsack and continuous Knapsack
// problems using greedy approximation method.

#include <stdio.h>

#define MAX 20

typedef struct {
    float w, p, r;
} Item;

int n;
float M;

/* ---------- Utility Functions ---------- */

void inputArray(float arr[], const char *msg) {
    printf("%s", msg);
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
}

void computeRatio(Item a[]) {
    for (int i = 0; i < n; i++)
        a[i].r = a[i].p / a[i].w;
}

void sortByRatio(Item a[]) {
    Item temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j].r < a[j + 1].r) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

/* ---------- Core Logic ---------- */

float knapsack(Item a[], float x[]) {
    float profit = 0, rc = M;

    for (int i = 0; i < n; i++) {
        if (a[i].w <= rc) {
            x[i] = 1;
            profit += a[i].p;
            rc -= a[i].w;
        } else {
            x[i] = rc / a[i].w;
            profit += x[i] * a[i].p;
            break;
        }
    }
    return profit;
}

/* ---------- Display ---------- */

void display(Item a[], float x[], float profit) {
    printf("\nWeight\tProfit\tFraction\n");
    for (int i = 0; i < n; i++)
        printf("%.2f\t%.2f\t%.2f\n", a[i].w, a[i].p, x[i]);

    printf("\nTotal Profit = %.2f\n", profit);
}

/* ---------- Main ---------- */

int main() {
    printf("***** FRACTIONAL KNAPSACK *****\n");

    printf("Enter number of objects: ");
    scanf("%d", &n);

    Item obj[MAX];
    float x[MAX] = {0};

    printf("Enter capacity: ");
    scanf("%f", &M);

    inputArray(&obj[0].w, "Enter Weights: ");
    inputArray(&obj[0].p, "Enter Profits: ");

    computeRatio(obj);
    sortByRatio(obj);

    float profit = knapsack(obj, x);
    display(obj, x, profit);

    return 0;
}