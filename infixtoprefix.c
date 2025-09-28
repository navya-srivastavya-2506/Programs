#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void reverse(char str[]) {
    int n = strlen(str);
    for(int i=0; i<n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

int main() {
    char infix[MAX], prefix[MAX];
    scanf("%s", infix);
    int len = strlen(infix);
    reverse(infix);
    for(int i=0; i<len; i++) {
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }
    int i=0, j=0;
    while(infix[i] != '\0') {
        char c = infix[i];
        if(isalnum(c)) prefix[j++] = c;
        else if(c == '(') push(c);
        else if(c == ')') {
            while(top != -1 && peek() != '(')
                prefix[j++] = pop();
            pop();
        }
        else {
            while(top != -1 && precedence(peek()) > precedence(c))
                prefix[j++] = pop();
            push(c);
        }
        i++;
    }
    while(top != -1) prefix[j++] = pop();
    prefix[j] = '\0';
    reverse(prefix);
    printf("%s\n", prefix);
    return 0;
}
