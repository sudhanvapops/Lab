// ## PROGRAM - 10 
 
// 10) Develop a menu driven Program in C for the following operations on Binary Search 
// Tree (BST) of Integers. 
// a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2 
// b. Traverse the BST in Inorder, Preorder and Post Order 
// c. Search the BST for a given element (KEY) and report the appropriatemessage 
// d. Exit

#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *left, *right;
} NODE;

NODE* createNode(int data) {
    NODE *n = (NODE*)malloc(sizeof(NODE));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

NODE* insert(NODE *root, int data) {
    if (!root) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

NODE* search(NODE *root, int data) {
    if (!root || root->data == data)
        return root;

    return (data < root->data) ? search(root->left, data) : search(root->right, data);
}

NODE* findMin(NODE *root) {
    while (root && root->left)
        root = root->left;
    return root;
}

NODE* deleteNode(NODE *root, int data) {
    if (!root) return NULL;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (!root->left) {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        NODE *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Traversal

void inorder(NODE *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* -------- SEARCH WITH PARENT -------- */

void searchWithParent(NODE *root, int key) {
    NODE *parent = NULL;
    NODE *curr = root;

    while (curr != NULL) {
        if (curr->data == key) {
            printf("The %d Element is Present\n", key);
            if (parent != NULL)
                printf("Parent of node %d is %d\n", key, parent->data);
            else
                printf("Node %d is the root (no parent)\n", key);
            return;
        }

        parent = curr;
        curr = (key < curr->data) ? curr->left : curr->right;
    }

    printf("Element %d not found\n", key);
}

void menu() {
    printf("\n1.Insert");
    printf("\n2.Search");
    printf("\n3.Delete");
    printf("\n4.Traversal");
    printf("\n5.Exit");
}

int main() {
    NODE *root = NULL;
    int ch, data, n;

    menu();
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter elements: ");
            while (n--) {
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;

        case 2:
            printf("Enter element to search: ");
            scanf("%d", &data);
            searchWithParent(root, data);
            break;

        case 3:
            printf("Enter element to delete: ");
            scanf("%d", &data);
        
            if (search(root, data) == NULL) {
                printf("Element %d does not exist in the BST\n", data);
            } else {
                root = deleteNode(root, data);
                printf("Element %d deleted successfully\n", data);
            }
            break;
        case 4:
            printf("Inorder: ");
            inorder(root);
            printf("\nPreorder: ");
            preorder(root);
            printf("\nPostorder: ");
            postorder(root);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}


// ### Output

// 1.Insert
// 2.Search
// 3.Traversal
// 4.Exit
// Enter choice: 1
// Enter number of elements: 12
// Enter elements: 
//  6 9 5 2 8 15 24 14 7 8 5 2

// Enter choice: 2
// Enter element to search: 10
// Element 10 not found

// Enter choice: 2
// Enter element to search: 15
// The 15 Element is Present
// Parent of node 15 is 9

// Enter choice: 3
// Inorder: 2 5 6 7 8 9 14 15 24 
// Preorder: 6 5 2 9 8 7 15 14 24
// Postorder: 2 5 7 8 14 24 15 9 6
// Enter choice: 4