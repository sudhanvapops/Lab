// 4) Develop a Program in C for converting an Infix Expression to Postfix Expression.
// Program should support for both parenthesized and free parenthesized expressions with
// the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.

// Input -> (A+B)*(C^D-E)^(F+G*H)-I
// Output -> Infix Expression: (A+B)*(C^D-E)^(F+G*H)-I
// Postfix Expression: AB+CD^E-FGH*+^*I-

#include <stdio.h>
#include <ctype.h>
#include <math.h>  
#define SIZE 50

// Stack implementation
char stack[SIZE];
int top = -1;

void push(char elem) {
    if (top < SIZE - 1)
        stack[++top] = elem;
    else
        printf("Stack Overflow!\n");
}

char pop() {
    if (top >= 0)
        return stack[top--];
    else
        return '#';
}

int precedence(char op) {
    switch (op) {
        case '(': return 1;
        case '+': case '-': return 2;
        case '*': case '/': case '%': return 3;
        case '^': return 4;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;
    push('#'); // Sentinel to mark bottom of stack

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;  // Operand directly to output
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); // Remove '(' from stack
        } else { // Operator
            while (precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nInfix Expression: %s", infix);
    printf("\nPostfix Expression: %s\n", postfix);

    return 0;
}
