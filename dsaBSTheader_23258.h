#ifndef dsaBSTheader_23258_h
#define dsaBSTheader_23258_h

#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class binarySearchTree
{
public:
    node *insertInBstRecursive(node *root, int val);
    node *inorderSucc(node *root);
    node *deleteInBST(node *root, int key);
    void inorderDisplay(node *root);
    int Depth(node *root); //op
    void search(node *root, int val);
    node *insertInBSTnonRecursive(node *root, int val);
    void mirror(node *root); //op
    void preorder(node *);
    void postorder(node *);
    void nonRecursivePreorder(node *);
    void nonRecursivePostorder(node *);
    void nonRecursiveInorder(node *);
    void printLeafNodes(node *root); //op
};
#endif