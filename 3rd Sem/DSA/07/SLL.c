// ## PROGRAM - 07 
 
// 7. Develop a menu driven Program in C for the following operations on Singly Linked 
// List (SLL) of Student Data with the fields: USN, Name, Programme, Sem, PhNo 
// a. Create a SLL of N Students Data by using front insertion. 
// b. Display the status of SLL and count the number of nodes in it 
// c. Perform Insertion / Deletion at End of SLL 
// d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack) 
// e. Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int usn, semester;
    char name[20], branch[20], phone[20];
} STUDENT;

typedef struct node {
    STUDENT s;
    struct node *link;
} *NODE;

NODE getnode() {
    NODE x = malloc(sizeof(struct node));
    if (!x) { printf("Out of memory\n"); exit(0); }
    return x;
}

void read_student(STUDENT *s) {
    printf("Enter USN: ");
    scanf("%d", &s->usn);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Branch: ");
    scanf("%s", s->branch);

    printf("Enter Semester: ");
    scanf("%d", &s->semester);

    printf("Enter Phone: ");
    scanf("%s", s->phone);
}


void print_student(STUDENT s) {
    printf("USN: %d, Name: %s, Branch: %s, Sem: %d, Phone: %s\n", s.usn, s.name, s.branch, s.semester, s.phone);
}

NODE create_node(STUDENT s) {
    NODE t = getnode();
    t->s = s;
    t->link = NULL;
    return t;
}

NODE insert_end(NODE first, STUDENT s) {
    NODE t = create_node(s);
    if (!first) return t;

    NODE cur = first;
    while (cur->link) cur = cur->link;
    cur->link = t;
    return first;
}

NODE insert_beg(NODE first, STUDENT s) {
    NODE t = create_node(s);
    t->link = first;
    return t;
}

NODE delete_beg(NODE first) {
    if (!first) { printf("List empty\n"); return NULL; }

    NODE t = first;
    print_student(t->s);
    first = first->link;
    free(t);
    return first;
}

NODE delete_end(NODE first) {
    if (!first) { printf("List empty\n"); return NULL; }
    if (!first->link) {
        print_student(first->s);
        free(first);
        return NULL;
    }

    NODE cur = first, prev = NULL;
    while (cur->link) { prev = cur; cur = cur->link; }

    print_student(cur->s);
    free(cur);
    prev->link = NULL;
    return first;
}

void display(NODE first) {
    if (!first) { printf("Linked list is empty\n"); return; }

    NODE cur = first;
    int count = 0;

    printf("\nLinked list elements: \n");
    while (cur) {
        print_student(cur->s);
        cur = cur->link;
        count++;
    }
    printf("No of students = %d\n", count);
}

int main() {
    NODE first = NULL;
    STUDENT s;
    int ch, n;
    printf("\n----- MENU -----\n"
            "1 - Create SLL\n"
            "2 - Display\n"
            "3 - Insert at end\n"
            "4 - Delete end\n"
            "5 - Insert at beg\n"
            "6 - Delete beg\n"
            "7 - Exit\n"
            "----------------\n");

    while (1) {
       
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter no of students: ");
                scanf("%d", &n);
                while (n--) {
                    read_student(&s);
                    first = insert_end(first, s);
                }
                break;

            case 2: display(first); break;
            case 3: read_student(&s); first = insert_end(first, s); break;
            case 4: first = delete_end(first); break;
            case 5: read_student(&s); first = insert_beg(first, s); break;
            case 6: first = delete_beg(first); break;
            case 7: exit(0);
        }
    }
}


// ### Output
// ----- MENU -----
// 1 - Create SLL
// 2 - Display
// 3 - Insert at end
// 4 - Delete end
// 5 - Insert at beg
// 6 - Delete beg
// 7 - Exit
// ----------------

// Enter choice: 1
// Enter no of students: 2
// Enter USN: 1
// Enter Name: abc
// Enter Branch: ise
// Enter Semester: 3
// Enter Phone: 9620
// Enter USN: 2
// Enter Name: def
// Enter Branch: ise
// Enter Semester: 3
// Enter Phone: 974

// Enter choice: 2

// Linked list elements:
// USN: 1, Name: abc, Branch: ise, Sem: 3, Phone: 9620
// USN: 2, Name: def, Branch: ise, Sem: 3, Phone: 974
// No of students = 2

// Enter choice: 3
// Enter USN: 3
// Enter Name: ghi
// Enter Branch: ise
// Enter Semester: 3
// Enter Phone: 895


// Enter choice: 5
// Enter USN: 4
// Enter Name: klm
// Enter Branch: ise
// Enter Semester: 3
// Enter Phone: 569

// Enter choice: 2

// Linked list elements:
// USN: 4, Name: klm, Branch: ise, Sem: 3, Phone: 569
// USN: 1, Name: abc, Branch: ise, Sem: 3, Phone: 9620
// USN: 2, Name: def, Branch: ise, Sem: 3, Phone: 974
// USN: 3, Name: ghi, Branch: ise, Sem: 3, Phone: 895
// No of students = 4

// Enter choice: 4
// USN: 3, Name: ghi, Branch: ise, Sem: 3, Phone: 895

// Enter choice: 6
// USN: 4, Name: klm, Branch: ise, Sem: 3, Phone: 569

// Enter choice: 7