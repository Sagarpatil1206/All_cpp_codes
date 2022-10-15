#include<iostream>
#include <cmath>
#include <stack>
#include "dsaBSTheader_23258.h"

using namespace std;

void binarySearchTree::nonRecursivePreorder(node *root)
{                     //VLR rule
    stack<node *> st; //we are creating a stack of pointers to the nodes of tree
    if (root == NULL)
    {
        return;
    }
    st.push(root); //firstly push root into the stack

    while (!st.empty())
    {
        node *tempRoot = st.top();     //we are storing the pointer pointing at top
        cout << tempRoot->data << " "; //then we print it V //so we are printing element at each turn which is at the top
        st.pop();                      //then we pop it
        if (tempRoot->right)
        { //then we check for its right if yes then we push it first //R
            st.push(tempRoot->right);
        }
        if (tempRoot->left)
        {                            //then we check for its left and push it secondly //L
            st.push(tempRoot->left); //as stack follows LIFO rule thats why we first push right and then left
        }                            //and so on for each node we will push right then left and then will print left and again push things.
    }                                //if we dont have further left to push then only right will be at top and it will be printed
}

void binarySearchTree::nonRecursiveInorder(node *root)
{ //LVR
    stack<node *> st;

    node *tempRoot = root;

    while (tempRoot != NULL || !st.empty())
    { //as after going right of righmost node we get empty stack as well as its value will be NULL

        while (tempRoot != NULL)
        { //when its NULL we are leftmost end of tempRoot
            st.push(tempRoot);
            tempRoot = tempRoot->left; //L
        }                              //taking it to leftmost node while pushing all left nodes of tempRoot

        tempRoot = st.top();           //
        cout << tempRoot->data << " "; //V
        tempRoot = tempRoot->right;    //R
        st.pop();                      //popping the topmost node<T>* at top
    }
}

void binarySearchTree::nonRecursivePostorder(node *root)
{                          //for postorder traversal
    stack<node *> st, st1; //we have taken two stacks
    if (root == NULL)
    {
        return;
    }
    st.push(root); //our stratergy is to do right preorder traversal(VRL) and then reverse it using another stack

    while (!st.empty())
    {
        node *tempRoot = st.top();
        // cout<<tempRoot->data<<" ";
        st1.push(tempRoot); //pushing top element in a stack as we have to reverse
        st.pop();

        if (tempRoot->left)
        {                            //here we will push left first and then right as
            st.push(tempRoot->left); //we are following VRL here
        }
        if (tempRoot->right)
        {
            st.push(tempRoot->right);
        }
    }
    while (!st1.empty())
    { //now we will print the st1 stack with reverse of VRL
        cout << st1.top()->data << " ";
        st1.pop();
    }
}

void binarySearchTree::mirror(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

node *binarySearchTree::insertInBstRecursive(node *root, int val)
{
    //inserting first node
    if (root == nullptr)
    {
        root = new node(val);
        return root;
    }

    if (val == root->data)
    {
        cout << "Duplication is not allowed in BST." << val << " exist already in BST." << endl;
        return root;
    }

    if (val < root->data)
    {
        root->left = insertInBstRecursive(root->left, val);
    }
    else
    {
        root->right = insertInBstRecursive(root->right, val);
    }
}

node *binarySearchTree::inorderSucc(node *root)
{
    node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

node *binarySearchTree::deleteInBST(node *root, int key)
{
    if (root == nullptr)
    {
        cout << "Element not found" << endl;
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    { //key==root->data
        if (root->left == nullptr)
        {                             //so theres a right child/subtree only
            node *temp = root->right; //storing right of root that we are going to delete
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {                                                       //if node has 2 childs
            node *temp = inorderSucc(root->right);              //finding inorder succesor of the designated node
            root->data = temp->data;                            //replacing the designated node's data with its inorder succesors data
            root->right = deleteInBST(root->right, temp->data); //deleting that node with temp->data and ret
        }
    }
    return root;
}

void binarySearchTree::inorderDisplay(node *root)
{ //display by inorder
    if (root == nullptr)
    {
        return;
    }
    inorderDisplay(root->left);
    cout << root->data << " ";
    inorderDisplay(root->right);
}

int binarySearchTree::Depth(node *root)
{ //display Depth of a tree
    if (root == nullptr)
    {
        return -1;
    }
    else
    {
        return (1 + max(Depth(root->left), Depth(root->right)));
    }
}

void binarySearchTree::search(node *root, int val)
{ //searching element in a bst
    if (root == nullptr)
    {
        cout << "Key not found in the tree" << endl;
        return;
    }

    if (val < root->data)
    {
        search(root->left, val);
    }
    else if (val > root->data)
    {
        search(root->right, val);
    }
    else
    {
        cout << "Key found in the tree" << endl;
        return;
    }
}

node *binarySearchTree::insertInBSTnonRecursive(node *root, int val)
{ //insert in bst by non recursive mode
    if (root == nullptr){
        root = new node(val);
        return root;
    }

    node *p = root; //parent
    node *q = root; //child

    while (q != nullptr && val != p->data){//stop only when q becomes nullptr and given value find to be equal to parent node
        p = q; //q=nullptr when q becomes nul as no deuplicate node is found we are traversing the postions through q
        if (val < p->data)
        {
            q = p->left;
        }
        else if (val > p->data)
        {
            q = p->right;
        }
    }

    if (val == p->data){//if we find the duplicate node
        cout << "Duplicate node is not allowed ";
        return p;
    }

    if (val < p->data){//if we find the value is less than leaf node
        p->left = new node(val);
    }else{//if its greater than leaf node
        p->right = new node(val);
    }
    return root;
}

void binarySearchTree::preorder(node *root)
{ //order in recursive by preorder method
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " "; //Visit
    preorder(root->left);      //Left
    preorder(root->right);     //Right
}

void binarySearchTree::postorder(node *root)
{ //order in recursive by postorder method
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);     //Left
    postorder(root->right);    //Right
    cout << root->data << " "; //Visit
}

// function to print leaf
// nodes from left to right
void binarySearchTree::printLeafNodes(node *root)
{
    // if node is null, return
    if (root == nullptr)
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