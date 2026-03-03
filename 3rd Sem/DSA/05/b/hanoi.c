// ## PROGRAM - 05 

// B) Solving Tower of Hanoi problem with n disks.

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

// ### Output
// Enter the number of discs: 3

// Steps to solve Tower of Hanoi:
// Move disc 1 from A to C
// Move disc 2 from A to B
// Move disc 1 from C to B
// Move disc 3 from A to C
// Move disc 1 from B to A
// Move disc 2 from B to C
// Move disc 1 from A to C

// Total number of moves: 7