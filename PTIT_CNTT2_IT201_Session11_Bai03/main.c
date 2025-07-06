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
int searchValue(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = NULL;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        head = appendNode(head, arr[i]);
    }
    int number;
    scanf("%d", &number);
    if (searchValue(head, number) == 1) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    return 0;
}