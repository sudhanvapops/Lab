#include <stdio.h>
#include <math.h>
#define MAX 20

struct Stack {
    int top;
    float items[MAX];
} s; 

void push(float x) {
    if (s.top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s.items[++s.top] = x;
}

float pop() {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return 0;
    }
    return s.items[s.top--];
}

int isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

float operate(float op1, float op2, char ch) {
    switch (ch) {
        case '+': return op2 + op1;
        case '-': return op2 - op1;
        case '*': return op2 * op1;
        case '/': return op2 / op1;
        case '^': return pow(op2, op1);
        default:  return 0;
    }
}

int main() {

    s.top = -1; 
    
    char postfix[MAX];
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        
        if (isOperand(postfix[i])) {
            push(postfix[i] - '0');
            printf("Pushed: %c | Stack Top: %.2f\n", postfix[i], s.items[s.top]);
        } else {
            float op1 = pop();
            float op2 = pop();
            float result = operate(op1, op2, postfix[i]);
            push(result);
            printf("Computed: %.2f %c %.2f = %.2f | Stack Top: %.2f\n",
                   op2, postfix[i], op1, result, s.items[s.top]);
        }
    }

    printf("\nFinal Answer: %.2f\n", s.items[s.top]);
    return 0;
}
