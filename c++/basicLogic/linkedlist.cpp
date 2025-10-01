#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x){
    Node* temp = (Node*)malloc(sizeof(struct Node)); // new Node; (this is used in cpp), malloc is used in C
    temp ->data=x;
    temp ->next=head;
    head= temp;
}

void print(){
    struct Node* temp= head;
    cout<<"The List is: ";
    while(temp!=NULL){
        cout<<(*temp).data<<" ";
        temp= temp->next;
    }
    cout<<"\n";

}

int main(){
    head= NULL;
    cout<<head->data<<endl;
    cout<<head->next;         
    return 0;
} 