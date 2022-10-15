#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

node* insertInBst(node* root,int val){
    if(root==nullptr){return new node(val);}
    if(val<root->data){
        root->left=insertInBst(root->left,val);
    }else{
        root->right=insertInBst(root->right,val);
    }
    return root;
}

void inorder(node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

bool search(node* root,int val){
    if(root==nullptr){return 0;}
    
    if(val<root->data){
        search(root->left,val);
    }else if(val>root->data){
        search(root->right,val);
    }else{
        return 1;
    }
}

int main(){
    int arr[6]={5,1,3,4,2,7};
    node* root=NULL;
    root=insertInBst(root,arr[0]);
    for(int i=1;i<6;i++){
        insertInBst(root,arr[i]);
    }
    inorder(root);cout<<endl;
    cout<<search(root,4);
}