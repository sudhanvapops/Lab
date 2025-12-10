// 6) Develop a menu driven Program in C for the following operations on Circular QUEUE
// of Characters (Array Implementation of Queue with maximum size MAX)
// a. Insert an Element on to Circular QUEUE
// b. Delete an Element from Circular QUEUE
// c. Demonstrate Overflow and Underflow situations on Circular QUEUE
// d. Display the status of Circular QUEUE 
// e. Exit Support the program with
// appropriate functions for each of the above operations.



#include <stdio.h>
#include <stdlib.h>
#define MAX 3

char CQ[MAX];
int front = -1, rear = -1;

int isFull()  { return (front == (rear + 1) % MAX); }
int isEmpty() { return (front == -1); }

void showMsg(char *msg) { printf("%s\n", msg); }

void insert(char item) {
    if (isFull()) return showMsg("Queue Overflow!");
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % MAX;
    CQ[rear] = item;
    printf("Inserted: %c\n", item);
}

void deleteItem() {
    if (isEmpty()) return showMsg("Queue Underflow!");
    printf("Deleted: %c\n", CQ[front]);
    (front == rear) ? (front = rear = -1) : (front = (front + 1) % MAX);
}

void display() {
    if (isEmpty()) return showMsg("Queue is Empty!");
    printf("Queue Elements: ");
    for (int i = front; ; i = (i + 1) % MAX) {
        printf("%c ", CQ[i]);
        if (i == rear) break;
    }
    printf("\n");
}

int main() {
    int choice;
    char item;
    printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
    while (1) {
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter element (char): "); scanf(" %c", &item); insert(item); break;
            case 2: deleteItem(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: showMsg("Invalid choice!");
        }
    }
}
