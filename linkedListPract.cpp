#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void insertAtIndex(node* head,int data,int index){
    node* temp=new node();
    node* prev=new node();
    prev=head;
    int i=0;
    while(i!=(index-1)){
        prev=prev->next;
        i++;
    }
    temp->next=prev->next;
    temp->data=data;
    prev->next=temp;
}

void printLL(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){

}