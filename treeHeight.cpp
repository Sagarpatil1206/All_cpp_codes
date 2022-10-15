#include<iostream>
#include<cmath>
#include<algorithm>
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

int height(node* root){
    if(root==NULL){return -1;}//as for null we dont have to count we had donw it so we ae subracting it and we are counting from 0
    else{//so it has to be 0 for tree with only 1 node
        return (1+max(height(root->left),height(root->right)));
    }
}

int main(){
    node* root=new node(10);
    root->left=new node(20);root->right=new node(30);
    root->left->left=new node(40);root->left->right=new node(50);
    root->right->left=new node(60);root->right->right=new node(70);
    cout<<height(root);
}