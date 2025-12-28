#include <stdio.h>

void printFrames(int frame[], int f, int page) {
    printf("Page %d -> ", page);
    for (int i = 0; i < f; i++)
        if (frame[i] != -1) printf("%d ", frame[i]);
        else printf("- ");
    printf("\n");
}

int runFIFO(int pages[], int n, int frame[], int f) {
    int pageFaults = 0, index = 0;

    printf("\nFIFO Page Replacement\n");
    for (int i = 0; i < n; i++) {
        int hit = 0;

        // Check if page already present
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i])
                hit = 1;

        // Page Fault
        if (!hit) {
            frame[index] = pages[i];
            index = (index + 1) % f;
            pageFaults++;
        }

        printFrames(frame, f, pages[i]);
    }

    return pageFaults;
}

int runLRU(int pages[], int n, int frame[], int f) {
    int pageFaults = 0;
    int temp[10];

    // initialize temp
    for (int i = 0; i < f; i++)
        temp[i] = -1;

    printf("\nLRU Page Replacement\n");

    for (int i = 0; i < n; i++) {
        int hit = 0;

        // check hit
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                hit = 1;
                temp[j] = i;
                break;
            }
        }

        if (!hit) {
            int replaceIndex = -1;

            // empty frame?
            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // if no empty frame, find LRU
            if (replaceIndex == -1) {
                replaceIndex = 0;
                for (int j = 1; j < f; j++)
                    if (temp[j] < temp[replaceIndex])
                        replaceIndex = j;
            }

            frame[replaceIndex] = pages[i];
            temp[replaceIndex] = i;
            pageFaults++;
        }

        printFrames(frame, f, pages[i]);
    }

    return pageFaults;
}

int main() {
    int pages[30], frame[10];
    int n, f, choice;

    printf("Enter number of pages: ");
    scanf(" %d", &n);

    printf("Enter page numbers: ");
    for (int i = 0; i < n; i++) scanf(" %d", &pages[i]);

    printf("Enter number of frames: ");
    scanf(" %d", &f);

    printf("\n1. FIFO\n2. LRU\nEnter your choice: ");
    scanf(" %d", &choice);

    // Initialize frames to empty
    for (int i = 0; i < f; i++) frame[i] = -1;

    int faults = 0;

    if (choice == 1)
        faults = runFIFO(pages, n, frame, f);
    else if (choice == 2)
        faults = runLRU(pages, n, frame, f);
    else {
        printf("Invalid choice!\n");
        return 0;
    }

    printf("\nTotal Page Faults (%s): %d\n",
           choice == 1 ? "FIFO" : "LRU", faults);

    return 0;
}
