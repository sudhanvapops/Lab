// ## PROGRAM - 03 
 
// 3) Develop a menu driven Program in C for the following operations on STACK of 
// Integers (Array Implementation of Stack with maximum size MAX) 
// a. Push an Element on to Stack 
// b. Pop an Element from Stack 
// c. Demonstrate how Stack can be used to check Palindrome 
// d. Demonstrate Overflow and Underflow situations on Stack 
// e. Display the status of Stack 
// f. Exit 
// Support the program with appropriate functions for each of the above operations

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX], top = -1;

void push() {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    int item;
    printf("Enter element: ");
    scanf("%d", &item);
    stack[++top] = item;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

void palindrome() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0, j = top; i < j; i++, j--) {
        if (stack[i] != stack[j]) {
            printf("Not Palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}

int main() {
    int choice;
    printf("\n1.Push\n2.Pop\n3.Palindrome\n4.Display\n5.Exit\n");
    while (1) {
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: palindrome(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

// ### Output
// 1.Push
// 2.Pop
// 3.Palindrome
// 4.Display
// 5.Exit
// Choice: 1
// Enter element: 1
// Choice: 1
// Enter element: 2
// Choice: 1
// Enter element: 1
// Choice: 3
// Palindrome
// Choice: 2
// Popped: 1
// Choice: 2
// Popped: 2
// Choice: 2
// Popped: 1
// Choice: 1
// Enter element: 
// 5
// Choice: 1
// Enter element: 4
// Choice: 4
// Stack elements:
// 4
// 5
// Choice: 5