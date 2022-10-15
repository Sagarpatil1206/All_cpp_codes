#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int main(){
    // node *root=new node();
    //This is a "new expression", not an operator. 
    //new creates a new object with dynamic storage and dynamic lifetime, that's what matters.
    //The head, second, and third variables are pointers to nodes in memory.
    //But, before you can use them, they must be pointing at a valid node in memory
    // root->data=10;
    // root->left=NULL;
    // root->right=NULL;

    // node *first=new node();
    // first->data=20;
    // first->left=NULL;
    // first->right=NULL;
    // root->left=first;

    // node *second=new node();
    // second->data=30;
    // second->left=NULL;
    // second->right=NULL;
    // root->right=second;

    node *root=new node(10);
    node *first=new node(20);
    node *second=new node(30);
    root->left=first;
    root->right=second;

    cout<<" "<<root->data<<endl;
    cout<<root->left->data<<" "<<root->right->data<<" ";
}

//Because the new keyword actually creates the object the pointer is pointing to. Without the new keyword, the pointer is uninitialized, and dereferencing it results in undefined behavior.

//Furthermore, properly-written code must always delete all objects that were instantiated with new, in order to avoid leaking memory. Not needed in this trivial example, but it's better to learn good habits early on.