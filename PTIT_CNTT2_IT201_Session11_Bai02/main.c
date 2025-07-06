#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* appendNode(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("Node%d: %d\n",count+1, temp->data);
        temp = temp->next;
        count++;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = NULL;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        head = appendNode(head, arr[i]);
    }
    printList(head);
    return 0;
}