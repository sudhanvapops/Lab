#include<stdio.h>
#define MAX 10

int processSize[MAX],blockSize[MAX];
int noBlocks, noProcess;
int allocation[MAX]; // for if allocated or not 


// Reads for How many blocks and thier size
void readBlocks(){
    printf("Enter number of Memory blocks: ");
    scanf("%d",&noBlocks);

    for(int i=0;i<noBlocks;i++){
        printf("Enter Block %d Size: ",i+1);
        scanf("%d",&blockSize[i]);
    }
}

// Reads for How many Process and thier required size
void readProcess(){
    printf("Enter Number of Process: ");
    scanf("%d",&noProcess);

    for(int i=0;i<noProcess;i++){
        printf("Enter Process %d Size: ",i+1);
        scanf("%d",&processSize[i]);
        allocation[i] = -1; // not alocated memory blocks for the process
    }

}

void displayResult(char *title){
    printf("\n--- %s Allocation ---\n", title);
    printf("\nProcess No.\tProcess Size\tBlock No.\n");

    for (int i = 0; i < noProcess; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


void allocateMemory(int type){

    for (int i=0; i<noProcess; i++){
        int blockIndex = -1;
        for (int j=0;j<noBlocks; j++){

            if (blockSize[j]>processSize[i]) {

            if (
                blockIndex == -1  ||
                (type == 2 && blockSize[j] < blockSize[blockIndex]) ||
                (type == 3 && blockSize[j] > blockSize[blockIndex]) 
            ){
                blockIndex = j;
            }

            if (type == 1 && blockIndex != -1) break;
            }
        }

        if (blockIndex!=-1){
            allocation[i] = blockIndex;
            blockSize[blockIndex] -= processSize[i];
        }
    }
}

int main(){

    int ch;

    readBlocks();
    readProcess();

    printf("1. First Fit\n2.Best Fit\n3. Worst Fit\n");
    printf("Enter Your Choice: ");
    scanf("%d",&ch);

    switch (ch) {
        case 1:
            allocateMemory(1);
            displayResult("First Fit");
            break;
        case 2:
            allocateMemory(2);
            displayResult("Best Fit");
            break;
        case 3:
            allocateMemory(3);
            displayResult("Worst Fit");
            break;
    default:
        printf("Invalid Choice\n");
    }

    return 0;
}