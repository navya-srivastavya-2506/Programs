#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertSorted(struct Node* head, int x) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL || head->data >= x) {
        newNode->next = head;
        return newNode;
    }
    struct Node* curr = head;
    while(curr->next && curr->next->data < x) curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

void display(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, x;
    scanf("%d", &n);
    struct Node* head = NULL;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);

