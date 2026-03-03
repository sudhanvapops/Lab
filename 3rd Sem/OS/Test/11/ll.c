// ! Output 


// Enter starting block (0-9): 5
// Enter file length: 4
// File allocated successfully!

// Block status:
// 0 0 0 0 0 1 1 1 1 0 

// Continue? (1-Yes / 0-No): 1

// Enter starting block (0-9): 7
// Enter file length: 3
// File cannot be allocated.

// Block status:
// 0 0 0 0 0 1 1 1 1 0

// Continue? (1-Yes / 0-No): 0

#include <stdio.h>

#define MAX 10

int main() {
    int blocks[MAX] = {0};
    int start, len, free, ch;

    do {
        printf("\nEnter starting block (0-9): ");
        scanf("%d", &start);

        printf("Enter file length: ");
        scanf("%d", &len);

        free = 1;
        if (start + len > MAX)
            free = 0;
        else
            for (int i = start; i < start + len; i++)
                if (blocks[i]==1) {
                    free = 0;
                    break;
                }

        if (free) {
            for (int i = start; i < start + len; i++)
                blocks[i] = 1;
            printf("File allocated successfully!\n");
        } else {
            printf("File cannot be allocated.\n");
        }

        printf("\nBlock status:\n");
        for (int i = 0; i < MAX; i++)
            printf("%d ", blocks[i]);

        printf("\n\nContinue? (1-Yes / 0-No): ");
        scanf("%d", &ch);

    } while (ch == 1);

    return 0;
}
