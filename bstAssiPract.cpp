#include<iostream>
#include <cmath>
#include <stack>
#include "dsaBSTheader_23258.h"

using namespace std;

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

node *binarySearchTree::inorderSucc(node *root)
{
    node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
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