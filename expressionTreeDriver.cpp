#include<iostream>
#include<stack>
#include "expressionTreeHeader.h"
#include "expressionTreeClass.cpp"


using namespace std;

int main(){
    binaryTreeOP<char> bt;

    // string postfix="abc-de/+*";
    cout<<"Enter the infix expression :"<<endl;
    string infix;cin>>infix;
    string postfix;
    postfix=bt.infixToPostfix(infix);
    node<char>* expTree=bt.constructExpressionTree(postfix);
    cout<<"Expression is :"<<endl;
    bt.inorder(expTree);cout<<endl;

    binaryTreeOP<int> bt1;

    node<int>* root=new node<int>(10);
    root->left=new node<int>(20);root->right=new node<int>(30);
    root->left->left=new node<int>(40);root->left->right=new node<int>(50);
    root->right->left=new node<int>(60);root->right->right=new node<int>(70);
    
    cout<<"\nBy recursive method :"<<endl;
    cout<<"Preorder : ";bt1.preorder(root);cout<<endl;//VLR
    cout<<"Postorder : ";bt1.postorder(root);cout<<endl;//LRV
    cout<<"Inorder : ";bt1.inorder(root);cout<<endl;//LVR

    cout<<"\nBy non-recursive method:"<<endl;
    cout<<"Preorder : ";bt1.nonRecursivePreorder(root);cout<<endl;
    cout<<"Inorder : ";bt1.nonRecursiveInorder(root);cout<<endl;
    cout<<"Postorder : ";bt1.nonRecursivePostorder(root);
}

// Enter the infix expression :
// a+b+(c/d*e)-f/g
// Expression is :
// (((a + b )+ ((c / d )* e ))- (f / g ))

// By recursive method :
// Preorder : 10 20 40 50 30 60 70
// Postorder : 40 50 20 60 70 30 10 
// Inorder : 40 20 50 10 60 30 70

// By non-recursive method:
// Preorder : 10 20 40 50 30 60 70 
// Inorder : 40 20 50 10 60 30 70
// Postorder : 40 50 20 60 70 30 10
// PS C:\Users\dell\Desktop\C++ programs\C++ Files> 