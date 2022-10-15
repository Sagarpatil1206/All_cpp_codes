#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

int main(){
    node *root;
    root->data=10;
    root->left=NULL;
    root->right=NULL;

    node *first;
    first->data=20;
    first->left=NULL;
    first->right=NULL;
    root->left=first;

    node *second;
    second->data=30;
    second->left=NULL;
    second->right=NULL;
    root->right=second;

    cout<<'\t'<<root->data<<endl;
    cout<<root->left->data<<" "<<root->right->data<<" ";
}