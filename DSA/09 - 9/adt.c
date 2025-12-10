#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int coeff, expo;
    struct node *ptr;
};

struct node *list1 = NULL, *list2 = NULL, *list3 = NULL;
struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
struct node *dummy1 = NULL, *dummy2 = NULL, *dummy3 = NULL;

// Create dummy node if it doesn't exist
void init_dummy(struct node **dummy) {
    if (*dummy == NULL) {
        *dummy = (struct node*)malloc(sizeof(struct node));
        (*dummy)->coeff = (*dummy)->expo = 0;
        (*dummy)->ptr = *dummy;
    }
}

// Add a term to polynomial - DRY principle
void add_term(struct node **list, struct node **head, struct node **dummy, int c, int e) {
    init_dummy(dummy);
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->expo = e;
    temp->ptr = *dummy;

    if (*list == NULL) {
        *list = *head = temp;
        (*dummy)->ptr = temp;
    } else {
        (*head)->ptr = temp;
        *head = temp;
    }
}

void create_poly(struct node **list, struct node **head, struct node **dummy) {
    int n, c, e;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter coefficient & power of each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        add_term(list, head, dummy, c, e);
    }
}

void add_poly() {
    init_dummy(&dummy3);
    list3 = head3 = NULL;
    
    struct node *temp1 = list1, *temp2 = list2;

    while (temp1 != dummy1 && temp2 != dummy2) {
        int c, e;
        if (temp1->expo == temp2->expo) {
            c = temp1->coeff + temp2->coeff;
            e = temp1->expo;
            temp1 = temp1->ptr;
            temp2 = temp2->ptr;
        } else if (temp1->expo > temp2->expo) {
            c = temp1->coeff;
            e = temp1->expo;
            temp1 = temp1->ptr;
        } else {
            c = temp2->coeff;
            e = temp2->expo;
            temp2 = temp2->ptr;
        }
        if (c != 0) add_term(&list3, &head3, &dummy3, c, e);
    }

    // Add remaining terms
    while (temp1 != dummy1) {
        add_term(&list3, &head3, &dummy3, temp1->coeff, temp1->expo);
        temp1 = temp1->ptr;
    }
    while (temp2 != dummy2) {
        add_term(&list3, &head3, &dummy3, temp2->coeff, temp2->expo);
        temp2 = temp2->ptr;
    }
}

void display_poly(struct node *list, struct node *dummy, char *name) {
    printf("%s: ", name);
    if (list == NULL || dummy == NULL) {
        printf("0\n");
        return;
    }

    struct node *temp = list;
    int first = 1;
    while (temp != dummy) {
        if (!first && temp->coeff >= 0) printf(" + ");
        else if (!first) printf(" ");
        if (temp->coeff < 0) printf("- ");
        printf("%dX^%d", abs(temp->coeff), temp->expo);
        temp = temp->ptr;
        first = 0;
    }
    printf("\n");
}

int eval_poly(struct node *list, struct node *dummy, int x) {
    if (list == NULL || dummy == NULL) return 0;
    int result = 0;
    struct node *temp = list;
    while (temp != dummy) {
        result += temp->coeff * pow(x, temp->expo);
        temp = temp->ptr;
    }
    return result;
}

int main() {
    int ch, x;
    printf("1.Create first polynomial\n2.Create second polynomial\n3.Display polynomials\n4.Add polynomials\n5.Evaluate polynomials\n6.Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create_poly(&list1, &head1, &dummy1);
                break;
            case 2:
                create_poly(&list2, &head2, &dummy2);
                break;
            case 3:
                display_poly(list1, dummy1, "POLYNOMIAL 1");
                display_poly(list2, dummy2, "POLYNOMIAL 2");
                if (list3) display_poly(list3, dummy3, "SUM");
                break;
            case 4:
                if (!list1 || !list2) {
                    printf("Create both polynomials first!\n");
                } else {
                    add_poly();
                    printf("Addition completed!\n");
                    display_poly(list3, dummy3, "RESULT");
                }
                break;
            case 5:
                printf("Enter value for x: ");
                scanf("%d", &x);
                if (list1) printf("Polynomial 1: %d\n", eval_poly(list1, dummy1, x));
                if (list2) printf("Polynomial 2: %d\n", eval_poly(list2, dummy2, x));
                if (list3) printf("Sum: %d\n", eval_poly(list3, dummy3, x));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Test input:
// 4 3 2 2 5 1
// 5 3 3 2 4 1