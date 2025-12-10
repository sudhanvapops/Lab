// Sample Input and Output

// Enter number of pages: 6
// Enter page numbers: 1 2 3 1 4 5
// Enter number of frames: 3
// 1. FIFO
// 2. LRU
// Enter your choice: 1
// FIFO Page Replacement

// Page 1 -> 1 - -
// Page 2 -> 1 2 -
// Page 3 -> 1 2 3
// Page 1 -> 1 2 3
// Page 4 -> 4 2 3
// Page 5 -> 4 5 3

// Total Page Faults (FIFO): 5

// Enter your choice: 2
// LRU Page Replacement

// Page 1 -> 1 - -
// Page 2 -> 1 2 -
// Page 3 -> 1 2 3
// Page 1 -> 1 2 3
// Page 4 -> 4 2 3
// Page 5 -> 4 5 3

// Total Page Faults (LRU): 5


#include <stdio.h>

void printFrames(int frame[], int f, int page) {
    int i;
    printf("Page %d -> ", page);
    for (i = 0; i < f; i++)
        printf("%s ", frame[i] == -1 ? "-" : (char[12]){0});
    printf("\b\b"); // fix formatting
    for (i = 0; i < f; i++)
        if (frame[i] != -1) printf("%d ", frame[i]);
        else printf("- ");
    printf("\n");
}

int main() {
    int pages[30], frame[10], temp[10];
    int n, f, i, j, pageFaults = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page numbers: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("\n1. FIFO\n2. LRU\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    for (i = 0; i < f; i++) frame[i] = -1;

    if (choice == 1) {
        printf("\nFIFO Page Replacement\n");
        int index = 0;

        for (i = 0; i < n; i++) {
            flag = 0;
            for (j = 0; j < f; j++)
                if (frame[j] == pages[i]) flag = 1;

            if (!flag) {
                frame[index] = pages[i];
                index = (index + 1) % f;
                pageFaults++;
            }
            printFrames(frame, f, pages[i]);
        }
        printf("\nTotal Page Faults (FIFO): %d\n", pageFaults);
    }

    else if (choice == 2) {
        printf("\nLRU Page Replacement\n");
        int count = 0;

        for (i = 0; i < n; i++) {
            flag = 0;
            for (j = 0; j < f; j++)
                if (frame[j] == pages[i]) {
                    temp[j] = i;
                    flag = 1;
                }

            if (!flag) {
                if (count < f) {
                    frame[count] = pages[i];
                    temp[count++] = i;
                } else {
                    int least = 0;
                    for (j = 1; j < f; j++)
                        if (temp[j] < temp[least]) least = j;

                    frame[least] = pages[i];
                    temp[least] = i;
                }
                pageFaults++;
            }
            printFrames(frame, f, pages[i]);
        }
        printf("\nTotal Page Faults (LRU): %d\n", pageFaults);
    }

    else printf("Invalid choice!\n");

    return 0;
}


