#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList() {
    return NULL;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) return head;
    if (position == 1) return insertAtBeginning(head, data);
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) {
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) return NULL;
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) return head;
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = createList();
    head = insertAtEnd(head, 10);
    head = insertAtBeginning(head, 5);
    head = insertAtPosition(head, 7, 2);
    head = insertAtEnd(head, 15);
    traverseList(head);
    head = deleteNode(head, 7);
    traverseList(head);
    freeList(head);
    return 0;
}