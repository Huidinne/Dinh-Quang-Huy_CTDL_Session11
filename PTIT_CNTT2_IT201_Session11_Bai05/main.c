#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* addNodeAtHead(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("This list is empty!\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = addNodeAtHead(head, 1);
    head = addNodeAtHead(head, 2);
    head = addNodeAtHead(head, 3);
    head = addNodeAtHead(head, 4);
    head = addNodeAtHead(head, 5);
    printList(head);
    head = addNodeAtHead(head, 7);
    printList(head);
    return 0;
}