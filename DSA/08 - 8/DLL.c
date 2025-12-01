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

struct Enode {
    char ssn[15], name[20], dept[5], designation[10];
    float salary;
    long long int phno;
    struct Enode *left, *right;
} *head=NULL, *tail=NULL, *temp1;

int count = 0;

struct Enode* newNode(char s[], char n[], char d[], char de[], float sal, long long int p) {
    struct Enode *node = malloc(sizeof(struct Enode));
    strcpy(node->ssn, s); strcpy(node->name, n); strcpy(node->dept, d);
    strcpy(node->designation, de); node->salary = sal; node->phno = p;
    node->left = node->right = NULL;
    return node;
}

void create(char s[], char n[], char d[], char de[], float sal, long long int p) {
    struct Enode *node = newNode(s, n, d, de, sal, p);
    if (!head) head = tail = node;
    else { tail->right = node; node->left = tail; tail = node; }
    count++;
}

void display() {
    if (!head) { printf("\nList is empty.\n"); return; }

    printf("\n-----------------------------------------\n");
    printf(" Linked List Elements (From Beginning)\n");
    printf("-----------------------------------------\n");

    for (temp1 = head; temp1; temp1 = temp1->right) {
        printf("\nSSN          : %s", temp1->ssn);
        printf("\nName         : %s", temp1->name);
        printf("\nDepartment   : %s", temp1->dept);
        printf("\nDesignation  : %s", temp1->designation);
        printf("\nSalary       : %.2f", temp1->salary);
        printf("\nPhone Number : %lld\n", temp1->phno);
    }

    printf("-----------------------------------------\nTotal Employees = %d\n-----------------------------------------\n", count);
}

void ins_beg(char s[], char n[], char d[], char de[], float sal, long long int p) {
    struct Enode *node = newNode(s, n, d, de, sal, p);
    if (!head) head = tail = node;
    else { node->right = head; head->left = node; head = node; }
    count++;
}

void ins_end(char s[], char n[], char d[], char de[], float sal, long long int p) {
    create(s, n, d, de, sal, p);
}

void del_beg() {
    if (!head) { printf("\nList is empty!\n"); return; }
    printf("\nDeleted Employee (From Beginning):\n%s %s %s %s %.2f %lld\n",
           head->ssn, head->name, head->dept, head->designation, head->salary, head->phno);

    temp1 = head;
    if (head == tail) head = tail = NULL;
    else { head = head->right; head->left = NULL; }
    free(temp1); count--;
}

void del_end() {
    if (!tail) { printf("\nList is empty!\n"); return; }
    printf("\nDeleted Employee (From End):\n%s %s %s %s %.2f %lld\n",
           tail->ssn, tail->name, tail->dept, tail->designation, tail->salary, tail->phno);

    temp1 = tail;
    if (head == tail) head = tail = NULL;
    else { tail = tail->left; tail->right = NULL; }
    free(temp1); count--;
}

int main() {
    int choice, n;
    char ssn[15], name[20], dept[5], desig[10];
    float sal; long long int ph;

    printf("\n----------------- MENU --------------------\n"
           "1. Create\n2. Display\n3. Insert at Beginning\n4. Insert at End\n"
           "5. Delete at Beginning\n6. Delete at End\n7. Exit\n"
           "-------------------------------------------\n");

    while (1) {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of employees : ");
                scanf("%d", &n);
                while (n--) {
                    printf("\nEnter ssn, name, department, designation, salary, phone :\n");
                    scanf(" %s %s %s %s %f %lld", ssn, name, dept, desig, &sal, &ph);
                    create(ssn, name, dept, desig, sal, ph);
                }
                break;

            case 2: display(); break;

            case 3:
                printf("\nEnter ssn, name, department, designation, salary, phone :\n");
                scanf(" %s %s %s %s %f %lld", ssn, name, dept, desig, &sal, &ph);
                ins_beg(ssn, name, dept, desig, sal, ph);
                break;

            case 4:
                printf("\nEnter ssn, name, department, designation, salary, phone :\n");
                scanf(" %s %s %s %s %f %lld", ssn, name, dept, desig, &sal, &ph);
                ins_end(ssn, name, dept, desig, sal, ph);
                break;

            case 5: del_beg(); break;
            case 6: del_end(); break;

            case 7: printf("\nExit\n"); return 0;

            default: printf("\nInvalid choice!\n");
        }
    }
}
