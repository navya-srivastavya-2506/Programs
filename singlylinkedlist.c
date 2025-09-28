#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert() {
    struct Node* newNode = malloc(sizeof(struct Node));
    int x;
    scanf("%d", &x);
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL) head = newNode;
    else {
        struct Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void delete() {
    int x; scanf("%d", &x);
    struct Node* temp = head, *prev = NULL;
    while(temp && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    if(prev == NULL) head = temp->next;
    else prev->next = temp->next;
    free(temp);
}

void display() {
    struct Node* temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        scanf("%d", &choice);
        if(choice == 1) insert();
        else if(choice == 2) delete();
        else if(choice == 3) display();
        else break;
    }
    return 0;
}
