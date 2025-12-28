#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define EMPTY -1

int hash(int key) {
    return key % MAX;
}

void init(int ht[]) {
    for (int i = 0; i < MAX; i++)
        ht[i] = EMPTY;
}

void insert(int ht[], int key) {
    int index = hash(key);

    if (ht[index] == EMPTY) {
        ht[index] = key;
        return;
    }

    printf("\nCollision Detected...!!!\n");
    printf("Collision avoided successfully using LINEAR PROBING\n");

    for (int i = (index + 1) % MAX; i != index; i = (i + 1) % MAX) {
        if (ht[i] == EMPTY) {
            ht[i] = key;
            return;
        }
    }

    printf("Hash table is full\n");
    exit(1);
}

void display(int ht[]) {
    int choice;
    printf("\n1. Display ALL\n2. Filtered Display\n");
    scanf("%d", &choice);

    printf("\n---------------------------------\n");
    printf("Index\t\tKey\n");
    printf("---------------------------------\n");

    for (int i = 0; i < MAX; i++) {
        if (choice == 1 || ht[i] != EMPTY)
            printf("%d\t\t%d\n", i, ht[i]);
    }

    printf("---------------------------------\n");
}


int main() {
    int ht[MAX], key, ch = 1;

    printf("collision handling by linear probing :\n");
    init(ht);

    while (ch) {
        printf("\nEnter the data: ");
        scanf("%4d", &key);
        insert(ht, key);
        printf("\nDo you wish to continue ? (1/0): ");
        scanf("%d", &ch);
    }

    display(ht);
    return 0;
}
