#include<stdio.h>

int main(){

    typedef struct {
        int data;
        struct Node *next;
    } Node;

    Node itm1,itm2;
    itm1.data = 0;
    itm2.data = 1;
    itm1.next = &itm2;
    

    return 0;
}