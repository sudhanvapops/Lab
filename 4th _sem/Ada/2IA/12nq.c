//12 NQ

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int board[20][20];
int n, count = 0;

int isSafe(int row,int col){

    for(int i = 0; i<col; i++){
        if(board[row][i])
            return 0;
    }


    for (int i = row, j = col ; i>=0 && j>=0; i--,j--){
        if(board[i][j])
            return 0;
    }

    for (int i = row, j = col ; i<n && j>=0; i++,j--){
        if(board[i][j])
            return 0;
    }
    
    return 1;
}

void printBoard() {
    count++;
    printf("\nSolution %d:\n", count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(board[i][j] ? "Q " : "* ");
        printf("\n");
    }
}

void solve(int col){

    if (col == n){
        printBord();
        return ;
    }

    for (int row = 0; row < n; row ++){
        if(isSafe(row,col)){
            board[row][col] = 1;
            solve(col+1);
            board[row][col] = 0;
        }
    }
}