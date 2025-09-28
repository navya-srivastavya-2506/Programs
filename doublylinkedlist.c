#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL) head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFromBeginning() {
    if(head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    if(head != NULL) head->prev = NULL;
    free(temp);
}

void deleteFromEnd() {
    if(head == NULL) return;
    struct Node* temp = head;
    if(temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }
    while(temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void displayForward() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward() {
    if(head == NULL) return;
    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, x;
    while(1) {
        scanf("%d", &choice);
        switch(choice) {
            case 1: scanf("%d", &x); insertAtBeginning(x); break;
            case 2: scanf("%d", &x); insertAtEnd(x); break;
            case 3: deleteFromBeginning(); break;
            case 4: deleteFromEnd(); break;
            case 5: displayForward(); break;
            case 6: displayBackward(); break;
            default: exit(0);
        }
    }
    return 0;
}
