// 6. Design and implement C/C++ Program to solve 0/1 Knapsack problem using Dynamic Programming method

#include <stdio.h>

#define MAX 10

int w[MAX], p[MAX], v[MAX][MAX], x[MAX];
int n, cap;

// Function to read input
void readInput() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("\nEnter in (Profit Weights)\n");
    for (int i = 1; i <= n; i++) {
        printf("Item %d: ", i);
        scanf("%d %d", &p[i], &w[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &cap);
}

// Build DP table
void buildTable() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] <= j)
                v[i][j] = (p[i] + v[i-1][j-w[i]] > v[i-1][j])
                            ? p[i] + v[i-1][j-w[i]]
                            : v[i-1][j];
            else
                v[i][j] = v[i-1][j];
        }
    }
}

// Traceback to find selected items
void findItems() {
    int i = n, j = cap;

    while (i > 0 && j > 0) {
        if (v[i][j] != v[i-1][j]) {
            x[i] = 1;
            j -= w[i];
        }
        i--;
    }
}

// Print result
void printResult() {
    int count = 0;
    printf("\nItems included:\n");
    printf("Sl.No\tWeight\tProfit\n");

    for (int i = 1; i <= n; i++) {
        if (x[i])
            printf("%d\t%d\t%d\n", ++count, w[i], p[i]);
    }

    printf("Total Profit = %d\n", v[n][cap]);
}

// Main function
int main() {
    readInput();
    buildTable();
    findItems();
    printResult();
    return 0;
}



// Enter number of items: 4

// Enter in (Profit Weights)
// Item 1: 12 2
// Item 2: 10 1
// Item 3: 20 3
// Item 4: 15 2
// Enter capacity: 5

// Items included:
// Sl.No   Weight  Profit
// 1       2       12
// 2       1       10
// 3       2       15
// Total Profit = 37