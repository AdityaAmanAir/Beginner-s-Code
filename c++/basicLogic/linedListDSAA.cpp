#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node* next;
};

Node* head=NULL;

void insertHead(int x){
    Node* temp = (Node*)malloc(sizeof(struct Node)); // new Node; (this is used in cpp), malloc is used in C
    temp ->data=x;
    temp ->next=head;
    head= temp;
}

void insertlast(int x){
    Node* temp = new Node;
    temp->data=x;
    temp->next=NULL;
    temp->next=head;
    head=temp;
    Node* temp2 = head;
    
    while(temp2->next!=NULL){
        temp2 =temp2->next;
    }temp2->next=temp;
    head=temp;
}

void print(){
    Node* temp= head;
    cout<<"The List is: ";
    while(temp!=NULL){
        cout<<(*temp).data<<" ";
        temp= temp->next;
    }
    cout<<"\n";

}

int main(){
    int size, number;
    cout<<"How many Numbers you want to add?\n";
    cin>>size;
    int s=size;
    while(size--){
        cout<<"Enter one Number\n";
        cin>>number;
        insertlast(number);
        print();
    }
    cout<<"The LINKEDList is : ";
    Node* temp=head;
    
    while(s--){
        
        cout<<temp->data;
        temp=(*temp).next;
    }
                 
    return 0;
} 