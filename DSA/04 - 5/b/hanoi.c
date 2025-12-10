#include <stdio.h>
#include <math.h>

// Recursive function for Tower of Hanoi
// (n,start,temp,end)
void towerOfHanoi(int n, char from, char aux, char to) {
    if (n == 0) return;

    // (n,start,temp,end)
    towerOfHanoi(n - 1, from, to, aux);
    printf("Move disc %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, from, to);
}

// Utility to calculate total moves
int totalMoves(int n) {
    return (int)pow(2, n) - 1;
}

int main() {
    int discs;

    printf("Enter the number of discs: ");
    scanf("%d", &discs);

    printf("\nSteps to solve Tower of Hanoi:\n");
    towerOfHanoi(discs, 'A', 'B', 'C');

    printf("\nTotal number of moves: %d\n", totalMoves(discs));

    return 0;
}
