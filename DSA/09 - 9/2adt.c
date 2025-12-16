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

// Initialize dummy node if it doesn't exist
void init_dummy(struct node **dummy) {
    if (*dummy == NULL) {
        *dummy = (struct node*)malloc(sizeof(struct node));
        (*dummy)->coeff = 0;
        (*dummy)->expo = 0;
        (*dummy)->ptr = *dummy;
    }
}

// Add a term to polynomial
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

// Create polynomial by reading user input
void create_poly(struct node **list, struct node **head, struct node **dummy) {
    int n, c, e;

    scanf("%d", &n);
    printf("Enter coefficient and exponent for each term:\n");

    for (int i = 0; i < n; i++) {
        printf("  Term %d: ", i + 1);
        scanf("%d %d", &c, &e);
        add_term(list, head, dummy, c, e);
    }
}

// Add two polynomials
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
        if (c != 0) {
            add_term(&list3, &head3, &dummy3, c, e);
        }
    }

    // Add remaining terms from polynomial 1
    while (temp1 != dummy1) {
        add_term(&list3, &head3, &dummy3, temp1->coeff, temp1->expo);
        temp1 = temp1->ptr;
    }
    
    // Add remaining terms from polynomial 2
    while (temp2 != dummy2) {
        add_term(&list3, &head3, &dummy3, temp2->coeff, temp2->expo);
        temp2 = temp2->ptr;
    }
}

// Display polynomial in a nice format
void display_poly(struct node *list, struct node *dummy) {
    if (list == NULL || list == dummy) {
        printf("0\n");
        return;
    }
    
    struct node *temp = list;
    int is_first = 1;

    while (temp != dummy) {
        // Skip terms with zero coefficient
        if (temp->coeff == 0) {
            temp = temp->ptr;
            continue;
        }
        
        // Print sign and coefficient
        if (!is_first) {
            if (temp->coeff > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        } else if (temp->coeff < 0) {
            printf("-");
        }
        
        int abs_coeff = abs(temp->coeff);
        
        // Handle different exponent cases
        if (temp->expo == 0) {
            // Constant term
            printf("%d", abs_coeff);
        } else if (temp->expo == 1) {
            // Linear term
            if (abs_coeff == 1) {
                printf("x");
            } else {
                printf("%dx", abs_coeff);
            }
        } else {
            // Higher order terms
            if (abs_coeff == 1) {
                printf("x^%d", temp->expo);
            } else {
                printf("%dx^%d", abs_coeff, temp->expo);
            }
        }
        
        temp = temp->ptr;
        is_first = 0;
    }
    printf("\n");
}

// Evaluate polynomial at given x value
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

// Print a separator line
void print_separator() {
    printf("----------------------\n");
}

int main() {
    int ch, x;

    // Display menu header
    print_separator();
    printf("         POLYNOMIAL OPERATIONS PROGRAM\n");
    print_separator();
    printf("\n");
    printf("  1. Add Two Polynomials\n");
    printf("  2. Evaluate a Polynomial\n");
    printf("  3. Exit\n");
    printf("\n");
    print_separator();

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("\n--- POLYNOMIAL ADDITION ---\n\n");
            
            // First polynomial
            printf("Enter number of terms for Polynomial 1: ");
            create_poly(&list1, &head1, &dummy1);
            printf("\nPolynomial 1: ");
            display_poly(list1, dummy1);

            // Second polynomial
            printf("\nEnter number of terms for Polynomial 2: ");
            create_poly(&list2, &head2, &dummy2);
            printf("\nPolynomial 2: ");
            display_poly(list2, dummy2);

            // Add and display result
            add_poly();
            printf("\n");
            print_separator();
            printf("Result: ");
            display_poly(list3, dummy3);
            print_separator();
            break;

        case 2:
            printf("\n--- POLYNOMIAL EVALUATION ---\n\n");
            
            printf("Enter number of terms: ");
            create_poly(&list1, &head1, &dummy1);
            
            printf("\nPolynomial: ");
            display_poly(list1, dummy1);

            printf("\nEnter value of x: ");
            scanf("%d", &x);

            int result = eval_poly(list1, dummy1, x);
            printf("\n");
            print_separator();
            printf("P(%d) = %d\n", x, result);
            print_separator();
            break;

        case 3:
            printf("\nExiting program. Goodbye!\n");
            exit(0);

        default:
            printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}