// 8. Design and implement C/C++ Program to find a subset of a given set S = {sl , s2,.....,sn} of n clpositive integers whose sum is equal to a given positive integer d.

#include <stdio.h>

#define MAX 20

int numbers[MAX];
int chosen[MAX];
int targetSum;


/* Print the subset */
void printSubset(int n) {
    printf("{ ");

    for(int i = 0; i < n; i++){
        if(chosen[i] == 1)
            printf("%d ", numbers[i]);
    }

    printf("}\n");
}

/* Backtracking */
void findSubsets(int currentIndex, int currentSum, int n) {
    /* Solution found */
    if(currentSum == targetSum){
        printSubset(n);
        return;
    }

    /* Invalid branch */
    if(currentIndex >= n || currentSum > targetSum){
        return;
    }

    /* Include current element */
    chosen[currentIndex] = 1;
    findSubsets(
        currentIndex + 1,
        currentSum + numbers[currentIndex],
        n
    );

    /* Exclude current element */
    chosen[currentIndex] = 0;
    findSubsets(
        currentIndex + 1,
        currentSum,
        n
    );
}


int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &targetSum);

    findSubsets(0, 0, n);

    return 0;
}


// Enter the n value: 5
// Enter the set in increasing order: 1 2 5 6 8
// Enter the max subset value: 9
// 1 2 6 
// 1 8 
// 
// Enter the n value: 5
// Enter the set in increasing order: 1 3 4 5 6
// Enter the max subset value: 20
// No subset possible
// 
// Enter the n value: 9
// Enter the set in increasing order: 1 2 3 4 5 6 7 8 9
// Enter the max subset value: 9
// 1 2 6 
// 1 3 5 
// 1 8 
// 2 3 4 
// 2 7 
// 3 6 
// 4 5 
// 9 