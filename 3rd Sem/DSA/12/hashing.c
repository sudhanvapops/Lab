// ## PROGRAM - 12 

// 12) Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine the records in file F. Assume that file F is maintained in memory by a Hash Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of locations in HT. 

// Let the keys in K and addresses in L are Integers. 
// Develop a Program in C that uses Hash function H: K →L as H(K)=K mod m 
// (remainder method), and implement hashing technique to map a given key K to the address space L. Resolve the collision (if any) using linear probing

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
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
        printf("Do you wish to continue ? (1/0): ");
        scanf("%d", &ch);
    }

    display(ht);
    return 0;
}


// ### Output
// collision handling by linear probing :

// Enter the data: 20
// Do you wish to continue ? (1/0): 1

// Enter the data: 50

// Collision Detected...!!!
// Collision avoided successfully using LINEAR PROBING
// Do you wish to continue ? (1/0): 1

// Enter the data: 3
// Do you wish to continue ? (1/0): 1

// Enter the data: 6
// Do you wish to continue ? (1/0): 0

// 1. Display ALL
// 2. Filtered Display
// 2

// ---------------------------------
// Index           Key
// ---------------------------------
// 0               20
// 1               50
// 3               3
// 6               6
// ---------------------------------