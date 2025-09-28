#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[MAX];
    scanf("%s", exp);
    int len = strlen(exp);
    for(int i=len-1; i>=0; i--) {
        char c = exp[i];
        if(isdigit(c)) push(c - '0');
        else {
            int val1 = pop();
            int val2 = pop();
            if(c == '+') push(val1 + val2);
            else if(c == '-') push(val1 - val2);
            else if(c == '*') push(val1 * val2);
            else if(c == '/') push(val1 / val2);
        }
    }
    printf("%d\n", pop());
    return 0;
}
