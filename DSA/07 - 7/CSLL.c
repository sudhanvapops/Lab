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
    if (!x) { printf("\033[31mOut of memory\033[0m\n"); exit(0); }
    return x;
}

void read_student(STUDENT *s) {
    printf("\033[33mEnter USN: \033[0m");
    scanf("%d", &s->usn);

    printf("\033[33mEnter Name: \033[0m");
    scanf("%s", s->name);

    printf("\033[33mEnter Branch: \033[0m");
    scanf("%s", s->branch);

    printf("\033[33mEnter Semester: \033[0m");
    scanf("%d", &s->semester);

    printf("\033[33mEnter Phone: \033[0m");
    scanf("%s", s->phone);
}

void print_student(STUDENT s) {
    printf("\033[36mUSN: %d, Name: %s, Branch: %s, Sem: %d, Phone: %s\033[0m\n",
           s.usn, s.name, s.branch, s.semester, s.phone);
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
    if (!first) { printf("\033[31mList empty\033[0m\n"); return NULL; }

    NODE t = first;
    print_student(t->s);
    first = first->link;
    free(t);
    return first;
}

NODE delete_end(NODE first) {
    if (!first) { printf("\033[31mList empty\033[0m\n"); return NULL; }
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
    if (!first) { printf("\n\033[31mLinked list is empty\033[0m\n"); return; }

    NODE cur = first;
    int count = 0;

    printf("\n\033[35mLinked list elements:\033[0m\n");
    while (cur) {
        print_student(cur->s);
        cur = cur->link;
        count++;
    }
    printf("\033[32mNo of students = %d\033[0m\n", count);
}

int main() {
    NODE first = NULL;
    STUDENT s;
    int ch, n;

    while (1) {
        printf("\n\033[36m----- MENU -----\033[0m\n"
               "\033[32m1 - Create SLL\n"
               "2 - Display\n"
               "3 - Insert at end\n"
               "4 - Delete end\n"
               "5 - Insert at beg\n"
               "6 - Delete beg\n"
               "7 - Exit\033[0m\n"
               "\033[36m----------------\033[0m\n"
               "\033[33mEnter choice: \033[0m"
            );

        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\033[33mEnter no of students: \033[0m");
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
            case 7: printf("\033[31mExiting...\033[0m\n"); exit(0);
        }
    }
}
