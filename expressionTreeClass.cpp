#include<iostream>
#include<stack>
#include "expressionTreeHeader.h"

using namespace std;

template<class T>
bool binaryTreeOP<T>::isoperator(T c){//this function will check uf the given character is operator or not
    return (c== '+' || c== '-' || c=='*' || c=='/' || c=='^');
}

template<class T>
node<T>* binaryTreeOP<T>::constructExpressionTree(string postfix){//for constructiona expression tree from postfix operation

    stack<node<T>*> st;

    for(int i=0;i<postfix.length();i++){
        if(!isoperator(postfix[i])){//if its not a operator u.e. its a operator
            st.push(new node<T>(postfix[i]));//make a new node of that operand and push it into the stack
        }
        else{//if its a operator
            node<T>* x=st.top();
            st.pop();
            node<T>* y=st.top();
            st.pop();//pop two recent nodes from the stack also store them in x and y
            node<T>* newNode=new node<T>(postfix[i]);//make a new node of that operator
            newNode->right=x;//on right of it the uppermost node
            newNode->left=y;//on left of it 2nd from uppermost node is there
            st.push(newNode);//pushing that new node into the stack
        }
    }
    return st.top();
}

template<class T>
void binaryTreeOP<T>::inorder(node<T>* root){//for inorder traversal
    if(root==NULL){return;}
    if(isoperator(root->data)){cout<<"(";}
    inorder(root->left);//first left
    cout<<root->data<<" ";//second visit
    inorder(root->right);//third right
    if(isoperator(root->data)){cout<<")";}
}

template<class T>
void binaryTreeOP<T>::preorder(node<T>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";//Visit
    preorder(root->left);//Left
    preorder(root->right);//Right
}

template<class T>
void binaryTreeOP<T>::postorder(node<T>* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);//Left
    postorder(root->right);//Right
    cout<<root->data<<" ";//Visit
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
    st.push(root);//firstly push root into the stack

    while(!st.empty()){
        node<T>* tempRoot=st.top();//we are storing the pointer pointing at top 
        cout<<tempRoot->data<<" ";//then we print it V //so we are printing element at each turn which is at the top
        st.pop();//then we pop it
        if(tempRoot->right){//then we check for its right if yes then we push it first //R
            st.push(tempRoot->right);
        }
        if(tempRoot->left){//then we check for its left and push it secondly //L
            st.push(tempRoot->left);//as stack follows LIFO rule thats why we first push right and then left
        }//and so on for each node we will push right then left and then will print left and again push things.
    }//if we dont have further left to push then only right will be at top and it will be printed
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
void binaryTreeOP<T>::nonRecursivePostorder(node<T>* root){//for postorder traversal
    stack<node<T>*> st,st1;//we have taken two stacks
    if(root==NULL){return;}
    st.push(root);//our stratergy is to do right preorder traversal(VRL) and then reverse it using another stack

    while(!st.empty()){
        node<T>* tempRoot=st.top();
        // cout<<tempRoot->data<<" ";
        st1.push(tempRoot);//pushing top element in a stack as we have to reverse
        st.pop();

        if(tempRoot->left){//here we will push left first and then right as
            st.push(tempRoot->left);//we are following VRL here
        }
        if(tempRoot->right){
            st.push(tempRoot->right);
        }
    }
    while(!st1.empty()){//now we will print the st1 stack with reverse of VRL 
        cout<<st1.top()->data<<" ";
        st1.pop();
    }
}

template<class T>
bool binaryTreeOP<T>::validations(string str){//here we will do validations for inorder
    int checkOprand=0;int checkOptr=0;
    int checkopeB=0;int checkclosB=0;
    for(int i=0;i<str.length();i++){

        if(isalpha(str[i])){checkOprand++;}
        else if(str[i]!='(' && str[i]!=')'){
            checkOptr++;
            if(i==0 || i==(str.length()-1)){return 1;}
        }else if(str[i]=='('){
            checkopeB++;
        }else if(str[i]==')'){
            checkclosB++;
        }
    }
    if(((checkOprand-1)!=checkOptr) || (checkclosB!=checkopeB)){return 1;}else{return 0;}
}

template<class T>
int binaryTreeOP<T>::precedance(T c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

template<class T>
bool binaryTreeOP<T>::associativity(T c)
{
    if (c == '^')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

template<class T>
string binaryTreeOP<T>::infixToPostfix(string s)
{
    stack<char> st;
    if(validations(s)){return "Entered expression is INVALID";}
    string ans;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans += s[i];
            //cout<<"ans string is "<<ans<<endl;
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                //cout<<"ans string is "<<ans<<endl;
                st.pop();
            }
            st.pop();
        }
        else
        {
            
            while (!st.empty() && ((precedance(st.top()) > precedance(s[i])) ||
                                   (precedance(st.top()) == precedance(s[i]) && associativity(st.top()) && associativity(s[i]))))
            {
                ans += st.top();
                //cout<<"ans string is "<<ans<<endl;
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        //cout<<"ans string is "<<ans<<endl;
        st.pop();
    }

    return ans;
}
