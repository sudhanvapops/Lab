#include <stdio.h>
#include <string.h>

struct File { char name[20]; };
struct Dir {
    char name[20];
    struct File files[10];
    int fileCount;
};


void printFiles(struct File files[], int count) {
    for (int i = 0; i < count; i++)
        printf("%s\n", files[i].name);
}

void deleteFile(struct File files[], int *count, char fname[]) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(files[i].name, fname) == 0) {
            for (int j = i; j < *count - 1; j++)
                files[j] = files[j + 1];
            (*count)--;
            printf("File deleted successfully!\n");
            return;
        }
    }
    printf("File not found!\n");
}

void createSingleFile(struct File files[], int *count) {
    printf("Enter file name to create: ");
    scanf("%s", files[(*count)++].name);
    printf("File created successfully!\n");
}

void searchSingleFile(struct File files[], int count) {
    char fname[20];
    printf("Enter file name to search: ");
    scanf("%s", fname);

    for (int i = 0; i < count; i++)
        if (strcmp(files[i].name, fname) == 0) {
            printf("File found!\n");
            return;
        }

    printf("File not found!\n");
}

void singleLvlDir() {
    struct File files[10];
    int fileCount = 0, ch;

    printf("\n--- Single Level Directory Simulation ---\n");
    do {
        printf("\n1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: createSingleFile(files, &fileCount); break;
            case 2: {
                char fname[20];
                printf("Enter file name to delete: ");
                scanf("%s", fname);
                deleteFile(files, &fileCount, fname);
                break;
            }
            case 3: searchSingleFile(files, fileCount); break;
            case 4:
                printf("\nFiles in Directory:\n");
                printFiles(files, fileCount);
                break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 5);
}


void createDirectory(struct Dir dirs[], int *dirCount) {
    printf("Enter directory name: ");
    scanf("%s", dirs[*dirCount].name);
    dirs[*dirCount].fileCount = 0;
    (*dirCount)++;
    printf("Directory created successfully!\n");
}

void createFileTwoLevel(struct Dir dirs[], int dirCount) {
    char dname[20];
    printf("Enter directory name: ");
    scanf("%s", dname);

    for (int i = 0; i < dirCount; i++) {
        if (strcmp(dirs[i].name, dname) == 0) {
            printf("Enter file name to create: ");
            scanf("%s", dirs[i].files[dirs[i].fileCount++].name);
            printf("File created in directory %s\n", dname);
            return;
        }
    }

    printf("Directory not found!\n");
}

void searchFileTwoLevel(struct Dir dirs[], int dirCount) {
    char fname[20];
    printf("Enter file name to search: ");
    scanf("%s", fname);

    for (int i = 0; i < dirCount; i++)
        for (int j = 0; j < dirs[i].fileCount; j++)
            if (strcmp(dirs[i].files[j].name, fname) == 0) {
                printf("File found in directory %s\n", dirs[i].name);
                return;
            }
}

void displayTwoLevel(struct Dir dirs[], int dirCount) {
    printf("\nDirectory Structure:\n");
    for (int i = 0; i < dirCount; i++) {
        printf("\nDirectory: %s\n", dirs[i].name);
        printFiles(dirs[i].files, dirs[i].fileCount);
    }
}

void twoLvlDir() {
    struct Dir dirs[5];
    int dirCount = 0, ch;

    printf("\n--- Two Level Directory Simulation ---\n");

    do {
        printf("\n1. Create Directory\n2. Create File\n3. Search File\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: createDirectory(dirs, &dirCount); break;
            case 2: createFileTwoLevel(dirs, dirCount); break;
            case 3: searchFileTwoLevel(dirs, dirCount); break;
            case 4: displayTwoLevel(dirs, dirCount); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 5);
}

int main() {
    int choice;

    printf("1. Single Level Directory\n"
        "2. Two Level Directory\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) singleLvlDir();
    else if (choice == 2) twoLvlDir();
    else printf("Invalid choice!\n");

    return 0;
}
