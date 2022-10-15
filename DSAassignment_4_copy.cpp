#include<iostream>
#include<stack>
using namespace std;

template<class T>
struct node{
    T data;
    node<T>* left;
    node<T>* right;

    node(T val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

template<class T>
class binaryTreeOP{
    public:
   void preorder(node<T>*);
    void postorder(node<T>*);
    void inorder(node<T>*);
    bool isoperator(T);
    node<T>* constructExpressionTree(string);
    // void inorder(node<T>*);
    double evaluate(node<T>*);
    bool isLeaf(node<T>*);
    double process(string,double,double);
    void nonRecursivePreorder(node<T>*);
    void nonRecursivePostorder(node<T>*);
    void nonRecursiveInorder(node<T>*);
};

template<class T>
bool binaryTreeOP<T>::isoperator(T c){
    return (c== '+' || c== '-' || c=='*' || c=='/' || c=='^');
}

template<class T>
node<T>* binaryTreeOP<T>::constructExpressionTree(string postfix){

    stack<node<T>*> st;

    for(int i=0;i<postfix.length();i++){
        if(!isoperator(postfix[i])){
            st.push(new node<T>(postfix[i]));
        }
        else{
            node<T>* x=st.top();
            st.pop();
            node<T>* y=st.top();
            st.pop();
            node<T>* newNode=new node<T>(postfix[i]);
            newNode->right=x;
            newNode->left=y;
            
            st.push(newNode);
        }
    }
    return st.top();
}

template<class T>
void binaryTreeOP<T>::inorder(node<T>* root){
    if(root==NULL){return;}
    if(isoperator(root->data)){cout<<"(";}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    if(isoperator(root->data)){cout<<")";}
}

template<class T>
void binaryTreeOP<T>::preorder(node<T>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

template<class T>
void binaryTreeOP<T>::postorder(node<T>* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// void binaryTreeOP<T>::inorder(node<T>* root){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

template<class T>
void binaryTreeOP<T>::nonRecursivePreorder(node<T>* root){//VLR rule
    stack<node<T>*> st;//we are creating a stack of pointers to the nodes of tree
    if(root==NULL){return;}
    st.push(root);

    while(!st.empty()){///as in next iteration
        node<T>* tempRoot=st.top();//we are storing the pointer pointing at top //V
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

template<class T>
void binaryTreeOP<T>::nonRecursiveInorder(node<T>* root){//LVR
    stack<node<T>*> st;

    node<T>* tempRoot=root;

    while(tempRoot!=NULL || !st.empty()){//as after going right of righmost node we get empty stack as well as its value will be NULL
        
        while(tempRoot!=NULL){//when its NULL we are leftmost end of tempRoot
            st.push(tempRoot);
            tempRoot=tempRoot->left;//L
        }//taking it to leftmost node while pushing all left nodes of tempRoot

        tempRoot=st.top();//
        cout<<tempRoot->data<<" ";//V
        tempRoot=tempRoot->right;//R
        st.pop();//popping the topmost node<T>* at top
    }
}

template<class T>
void binaryTreeOP<T>::nonRecursivePostorder(node<T>* root){
    stack<node<T>*> st,st1;
    if(root==NULL){return;}
    st.push(root);

    while(!st.empty()){
        node<T>* tempRoot=st.top();
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
    binaryTreeOP<char> bt;
    binaryTreeOP<int> bt1;
    string postfix="abc-de/+*";
    node<char>* expTree=bt.constructExpressionTree(postfix);
    bt.inorder(expTree);cout<<endl;
    node<int>* root=new node<int>(10);
    root->left=new node<int>(20);root->right=new node<int>(30);
    root->left->left=new node<int>(40);root->left->right=new node<int>(50);
    root->right->left=new node<int>(60);root->right->right=new node<int>(70);
    cout<<"Preorder : ";bt1.preorder(root);cout<<endl;//VLR
    cout<<"Postorder : ";bt1.postorder(root);cout<<endl;//LRV
    cout<<"Inorder : ";bt1.inorder(root);cout<<endl;//LVR
    cout<<"Preorder : ";bt1.nonRecursivePreorder(root);cout<<endl;
    cout<<"Inorder : ";bt1.nonRecursiveInorder(root);cout<<endl;
    cout<<"Postorder : ";bt1.nonRecursivePostorder(root);
}
