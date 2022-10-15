#include<iostream>
#include "dsaBSTheader_23258.h"
#include "dsaBSTimplementation_23258.cpp"

using namespace std;

int main()
{
    binarySearchTree bst;
    int arr[6] = {5, 1, 3, 4, 6, 7};
    node *root = nullptr;
    root = bst.insertInBstRecursive(root, arr[0]);
    // cout<<root->data;

    for (int i = 1; i < 6; i++)
    {
        bst.insertInBSTnonRecursive(root, arr[i]);
        cout << "Key inserted is :" << arr[i];
        cout << endl;
    }

    cout << "Inorder display is :";
    bst.inorderDisplay(root);
    cout << endl;
    cout << "Deleted 7 in a bst.";
    bst.deleteInBST(root, 7);
    cout << endl;
    cout << "Inorder display is :";
    bst.inorderDisplay(root);
    cout << endl;
    cout << "Searching 2 in a bst :";
    bst.search(root, 2);
    cout << endl;
    cout << "Depth of a tree is :" << bst.Depth(root);
    cout << endl;
    bst.mirror(root);
    cout << endl;
    cout << "Inorder display of mirror copy of bst is :";
    bst.inorderDisplay(root);
    cout << endl;
    cout << "Leaf nodes of a tree are :";
    bst.printLeafNodes(root);
    cout << endl;
}

/*
Key inserted is :1
Key inserted is :3
Key inserted is :4
Key inserted is :6
Key inserted is :7
Inorder display is :1 3 4 5 6 7 
Deleted 7 in a bst.
Inorder display is :1 3 4 5 6 

Searching 2 in a bst :Key not found in the tree

Depth of a tree is :3

Inorder display of mirror copy of bst is :6 5 4 3 1
Leaf nodes of a tree are :6 4
PS C:\Users\dell\Desktop\C++ programs\C++ Files>   
*/