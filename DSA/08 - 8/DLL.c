// 8) Develop a menu driven Program in C for the following operations on Doubly Linked
// List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
// a. Create a DLL of N Employees Data by using end insertion.
// b. Display the status of DLL and count the number of nodes in it
// c. Perform Insertion and Deletion at End of DLL
// d. Perform Insertion and Deletion at Front of DLL
// e. Demonstrate how this DLL can be used as Double Ended Queue. f. Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ssn[15], name[20], dept[5], desig[10];
    float sal;
    long long int ph;
} EmpData;

struct Enode {
    EmpData data;
    struct Enode *left, *right;
} *head = NULL, *tail = NULL;

int count = 0;

struct Enode* newNode(EmpData e) {
    struct Enode *node = malloc(sizeof(struct Enode));
    node->data = e;
    node->left = node->right = NULL;
    return node;
}

void insert(EmpData e, int atEnd) {
    struct Enode *node = newNode(e);
    if (!head) {
        head = tail = node;
    } else if (atEnd) {
        tail->right = node;
        node->left = tail;
        tail = node;
    } else {
        node->right = head;
        head->left = node;
        head = node;
    }
    count++;
}

void delete(int fromEnd) {
    if (!head) {
        printf("\nList is empty!\n");
        return;
    }
    struct Enode *temp = fromEnd ? tail : head;
    printf("\nDeleted Employee (%s):\n%s %s %s %s %.2f %lld\n",
           fromEnd ? "From End" : "From Beginning",
           temp->data.ssn, temp->data.name, temp->data.dept, 
           temp->data.desig, temp->data.sal, temp->data.ph);
    
    if (head == tail) {
        head = tail = NULL;
    } else if (fromEnd) {
        tail = tail->left;
        tail->right = NULL;
    } else {
        head = head->right;
        head->left = NULL;
    }
    free(temp);
    count--;
}

void display() {
    if (!head) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\n-----------------------------------------\n Linked List Elements\n-----------------------------------------\n");
    for (struct Enode *temp = head; temp; temp = temp->right) {
        printf("\nSSN: %s\nName: %s\nDept: %s\nDesignation: %s\nSalary: %.2f\nPhone: %lld\n",
               temp->data.ssn, temp->data.name, temp->data.dept, 
               temp->data.desig, temp->data.sal, temp->data.ph);
    }
    printf("-----------------------------------------\nTotal Employees = %d\n-----------------------------------------\n", count);
}

EmpData readInput() {
    EmpData e;
    printf("\nEnter ssn, name, dept, designation, salary, phone:\n");
    scanf(" %s %s %s %s %f %lld", e.ssn, e.name, e.dept, e.desig, &e.sal, &e.ph);
    return e;
}

int main() {
    int choice, n;
    EmpData e;
    
    printf("\n----------------- MENU --------------------\n"
           "1. Create\n2. Display\n3. Insert at Beginning\n4. Insert at End\n"
           "5. Delete at Beginning\n6. Delete at End\n7. Exit\n"
           "-------------------------------------------\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of employees: ");
                scanf("%d", &n);
                while (n--) {
                    e = readInput();
                    insert(e, 1);
                }
                break;
            case 2:
                display();
                break;
            case 3:
                e = readInput();
                insert(e, 0);
                break;
            case 4:
                e = readInput();
                insert(e, 1);
                break;
            case 5:
                delete(0);
                break;
            case 6:
                delete(1);
                break;
            case 7:
                printf("\nExit\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }
}