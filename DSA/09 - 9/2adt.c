#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int coeff, powX, powY, powZ;
    struct node *ptr;
};

struct node *list1 = NULL, *list2 = NULL, *list3 = NULL;
struct node *head1, *head2, *head3;
struct node *dummy1, *dummy2;

// DRY: Single function to create polynomial for any list
void create_poly(struct node **list, struct node **head, struct node **dummy, int c, int px, int py, int pz) {
    *dummy = (struct node*)malloc(sizeof(struct node));
    (*dummy)->coeff = (*dummy)->powX = (*dummy)->powY = (*dummy)->powZ = 0;
    (*dummy)->ptr = *list;
    
    if (*list == NULL) {
        *list = (struct node*)malloc(sizeof(struct node));
        (*list)->coeff = c;
        (*list)->powX = px;
        (*list)->powY = py;
        (*list)->powZ = pz;
        (*list)->ptr = *list;
        *head = *list;
        (*head)->ptr = *dummy;
    } else {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = c;
        temp->powX = px;
        temp->powY = py;
        temp->powZ = pz;
        (*head)->ptr = temp;
        temp->ptr = *dummy;
        *head = temp;
    }
}

void add_poly() {
    struct node *temp1 = list1, *temp2 = list2, *temp;
    list3 = NULL;
    head3 = NULL;
    
    while (temp1 != dummy1 && temp2 != dummy2) {
        temp = (struct node*)malloc(sizeof(struct node));
        
        // Check if terms have same powers (like terms)
        int same = (temp1->powX == temp2->powX && 
                   temp1->powY == temp2->powY && 
                   temp1->powZ == temp2->powZ);
        
        if (same) {
            // Add coefficients for like terms
            temp->coeff = temp1->coeff + temp2->coeff;
            temp->powX = temp1->powX;
            temp->powY = temp1->powY;
            temp->powZ = temp1->powZ;
            temp1 = temp1->ptr;
            temp2 = temp2->ptr;
        } else {
            // Compare which term comes first (higher powers first)
            int cmp = (temp1->powX != temp2->powX) ? (temp1->powX - temp2->powX) :
                      (temp1->powY != temp2->powY) ? (temp1->powY - temp2->powY) :
                      (temp1->powZ - temp2->powZ);
            
            if (cmp > 0) {
                temp->coeff = temp1->coeff;
                temp->powX = temp1->powX;
                temp->powY = temp1->powY;
                temp->powZ = temp1->powZ;
                temp1 = temp1->ptr;
            } else {
                temp->coeff = temp2->coeff;
                temp->powX = temp2->powX;
                temp->powY = temp2->powY;
                temp->powZ = temp2->powZ;
                temp2 = temp2->ptr;
            }
        }
        
        // Skip zero coefficients
        if (temp->coeff == 0) {
            free(temp);
            continue;
        }
        
        if (list3 == NULL) {
            list3 = temp;
            temp->ptr = list3; // Circular
            head3 = temp;
        } else {
            head3->ptr = temp;
            temp->ptr = list3; // Circular
            head3 = temp;
        }
    }
    
    // Handle remaining terms from poly1
    while (temp1 != dummy1) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = temp1->coeff;
        temp->powX = temp1->powX;
        temp->powY = temp1->powY;
        temp->powZ = temp1->powZ;
        
        if (list3 == NULL) {
            list3 = temp;
            temp->ptr = list3;
            head3 = temp;
        } else {
            head3->ptr = temp;
            temp->ptr = list3;
            head3 = temp;
        }
        temp1 = temp1->ptr;
    }
    
    // Handle remaining terms from poly2
    while (temp2 != dummy2) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->coeff = temp2->coeff;
        temp->powX = temp2->powX;
        temp->powY = temp2->powY;
        temp->powZ = temp2->powZ;
        
        if (list3 == NULL) {
            list3 = temp;
            temp->ptr = list3;
            head3 = temp;
        } else {
            head3->ptr = temp;
            temp->ptr = list3;
            head3 = temp;
        }
        temp2 = temp2->ptr;
    }
}

// DRY: Single display function
void display_list(struct node *list, struct node *dummy, const char *name) {
    printf("%s: ", name);
    struct node *temp = list;
    if (temp == NULL) {
        printf("Not created");
        return;
    }
    
    while (temp->ptr != list) {
        if (temp != list && temp->coeff > 0) printf("+");
        printf("%d", temp->coeff);
        if (temp->powX) printf("X^%d", temp->powX);
        if (temp->powY) printf("Y^%d", temp->powY);
        if (temp->powZ) printf("Z^%d", temp->powZ);
        temp = temp->ptr;
    }
    // Print last node
    if (temp->coeff > 0 && temp != list) printf("+");
    printf("%d", temp->coeff);
    if (temp->powX) printf("X^%d", temp->powX);
    if (temp->powY) printf("Y^%d", temp->powY);
    if (temp->powZ) printf("Z^%d", temp->powZ);
}

void display() {
    printf("\n");
    display_list(list1, dummy1, "POLYNOMIAL 1");
    printf("\n");
    display_list(list2, dummy2, "POLYNOMIAL 2");
    printf("\n");
    display_list(list3, NULL, "SUM OF POLYNOMIALS");
    printf("\n");
}

// DRY: Single evaluation function
int eval_list(struct node *list, struct node *dummy, int x, int y, int z) {
    int result = 0;
    struct node *temp = list;
    while (temp != dummy) {
        result += temp->coeff * pow(x, temp->powX) * pow(y, temp->powY) * pow(z, temp->powZ);
        temp = temp->ptr;
    }
    return result;
}

void eval_poly(int x, int y, int z) {
    printf("Polynomial 1 Evaluation: %d\n", eval_list(list1, dummy1, x, y, z));
    printf("Polynomial 2 Evaluation: %d\n", eval_list(list2, dummy2, x, y, z));
}

int main() {
    int ch, n, c, px, py, pz, x, y, z;
    
    printf("1.Create first polynomial\n2.Create second polynomial\n");
    printf("3.Display polynomials\n4.Add polynomials\n");
    printf("5.Evaluate polynomial\n6.Exit\n");
    
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
            case 2:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                printf("Enter coefficient & powers (coeff powX powY powZ) for each term:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d %d %d %d", &c, &px, &py, &pz);
                    if (ch == 1)
                        create_poly(&list1, &head1, &dummy1, c, px, py, pz);
                    else
                        create_poly(&list2, &head2, &dummy2, c, px, py, pz);
                }
                printf("Polynomial %d created successfully!\n", ch);
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                if (list1 && list2) {
                    add_poly();
                    printf("Addition completed!\n");
                    printf("RESULT:\n");
                    display_list(list3, NULL, "");
                    printf("\n");
                } else {
                    printf("Create both polynomials first!\n");
                }
                break;
                
            case 5:
                if (list1) {
                    printf("Enter values for x, y, z: ");
                    scanf("%d %d %d", &x, &y, &z);
                    eval_poly(x, y, z);
                } else {
                    printf("Create polynomial first!\n");
                }
                break;
                
            case 6:
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}