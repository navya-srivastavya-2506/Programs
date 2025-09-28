#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* getNthNode(struct Node* head, int n) {
    int count = 1;
    struct Node* current = head;
    while (current != NULL && count < n) {
        current = current->next;
        count++;
    }
    if (count == n && current != NULL)
        return current;
    return NULL;  // Nth node doesn't exist
}

int main() {
    int n, val, pos;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &pos);
    struct Node* result = getNthNode(head, pos);
    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No such node\n");
    return 0;
}
