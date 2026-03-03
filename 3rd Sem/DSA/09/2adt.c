// ## PROGRAM - 09

// 9) Develop a Program in C for the following operations on Singly Circular Linked List 
// (SCLL) with header nodes a. Represent and Evaluate a Polynomial P(x,y,z) = 6x 2 y 2 z- 
// 4yz 5 +3x 3 yz+2xy 5 z-2xyz 3 b. Find the sum of two polynomials POLY1(x,y,z) and 
// POLY2(x,y,z) and store the result in POLYSUM(x,y,z) Support the program with 
// appropriate functions for each of the above operations

// Implemented only for one variable x

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int coeff, expo;
    struct node *next;
};

struct poly {
    struct node *head, *tail, *dummy;
};

/* ---------- Utility Functions ---------- */

void init_poly(struct poly *p) {
    p->dummy = (struct node *)malloc(sizeof(struct node));
    p->dummy->coeff = p->dummy->expo = 0;
    p->dummy->next = p->dummy;
    p->head = p->tail = NULL;
}

void add_term(struct poly *p, int c, int e) {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->coeff = c;
    t->expo = e;
    t->next = p->dummy;

    if (!p->head) {
        p->head = p->tail = t;
        p->dummy->next = t;
    } else {
        p->tail->next = t;
        p->tail = t;
    }
}

void create_poly(struct poly *p) {
    int n, c, e;
    scanf("%d", &n);
    printf("Enter coef & expo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        add_term(p, c, e);
    }
}

void display_poly(struct poly *p) {
    if (!p->head) {
        printf("0\n");
        return;
    }

    struct node *t = p->head;
    int first = 1;

    while (t != p->dummy) {
        if (!first)
            printf(t->coeff >= 0 ? " + " : " - ");
        else if (t->coeff < 0)
            printf("-");

        printf("%dx^%d", abs(t->coeff), t->expo);
        first = 0;
        t = t->next;
    }
    printf("\n");
}

void add_poly(struct poly *a, struct poly *b, struct poly *c) {
    init_poly(c);
    struct node *p = a->head, *q = b->head;

    while (p != a->dummy && q != b->dummy) {
        if (p->expo == q->expo) {
            int sum = p->coeff + q->coeff;
            if (sum != 0)
                add_term(c, sum, p->expo);
            p = p->next;
            q = q->next;
        } else if (p->expo > q->expo) {
            add_term(c, p->coeff, p->expo);
            p = p->next;
        } else {
            add_term(c, q->coeff, q->expo);
            q = q->next;
        }
    }

    while (p != a->dummy) {
        add_term(c, p->coeff, p->expo);
        p = p->next;
    }
    while (q != b->dummy) {
        add_term(c, q->coeff, q->expo);
        q = q->next;
    }
}

int eval_poly(struct poly *p, int x) {
    int result = 0;
    for (struct node *t = p->head; t != p->dummy; t = t->next)
        result += t->coeff * pow(x, t->expo);
    return result;
}

/* ---------- Main ---------- */

int main() {
    int ch, x;
    struct poly p1, p2, p3;

    printf("---------------- MENU ----------------\n");
    printf("Polynomial Operations\n");
    printf("1. Add\n2. Evaluate\n3. Exit\n");
    printf("-------------------------------------\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

        case 1:
            init_poly(&p1);
            init_poly(&p2);

            printf("Enter no of terms of polynomial: ");
            create_poly(&p1);
            printf("The polynomial is: ");
            display_poly(&p1);

            printf("Enter no of terms of polynomial: ");
            create_poly(&p2);
            printf("The polynomial is: ");
            display_poly(&p2);

            add_poly(&p1, &p2, &p3);
            printf("Addition of polynomial is: ");
            display_poly(&p3);
            break;

        case 2:
            init_poly(&p1);

            printf("Enter no of terms of polynomial: ");
            create_poly(&p1);
            printf("The polynomial is: ");
            display_poly(&p1);

            printf("Enter value of x: ");
            scanf("%d", &x);

            printf("Value of polynomial: %d\n", eval_poly(&p1, x));
            break;

        case 3:
            printf("Exit\n");
            exit(0);
        }
    }
}


// ### Output

// ---------------- MENU ----------------
// Polynomial Operations
// 1. Add
// 2. Evaluate
// 3. Exit
// -------------------------------------

// Enter your choice: 1
// Enter no of terms of polynomial: 3
// Enter coef & expo:
// 9 6 8 5 4 2
// The polynomial is: 9x^6 + 8x^5 + 4x^2
// Enter no of terms of polynomial: 3
// Enter coef & expo:
// 10 6 5 5 3 2
// The polynomial is: 10x^6 + 5x^5 + 3x^2
// Addition of polynomial is: 19x^6 + 13x^5 + 7x^2

// Enter your choice: 2
// Enter no of terms of polynomial: 3
// Enter coef & expo:
// 10 6 5 5 3 2
// The polynomial is: 10x^6 + 5x^5 + 3x^2
// Enter value of x: 3
// Value of polynomial: 8532

// Enter your choice: 3
// Exit