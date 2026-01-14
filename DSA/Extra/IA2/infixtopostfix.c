#include<stdio.h>
#include <ctype.h>
#include <math.h>  

int stack[100];
int top = -1;

void push(char ch){

}

char pop(){

}

int precedence(){

}

void infixToPostfic(int infix[], int postfix[]){
    int i=0,j=0; // i -> infix, j -> postfix
    char ch;

    push('#');

    while((ch = infix[i++])!='\0'){
        if(ch == isalnum(ch)){
            postfix[j++] = ch;
        }else if(ch == '('){
            push(ch);
        }else if (ch == ')'){
            while(stack[top--] != '(')
                postfix[j++] = pop();
            pop();
        }else { // operators
            while(precedence(ch) <= precedence(stack[top]))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while(stack[top--]!='#')
        postfix[j++] = pop();

    postfix[j] ='\0';
}


int main(){
    return 0;
}