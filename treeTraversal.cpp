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

void preorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node* root=new node(10);
    root->left=new node(20);root->right=new node(30);
    root->left->left=new node(40);root->left->right=new node(50);
    root->right->left=new node(60);root->right->right=new node(70);
    // node* first=new node(20);
    // node* second=new node(30);
    // node* third=new node(40);
    // node* four=new node(50);
    // node* five=new node(60);
    // node* six=new node(70);
    // root->left=first;root->right=second;
    // first->left=third;first->right=four;
    // second->left=five;second->right=six;

    cout<<"Preorder : ";preorder(root);cout<<endl;//VLR
    cout<<"Postorder : ";postorder(root);cout<<endl;//LRV
    cout<<"Inorder : ";inorder(root);//LVR
}