#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if(top == -1) return -1;
    return stack[top--];
}

char peek() {
    if(top == -1) return -1;
    return stack[top];
}

int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j=0;
    scanf("%s", infix);
    for(i=0; infix[i]!='\0'; i++) {
        char c = infix[i];
        if(isalnum(c)) postfix[j++] = c;
        else if(c == '(') push(c);
        else if(c == ')') {
            while(top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop();
        }
        else {
            while(top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while(top != -1) postfix[j++] = pop();
    postfix[j] = '\0';
    printf("%s\n", postfix);
    return 0;
}
