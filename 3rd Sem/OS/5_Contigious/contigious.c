#include <stdio.h>

#define MAX 10

int blockSize[MAX], processSize[MAX], allocation[MAX];
int nb, np;

void readBlocks() {
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    for (int i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
}


void readProcesses() {
    int i;
    printf("\nEnter number of processes: ");
    scanf("%d", &np);

    for (i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }
}


void allocateMemory(int type) {

    for (int i = 0; i < np; i++) {

        int blockIndx = -1; // blockIndx stores the selected block index

        for (int j = 0; j < nb; j++) {

            // Only blocks that can fit the process are considered.
            if (blockSize[j] < processSize[i]) continue;

            if (
                blockIndx == -1 ||
                (type == 2 && blockSize[j] < blockSize[blockIndx]) ||
                (type == 3 && blockSize[j] > blockSize[blockIndx])
            ) {
                blockIndx = j;
            }

            if (type == 1 && blockIndx != -1) break;
        }

        if (blockIndx != -1) {
            allocation[i] = blockIndx;
            blockSize[blockIndx] -= processSize[i];
        }
    }
}


void displayResult(char *title) {
    printf("\n--- %s Allocation ---\n", title);
    printf("\nProcess No.\tProcess Size\tBlock No.\n");

    for (int i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


int main() {
    int choice;

    readBlocks();
    readProcesses();

    printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
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
            printf("Invalid choice!");
    }

    return 0;
}
