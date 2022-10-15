#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
    node(){
        data=0;
        next=NULL;
    }
};

void insertAtIndex(node* &head,int index,int value){
    node* temp=new node(value);
    if(index==0){
        temp->next=head;
        head=temp;
        return;
    }
    node* prev=new node(value);
    prev=head;
    int i=0;
    while(i!=(index-1)){
        prev=prev->next;
        i++;
    }
    temp->next=prev->next;
    prev->next=temp;
}

void deleteNode(node* &head,int index){
    node* prev=new node();
    prev=head;
    int i=0;
    while(i!=index-1){
        prev=prev->next;
        i++;
    }
    prev->next=prev->next->next;
}

void displayLL(node* head){
    node* temp=head;
    cout<<head<<" -> ";
    while(temp->next!=NULL){
        cout<<temp->data<<" "<<temp->next<<" "<<"-> ";
        temp=temp->next;
    }
    cout<<temp->data<<" "<<temp->next;
}

int main(){
    node* head=NULL;
    insertAtIndex(head,0,5);
    insertAtIndex(head,1,10);
    insertAtIndex(head,2,15);
    insertAtIndex(head,3,20);
    insertAtIndex(head,4,25);
    deleteNode(head,2);
    displayLL(head);
    cout<<"\n"<<sizeof(node);
}