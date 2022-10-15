#include<iostream>
using namespace std;

struct node{
    int val;
    node* next;
};

node* insertAtFirst(node* head,int x){
    node* temp=new node();
    if(head==NULL){
        temp->val=x;
        temp->next=NULL;
    }else{
        temp->val=x;
        temp->next=head;
    }
    return temp;
}

void insertAtIndex(node *head,int data,int index){
    node *temp=new node();///the node to be inserted
    node *prev=new node();//created to get node of previous index of desired index
    prev=head;//initializing
    int i=0;
    while(i!=(index-1)){//index=desired index that we passed in function
        prev=prev->next;
        i++;
    }//prev node pointer is now pointing at index-1 th node
    temp->next=prev->next;
    temp->val=data;
    prev->next=temp;
}

int main(){

    node *head=NULL;
    //initialize head with NULL
    head=insertAtFirst(head,10);
    insertAtIndex(head,20,1);
    cout<<head->val<<" "<<head->next->val;

    // node *head=new node();
    // node *second=new node();
    // node *third=new node();

    // head->val=5;
    // head->next=second;

    // second->val=10;
    // second->next=third;

    // third->val=30;
    // third->next=NULL;
}