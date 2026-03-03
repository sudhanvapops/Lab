#include <stdio.h>
#include <stdlib.h>

int noPage, noFrame;
int pages[30];

void printFrames(int frame[], int noFrames, int page) {
    printf("Page %d -> ", page);
    for (int i = 0; i < noFrames; i++)
        frame[i] == -1 ? printf("- ") : printf("%d ", frame[i]);
    printf("\n");
}

int isHit(int noFrames, int frame[], int page) {
    for (int i = 0; i < noFrames; i++) {
        if (frame[i] == page)
            return 1;
    }
    return 0;
}

void FIFO() {

    int frames[noFrame], index = 0, pageFault = 0;

    for (int i = 0; i < noFrame; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement\n");

    for (int i = 0; i < noPage; i++) {
        if (!isHit(noFrame, frames, pages[i])) {
            frames[index] = pages[i];
            index = (index + 1) % noFrame;
            pageFault++;
        }
        printFrames(frames, noFrame, pages[i]);
    }

    printf("\nTotal Page Faults (FIFO): %d\n", pageFault);
}

void LRU() {

    int frames[noFrame], lastUsed[noFrame];
    int count = 0, faults = 0;

    for (int i = 0; i < noFrame; i++)
        frames[i] = -1;

    printf("\nLRU Page Replacement\n");

    for (int i = 0; i < noPage; i++) {

        int hit = 0;

        for (int j = 0; j < noFrame; j++) {
            if (pages[i] == frames[j]) {
                lastUsed[j] = i;
                hit = 1;
            }
        }

        if (!hit) {
            if (count < noFrame) {
                frames[count] = pages[i];
                lastUsed[count++] = i;
            } else {
                int least = 0;
                for (int j = 1; j < noFrame; j++)
                    if (lastUsed[j] < lastUsed[least])
                        least = j;

                frames[least] = pages[i];
                lastUsed[least] = i;
            }
            faults++;
        }

        printFrames(frames, noFrame, pages[i]);
    }

    printf("\nTotal Page Faults (LRU): %d\n", faults);
}

int main() {

    int choice;

    printf("Enter No of Pages: ");
    scanf("%d", &noPage);

    printf("Enter Page Numbers: ");
    for (int i = 0; i < noPage; i++)
        scanf("%d", &pages[i]);

    printf("Enter No of Frames: ");
    scanf("%d", &noFrame);

    printf("\n1. FIFO\n2. LRU\n3. Exit\n");
    printf("Enter The Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FIFO();
            break;
        case 2:
            LRU();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice\n");
    }

    return 0;
}
