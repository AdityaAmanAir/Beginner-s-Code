#include <iostream>
using namespace std;

struct Node{
    int data1;
    Node* next;

    Node(int val){
        data1 =val;
        next == nullptr;
    }
};

void push(Node* &head, int new_data){
    Node* new_node =new Node(new_data);

    new_node->data1 =new_data;
    head = new_node;
}

void printList(Node* node){
    Node* temp = head;
    while( node!= nullptr){
        cout<<node->data1<<"->";
        node = node->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
Node* head= nullptr;

push(head, 10);
push(head, 20);
push(head, 30);
push(head, 40);

cout<<"LINKED LIST ";
printList(head);
    return 0;
}