#include <stdio.h>

#define MAX 20

typedef struct {
    float p, w, r;
} Item;

int n;
float M;

/* ---------- Input ---------- */

void readInput(Item obj[]) {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity: ");
    scanf("%f", &M);

    printf("\nEnter each item (Profit Weight)\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%f %f", &obj[i].p, &obj[i].w);
    }
}


/* ---------- Ratio ---------- */

// Ratio = Profit / weight
void computeRatio(Item a[]) {
    for (int i = 0; i < n; i++)
        a[i].r = a[i].p / a[i].w;
}

/* ---------- Sort ---------- */

void sortByRatio(Item a[]) {
    Item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].r < a[j + 1].r) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/* ---------- Fractional Knapsack ---------- */

float knapsack(Item a[], float x[]) {
    float profit = 0;
    float rc = M;

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

/* ---------- Output ---------- */

void display(Item a[], float x[], float profit) {

    printf("\nProfit\tWeight\tRatio\tFraction\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f\t%.2f\t%.2f\t%.2f\n",
               a[i].p,
               a[i].w,
               a[i].r,
               x[i]);
    }

    printf("\nTotal Profit = %.2f\n", profit);
}

/* ---------- Main ---------- */

int main() {

    Item obj[MAX];
    float x[MAX] = {0};

    readInput(obj);

    computeRatio(obj);
    sortByRatio(obj);

    float profit = knapsack(obj, x);

    display(obj, x, profit);

    return 0;
}


// Enter number of items: 3
// Enter capacity: 40
// 
// Enter each item (Profit Weight)
// Item 1: 30 20
// Item 2: 40 25
// Item 3: 35 10
// 
// Profit  Weight  Ratio   Fraction
// 35.00   10.00   3.50    1.00
// 40.00   25.00   1.60    1.00
// 30.00   20.00   1.50    0.25
// 
// Total Profit = 82.50