//Reg No. : 24BAI10129
//Name : ADITYA AMAN

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data=new_data;
    new_node->next= *head_ref;
    
    *head_ref =new_node;
}

void printList(struct Node* node) {
    while (node!=NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = NULL;
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    
    printf("Linked list after insertion: ");
    printList(head);
    
    return 0;
}