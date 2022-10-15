#include<iostream>
using namespace std;

struct node{
    int val;
    node* next;
};//we can create a class with same parameters and can initialize the constructor for setting
//we can create a constructor so while defining it and giving mememorty we can give
//val=data;and next=NULL;data is provided by user and can modify next in program also

void addNode(node* &head,int value){
    node* n=new node();//node* is a pointer which is storing a memory address of node datatype created by new keyword
    n->val=value;
    n->next = NULL;//here we define n node in a memory now we have to connect it 
    if(head == NULL){
        head=n;//here we are updating head with new node so we have to pass head by referance to reflect desired changes
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;//as n is also a pointer and we have set n pointer at the atsrt
}

void printLL(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAthead(node* &head,int value){
    node* n=new node();
    n->val=value;
    n->next=head;
    head=n;
}

bool searchInLL(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->val==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void insertAtIndex(node* head,int index,int data){
    node* n=new node();
    n->val=data;
    node *prev=new node();
    if(index==0){//modification for index 0 i.e. at the start
        n->next=head;
        head=n;//here we are updating head with new node so we have to pass head by referance to reflext desired changes
        return;
    }
    prev=head;
    int i=0;
    while(i!=(index-1)){//we will traverse till previous index of desire index
        prev=prev->next;
        i++;
    }
    n->next=prev->next;
    prev->next=n;
}

int main(){

    node* head=NULL;
    addNode(head,5);
    addNode(head,8);
    addNode(head,9);
    printLL(head);
    insertAthead(head,6);
    cout<<searchInLL(head,8)<<"\n";
    insertAtIndex(head,0,2);
    printLL(head);
}