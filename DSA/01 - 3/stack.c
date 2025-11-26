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
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Palindrome\n4.Display\n5.Exit\nChoice: ");
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
