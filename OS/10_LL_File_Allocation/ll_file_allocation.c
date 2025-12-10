// !! Output
// Linked File Allocation Menu:
// 1. Create File
// 2. Display Files
// 3. Exit
// Enter your choice: 1
// Enter the name of the file: Sudhanva
// Enter the number of blocks for file Sudhanva: 5
// File Sudhanva created successfully!

// Linked File Allocation Menu:
// 1. Create File
// 2. Display Files
// 3. Exit
// Enter your choice: 2

// Files and Blocks:
// File Sudhanva: 0 1 2 3 4

// Linked File Allocation Menu:
// 1. Create File
// 2. Display Files
// 3. Exit
// Enter your choice: 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_BLOCKS 100

struct Block {
    int blockNumber;
    struct Block* nextBlock;
};

struct File {
    char name[20];
    struct Block* firstBlock;
};

struct Block* createBlock(int number) {
    struct Block* b = malloc(sizeof(struct Block));
    b->blockNumber = number;
    b->nextBlock = NULL;
    return b;
}

void appendBlock(struct Block** head, struct Block* newBlock) {
    if (*head == NULL) {
        *head = newBlock;
        return;
    }
    struct Block* temp = *head;
    while (temp->nextBlock) temp = temp->nextBlock;
    temp->nextBlock = newBlock;
}

void createFile(struct File* files, int* fileCount, char* name, int* blockCount) {
    if (*fileCount >= MAX_FILES) {
        printf("Maximum file limit reached!\n");
        return;
    }

    struct File* file = &files[*fileCount];
    strcpy(file->name, name);
    file->firstBlock = NULL;

    int n;
    printf("Enter the number of blocks for file %s: ", name);
    scanf("%d", &n);

    while (n-- > 0 && *blockCount < MAX_BLOCKS) {
        appendBlock(&file->firstBlock, createBlock((*blockCount)++));
    }

    if (*blockCount >= MAX_BLOCKS) printf("Maximum block limit reached!\n");

    printf("File %s created successfully!\n", name);
    (*fileCount)++;
}

void displayFiles(struct File* files, int fileCount) {
    if (!fileCount) {
        printf("No files created yet!\n");
        return;
    }

    printf("\nFiles and Blocks:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("File %s: ", files[i].name);

        struct Block* b = files[i].firstBlock;
        while (b) {
            printf("%d ", b->blockNumber);
            b = b->nextBlock;
        }
        printf("\n");
    }
}

int main() {
    struct File files[MAX_FILES];
    int fileCount = 0, blockCount = 0, choice;

    do {
        printf("\nLinked File Allocation Menu:\n"
               "1. Create File\n"
               "2. Display Files\n"
               "3. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char name[20];
            printf("Enter the name of the file: ");
            scanf("%s", name);
            createFile(files, &fileCount, name, &blockCount);
        }
        else if (choice == 2) displayFiles(files, fileCount);
        else if (choice != 3) printf("Invalid choice! Please try again.\n");

    } while (choice != 3);

    for (int i = 0; i < fileCount; i++) {
        struct Block* b = files[i].firstBlock;
        while (b) {
            struct Block* next = b->nextBlock;
            free(b);
            b = next;
        }
    }

    return 0;
}
