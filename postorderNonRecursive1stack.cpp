#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void nonRecursivePostorder(node* root){
    
}

int main(){
    node* root=new node(10);
    root->left=new node(20);root->right=new node(30);
    root->left->left=new node(40);root->left->right=new node(50);
    root->right->left=new node(60);root->right->right=new node(70);
}