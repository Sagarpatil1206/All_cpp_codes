#include<iostream>
#include<stack>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

    // node(int val,node *l,node* r){
    //     data=val;
    //     left=l;
    //     right=r;
    // }
};

class expressionTree{
    public:
    node* constructExpressionTree(string);
    bool isoperator(char);
    void inorder(node* root);
};

bool expressionTree::isoperator(char c){
    return (c== '+' || c== '-' || c=='*' || c=='/' || c=='^');
}

node* expressionTree::constructExpressionTree(string postfix){

    stack<node*> st;

    for(int i=0;i<postfix.length();i++){
        if(!isoperator(postfix[i])){
            st.push(new node(postfix[i]));
        }
        else{
            node* x=st.top();
            st.pop();
            node* y=st.top();
            st.pop();
            node* newNode=new node(postfix[i]);
            newNode->right=x;
            newNode->left=y;
            
            st.push(newNode);
        }
    }
    return st.top();
}

void expressionTree::inorder(node* root){
    if(root==NULL){return;}
    if(isoperator(root->data)){cout<<"(";}
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    if(isoperator(root->data)){cout<<")";}
}

int main(){
    expressionTree et;
    string postfix="abc-de/+*";
    node *expTree=et.constructExpressionTree(postfix);
    et.inorder(expTree);
}