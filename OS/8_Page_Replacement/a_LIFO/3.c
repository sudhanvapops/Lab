#include <stdio.h>

void printFrames(int frame[], int f, int page) {
    printf("Page %d -> ", page);
    for (int i = 0; i < f; i++)
        frame[i] == -1 ? printf("- ") : printf("%d ", frame[i]);
    printf("\n");
}


// Check wether the Page is already in exits in the memory
int isHit(int frame[], int f, int page) {
    for (int i = 0; i < f; i++)
        if (frame[i] == page) return 1;
    return 0;
}

void fifo(int pages[], int n, int f) {
    int frame[10], index = 0, faults = 0;

    for (int i = 0; i < f; i++) frame[i] = -1;

    printf("\nFIFO Page Replacement\n");

    for (int i = 0; i < n; i++) {
        if (!isHit(frame, f, pages[i])) {
            frame[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }
        printFrames(frame, f, pages[i]);
    }
    printf("\nTotal Page Faults (FIFO): %d\n", faults);
}

void lru(int pages[], int n, int f) {
    int frame[10], lastUsed[10], faults = 0, count = 0;

    for (int i = 0; i < f; i++) frame[i] = -1;

    printf("\nLRU Page Replacement\n");

    for (int i = 0; i < n; i++) {
        int hit = 0;

        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                lastUsed[j] = i;
                hit = 1;
            }
        }

        if (!hit) {
            if (count < f) {
                frame[count] = pages[i];
                lastUsed[count++] = i;
            } else {
                int least = 0;
                for (int j = 1; j < f; j++)
                    if (lastUsed[j] < lastUsed[least]) least = j;

                frame[least] = pages[i];
                lastUsed[least] = i;
            }
            faults++;
        }
        printFrames(frame, f, pages[i]);
    }
    printf("\nTotal Page Faults (LRU): %d\n", faults);
}

int main() {
    int pages[30], n, f, choice;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page numbers: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("\n1. FIFO\n2. LRU\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) fifo(pages, n, f);
    else if (choice == 2) lru(pages, n, f);
    else printf("Invalid choice!\n");

    return 0;
}
