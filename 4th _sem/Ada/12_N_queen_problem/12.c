#include <stdio.h>

int board[20][20];
int n, count = 0;

/* Check whether a queen can be placed */
int isSafe(int row, int col) {
    int i, j;

    // Check left side of same row
    for(i = 0; i < col; i++)
        if(board[row][i])
            return 0;

    // Check upper-left diagonal
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return 0;

    // Check lower-left diagonal
    for(i = row, j = col; i < n && j >= 0; i++, j--)
        if(board[i][j])
            return 0;

    return 1;
}

/* Print solution */
void printBoard() {
    int i, j;

    count++;
    printf("\nSolution %d:\n", count);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(board[i][j])
                printf("Q ");
            else
                printf("* ");
        }
        printf("\n");
    }
}

/* Backtracking function */
void solve(int col) {
    if(col == n) {
        printBoard();
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isSafe(row, col)) {
            board[row][col] = 1;   // Place queen

            solve(col + 1);        // Recur

            board[row][col] = 0;   // Backtrack
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(0);

    printf("\nTotal Solutions = %d\n", count);

    return 0;
}