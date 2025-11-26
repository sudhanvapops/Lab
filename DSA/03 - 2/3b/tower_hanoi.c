#include <stdio.h>
#include <math.h>   // for pow()

void tower(int n, char src, char temp, char dest) {
    if (n == 0)
        return;
    
    tower(n - 1, src, dest, temp);
    printf("\nMove disc %d from %c to %c", n, src, dest);
    tower(n - 1, temp, src, dest);
}

int main() {
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);

    printf("\nSteps:\n");
    tower(n, 'A', 'B', 'C');

    printf("\n\nTotal number of moves: %d\n", (int)pow(2, n) - 1);
    return 0;
}
