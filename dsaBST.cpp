#include<iostream>
#include<cmath>
#include<stack>

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

class binarySearchTree{
    public:
    node* insertInBstRecursive(node* root,int val);
    node* inorderSucc(node* root);
    node* deleteInBST(node* root,int key);
    void inorderDisplay(node* root);
    int height(node* root);//op
    void search(node* root,int val);
    node* insertInBSTnonRecursive(node* root,int val);
    void mirror(node* root);//op
    void preorder(node*);
    void postorder(node*);
    void nonRecursivePreorder(node*);
    void nonRecursivePostorder(node*);
    void nonRecursiveInorder(node*);
    void printLeafNodes(node *root);//op
};


void binarySearchTree::nonRecursivePreorder(node* root){//VLR rule
    stack<node*> st;//we are creating a stack of pointers to the nodes of tree
    if(root==NULL){return;}
    st.push(root);//firstly push root into the stack

    while(!st.empty()){
        node* tempRoot=st.top();//we are storing the pointer pointing at top 
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

void binarySearchTree::nonRecursiveInorder(node* root){//LVR
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
        st.pop();//popping the topmost node<T>* at top
    }
}

void binarySearchTree::nonRecursivePostorder(node* root){//for postorder traversal
    stack<node*> st,st1;//we have taken two stacks
    if(root==NULL){return;}
    st.push(root);//our stratergy is to do right preorder traversal(VRL) and then reverse it using another stack

    while(!st.empty()){
        node* tempRoot=st.top();
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

void binarySearchTree::mirror(node* root){
    if(root==nullptr){
        return;
    }
    mirror(root->left);
    mirror(root->right);

    node *temp=root->left;
    root->left=root->right;
    root->right=temp;

}

node* binarySearchTree::insertInBstRecursive(node* root,int val){
//inserting first node
    if(root==nullptr){
        root=new node(val);
        return root;
    }

    if(val==root->data){
        cout<<"Duplication is not allowed in BST."<<val<<" exist already in BST."<<endl;
        return root;
    }

    if(val<root->data){
        root->left=insertInBstRecursive(root->left,val);
    }else{
        root->right=insertInBstRecursive(root->right,val);
    }
    
}

node* binarySearchTree::inorderSucc(node* root){
    node* current=root;
    while(current && current->left!=NULL){
        current=current->left;
    }
    return current; 
}

node* binarySearchTree::deleteInBST(node* root,int key){
    if(root==nullptr){
        cout<<"Element not found"<<endl;
        return root;
    }

    if(key<root->data){
        root->left=deleteInBST(root->left,key);
    }else if(key>root->data){
        root->right=deleteInBST(root->right,key);
    }else{//key==root->data
        if(root->left==nullptr){//so theres a right child/subtree only
            node* temp=root->right;//storing right of root that we are going to delete
            free(root);
            return temp;
        }else if(root->right==nullptr){
            node* temp=root->left;
            free(root);
            return temp;
        }else{//if node has 2 childs
            node* temp=inorderSucc(root->right);//finding inorder succesor of the designated node
            root->data=temp->data;//replacing the designated node's data with its inorder succesors data
            root->right=deleteInBST(root->right,temp->data);//deleting that node with temp->data and ret
        }
    }
    return root;
}

void binarySearchTree::inorderDisplay(node* root){//display by inorder
    if(root==nullptr){
        return;
    }
    inorderDisplay(root->left);
    cout<<root->data<<" ";
    inorderDisplay(root->right);
}

int binarySearchTree::height(node* root){//display height of a tree
    if(root==nullptr){
        return -1;
    }
    else{
        return (1+max(height(root->left),height(root->right)));
    }
}

void binarySearchTree::search(node* root,int val){//searching element in a bst
    if(root==nullptr){
        cout<<"Key not found in the tree"<<endl;
        return;
    }
    
    if(val<root->data){
        search(root->left,val);
    }else if(val>root->data){
        search(root->right,val);
    }else{
        cout<<"Key found in the tree"<<endl;
        return;
    }
}

node* binarySearchTree::insertInBSTnonRecursive(node* root,int val){//insert in bst by non recursive mode
    if(root==nullptr){
        root=new node(val);
        return root;
    }
     node*p=root;
     node*q=root;

     while(q!=nullptr && val!=p->data){
        p=q;
        if(val<p->data){
             q=p->left;
        }else if(val>p->data){
             q=p->right;
         }
    }

     if(val==p->data){
             cout<<"Duplicate node is not allowed ";
             return p;
    }
     if(val<p->data){
         p->left=new node(val);
     }else{
         p->right=new node(val);
     }
     return root;
}

void binarySearchTree::preorder(node* root){//order in recursive by preorder method 
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";//Visit
    preorder(root->left);//Left
    preorder(root->right);//Right
}

void binarySearchTree::postorder(node* root){//order in recursive by postorder method 
    if(root==NULL){
        return;
    }
    postorder(root->left);//Left
    postorder(root->right);//Right
    cout<<root->data<<" ";//Visit
}

// function to print leaf
// nodes from left to right
void binarySearchTree::printLeafNodes(node *root){
    // if node is null, return
    if (root==nullptr)
        return;
     
    // if node is leaf node, print its data   
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
 
    // if left child exists, check for leaf
    // recursively
    if (root->left)
       printLeafNodes(root->left);
         
    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes(root->right);
}

// void binaryTreeOP<T>::inorder(node<T>* root){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

int main(){
    binarySearchTree bst;
    int arr[6]={5,1,3,4,6,7};
    node* root=nullptr;
    root=bst.insertInBstRecursive(root,arr[0]);
    // cout<<root->data;

    for(int i=1;i<6;i++){
        bst.insertInBSTnonRecursive(root,arr[i]);
        cout<<"Key inserted is :"<<arr[i];
        cout<<endl;
    }

    cout<<"Inorder display is :";bst.inorderDisplay(root);cout<<endl;
    cout<<"Deleted 7 in a bst.";bst.deleteInBST(root,7);cout<<endl;
    cout<<"Inorder display is :";bst.inorderDisplay(root);cout<<endl;
    cout<<"Searching 2 in a bst :";bst.search(root,2);cout<<endl;
    cout<<"Height of a tree is :"<<bst.height(root);cout<<endl;
    bst.mirror(root);cout<<endl;
    cout<<"Inorder display of mirror copy of bst is :";bst.inorderDisplay(root);cout<<endl;
    cout<<"Leaf nodes of a tree are :";bst.printLeafNodes(root);cout<<endl;
}

// PS C:\Users\dell\Desktop\C++ programs\C++ Files> cd "c:\Users\dell\Desktop\C++ programs\C++ Files\" ; if ($?) { g++ dsaBST.cpp -o dsaBST } ; if ($?) { .\dsaBST }
// Key inserted is :1
// Key inserted is :3
// Key inserted is :4
// Key inserted is :6
// Key inserted is :7
// Inorder display is :1 3 4 5 6 7
// Deleted 7 in a bst.
// Inorder display is :1 3 4 5 6
// Searching 2 in a bst :Key not found in the tree

// Height of a tree is :3

// Inorder display of mirror copy of bst is :6 5 4 3 1
// Leaf nodes of a tree are :6 4
// PS C:\Users\dell\Desktop\C++ programs\C++ Files>