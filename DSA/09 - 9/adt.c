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

    scanf("%d", &n);
    printf("Enter coef & expo: \n");

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


void display_poly(struct node *list, struct node *dummy) {
    if (list == NULL || dummy == NULL || list == dummy) {
        printf("0\n");
        return;
    }

    struct node *temp = list;
    int first = 1;

    while (temp != dummy) {
        if (!first) {
            if (temp->coeff >= 0)
                printf(" + ");
            else
                printf(" - ");
        } else {
            if (temp->coeff < 0)
                printf("-");
        }

        printf("%d", abs(temp->coeff));
        printf("x^%d", temp->expo);

        first = 0;
        temp = temp->ptr;
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

    printf("---------------- MENU ---------------\n");
    printf("Polynomial Operations :  \n1.Add\n");
    printf("2.Evaluate\n");
    printf("3.Exit\n");
    printf("-------------------------------------\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

        case 1:
            printf("Enter no of terms of polynomial: ");
            create_poly(&list1, &head1, &dummy1);

            printf("The polynomial is: ");
            display_poly(list1, dummy1);

            printf("Enter no of terms of polynomial: ");
            create_poly(&list2, &head2, &dummy2);

            printf("The polynomial is: ");
            display_poly(list2, dummy2);

            add_poly();
            printf("Addition of polynomial The polynomial is: ");
            display_poly(list3, dummy3);
            break;

        case 2:

            list1 = NULL;
            head1 = NULL;
            dummy1 = NULL;

            printf("Enter no of terms of polynomial: ");
            create_poly(&list1, &head1, &dummy1);

            printf("The polynomial is: ");
            display_poly(list1, dummy1);

            printf("Enter the value of x: ");
            scanf("%d", &x);

            printf("Value of polynomial: %d\n",
            eval_poly(list1, dummy1, x));
            break;

        case 3:
            printf("exit\n");
            exit(0);
        }
    }
}



// void display_poly(struct node *list, struct node *dummy) {
//     struct node *temp = list;
//     int first = 1;

//     while (temp != dummy) {
//         if (!first)
//             printf(" + ");
//         printf("%dx^(%d)", temp->coeff, temp->expo);
//         temp = temp->ptr;
//         first = 0;
//     }
//     printf("\n");
// }


// Test input:
// 4 3 2 2 5 1
// 5 3 3 2 4 1
// 3 1 4 2 5 4


// ! Output 

// ---------------- MENU ---------------
// Polynomial Operations :  
// 1.Add
// 2.Evaluate
// 3.Exit
// -------------------------------------

// Enter your choice: 1
// Enter no of terms of polynomial: 3
// Enter coef & expo: 
// 4 3 2 2 5 1
// The polynomial is: 4x^3 + 2x^2 + 5x^1
// Enter no of terms of polynomial: 3
// Enter coef & expo: 
// 5 3 3 2 4 1
// The polynomial is: 5x^3 + 3x^2 + 4x^1
// Addition of polynomial The polynomial is: 9x^3 + 5x^2 + 9x^1

// Enter your choice: 2
// Enter no of terms of polynomial: 3
// Enter coef & expo: 
// 3 1 4 2 5 4
// The polynomial is: 3x^1 + 4x^2 + 5x^4
// Enter the value of x: 2
// Value of polynomial: 102

// Enter your choice: 3
// exit