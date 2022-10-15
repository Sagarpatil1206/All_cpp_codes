#include<iostream>
#include<stack>

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

void nonRecursivePreorder(node* root){//VLR rule
    stack<node*> st;//we are creating a stack of pointers to the nodes of tree
    if(root==NULL){return;}
    st.push(root);

    while(!st.empty()){///as in next iteration
        node* tempRoot=st.top();//we are storing the pointer pointing at top //V
        cout<<tempRoot->data<<" ";//then we print it //so we are printing element at each turn which is at the top
        st.pop();//then we pop it
        if(tempRoot->right){//then we check for its right if yes then we push it first //R
            st.push(tempRoot->right);
        }
        if(tempRoot->left){//then we check for its left and push it secondly //L
            st.push(tempRoot->left);//as stack fpllows LIFO rule
        }
    }
}

void nonRecursiveInorder(node* root){//LVR
    stack<node*> st;

    node* tempRoot=root;

    while(tempRoot!=NULL || !st.empty()){//as after going right of righmost node we get empty stack as well as its value will be NULL
        
        while(tempRoot!=NULL){//when its NULL we are leftmost end of tempRoot
            st.push(tempRoot);
            tempRoot=tempRoot->left;//L
        }//taking it to leftmost node while pushing all left nodes of tempRoot

        tempRoot=st.top();//
        cout<<tempRoot->data<<" ";//V
        tempRoot=tempRoot->right;//R
        st.pop();//popping the topmost node* at top
    }
}

void nonRecursivePostorder(node* root){
    stack<node*> st,st1;
    if(root==NULL){return;}
    st.push(root);

    while(!st.empty()){
        node* tempRoot=st.top();
        // cout<<tempRoot->data<<" ";
        st1.push(tempRoot);
        st.pop();

        if(tempRoot->left){
            st.push(tempRoot->left);
        }
        if(tempRoot->right){
            st.push(tempRoot->right);
        }
    }
    while(!st1.empty()){
        cout<<st1.top()->data<<" ";
        st1.pop();
    }
}

int main(){
    node* root=new node(10);
    root->left=new node(20);root->right=new node(30);
    root->left->left=new node(40);root->left->right=new node(50);
    root->right->left=new node(60);root->right->right=new node(70);
    nonRecursivePreorder(root);cout<<endl;
    nonRecursiveInorder(root);cout<<endl;
    nonRecursivePostorder(root);
}