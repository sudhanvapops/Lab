// ## PROGRAM - 06 
 
// 6) Develop a menu driven Program in C for the following operations on Circular QUEUE  of Characters (Array Implementation of Queue with maximum size MAX) 
// a. Insert an Element on to Circular QUEUE  b. Delete an Element from Circular QUEUE 
// c. Demonstrate Overflow and Underflow situations on Circular QUEUE 
// d. Display the status of Circular QUEUE e. Exit Support the program with appropriate functions for each of the above operations.

#include <stdio.h>
#include <stdlib.h>
#define MAX 3


int CQ[MAX];
int front = -1, rear = -1;


int isFull(){ return (front == ( rear + 1 ) % MAX); }
int isEmpty(){ return (front == -1); }


void insert(){

    if(isFull()){
        printf("Queue is full\n");
        return;
    }

    if(isEmpty())
        front = rear = 0;
    else rear = (rear + 1)%MAX;

    int item;
    printf("Enter element (number): "); 
    scanf("%d", &item);
    CQ[rear] = item;
    printf("Inserted: %d\n",item);

}


void deleteItem(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    
    printf("Deleted: %d\n", CQ[front]);
    (front == rear) ? ( front = rear = -1) : ( front = (front+1)%MAX );
    return;
}


void display(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }

    for(int i = front; ; i=(i+1)%MAX){
        printf("%d ",CQ[i]);
        if (i==rear) break;
    }

}


int main(){

    int choice;
    printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
    while (1) {
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: deleteItem(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

// ### Output
// 1.Insert  2.Delete  3.Display  4.Exit

// Enter choice:1
// Enter element (number): 1
// Inserted: 1

// Enter choice:1
// Enter element (number): 2
// Inserted: 2

// Enter choice:1
// Enter element (number): 3
// Inserted: 3

// Enter choice:1
// Queue is full

// Enter choice:3
// 1 2 3 
// Enter choice:2
// Deleted: 1

// Enter choice:3
// 2 3 
// Enter choice:1
// Enter element (number): 4
// Inserted: 4

// Enter choice:3
// 2 3 4 
// Enter choice:4