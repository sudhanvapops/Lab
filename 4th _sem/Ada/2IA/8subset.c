#include<stdio.h>

#define MAX 20

int numbers[MAX];
int chosen[MAX];
int targetSum;

void findSubset(int currentSum, int currentIndex, int n){

    if(currentSum == targetSum){
        printSubset();
        return;
    }

    if (currentIndex > n || currentSum > targetSum)
        return;

    chosen[currentIndex] = 1;
    findSubset(currentSum + numbers[currentIndex],currentIndex+1,n);
    chosen[currentIndex] = 0;
    findSubset(currentSum,currentIndex+1,n);

}