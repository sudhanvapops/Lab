#include<stdio.h>
#include<stdlib.h>

typedef struct bst {
    int data;
    struct bst *left,*right;
} NODE;


NODE* createNode(int data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->left=node->right = NULL;
    return node;
}

NODE* insert(NODE* root,int data){

    if(!root) return createNode(data);

    if(root->data < data)
        root->right = insert(root->right,data);
    else if (root->data > data)
        root->left = insert(root->left,data);

    return root;
}

void search(NODE* root,int key){
    NODE *parent=NULL,*curr=root;

    while(curr!=NULL){
        if(curr->data == key){
            printf("elemet %d found\n",key);
            if(parent!=NULL){
                printf("parent of Node %d is %d\n",key,parent->data);
            }else{
                printf("No parent %d is the root node",key);
            }
            return;
        }

        parent = curr;
        curr = (curr->data < key) ? (curr->right) : (curr->left);
    }

    printf("Element %d not found\n",key);

}


void inorder(NODE* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}

void postorder(NODE* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void preorder(NODE* root){
    if(!root) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void menu() {
    printf("\n1.Insert");
    printf("\n2.Search");
    printf("\n3.Traversal");
    printf("\n4.Exit\n");
}

int main(){

    NODE *root=NULL;
    int ch,n,ele;

    menu();

    while (1) {
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Enter number of elements to be inserted: ");
                scanf("%d",&n);
                while (n--) {
                    printf("Enter the elements: ");
                    scanf("%d",&ele);
                    root = insert(root,ele);
                }
                break;
            
            case 2:
                printf("Enter the element to search: ");
                scanf("%d",&ele);
                search(root,ele);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\nPreorder: ");
                preorder(root);
                printf("\nPostorder: ");
                postorder(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option try again\n");
        }

    }
    
    return 0;
}