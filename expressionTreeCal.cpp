#include<iostream>
#include<string>
using namespace std;

struct node{
    string data;
    node* left;
    node* right;
    node(string val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

bool isLeaf(node* root){
    return ((root->left==nullptr) && (root->right==nullptr));
}

double process(string op,double x,double y){
    // switch(op){
    //     case '+':return (x+y);break;
    //     case '-':return (x-y);break;
    //     case '*':return (x*y);break;
    //     case '/':return (x/y);break;
    // }
    if(op=="+"){return x+y;}
    if(op=="-"){return x-y;}
    if(op=="x"){return x*y;}
    if(op=="/"){return x/y;}
    return 0;
}

double evaluate(node* root){
    if(root==nullptr){return 0;}
    if(isLeaf(root)){
        return stod(root->data);
    }
    double x=evaluate(root->left);
    double y=evaluate(root->right);
    
    return process(root->data,x,y);
}

int main(){
     node* root = new node("+");
    root->left = new node("x");
    root->right = new node("/");
    root->left->left = new node("-");
    root->left->right = new node("5");
    root->right->left = new node("21");
    root->right->right = new node("7");
    root->left->left->left = new node("10");
    root->left->left->right = new node("5");
 
    cout << "The value of the expression tree is " << evaluate(root) << endl;
 
    return 0;
}