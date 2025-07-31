//Name : ADITYA AMAN
//Reg No. : 24BAI10129

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Used to traverse the list

    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    
    struct Node* head = NULL;
    append(&head, 6);  
    append(&head, 4);  
    append(&head, 8);  
    append(&head, 2);  
    
    printf("Created Linked list is: ");
    printList(head);
    
    return 0;
}