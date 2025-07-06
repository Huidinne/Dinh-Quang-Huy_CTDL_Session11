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

Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("Empty list!\n");
        return NULL;
    }
    if (position < 1) {
        printf("Invalid pos!\n");
        return head;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    Node* temp = head;
    int currentPos = 1;
    while (temp != NULL && currentPos < position) {
        temp = temp->next;
        currentPos++;
    }
    if (temp == NULL) {
        printf("Invalid pos!\n");
        return head;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}
void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list!\n");
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
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 5);
    printList(head);
    int pos;
    scanf("%d",&pos);
    head = deleteAtPosition(head, pos);
    printList(head);
    return 0;
}