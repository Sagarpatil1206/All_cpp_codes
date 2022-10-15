#ifndef threadedBTHeader_h
#define threadedBTHeader_h

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    bool lthread, rthread;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
        lthread = 0;
        rthread = 0;
    }
};

class threadedBT
{
    node *current; // this will be the real root of the tree
    node *root;
    int num;

public:
    void creat_threaded_binery_search_tree();
    void preorder_traversal();
    void inorder_traversal();
};

#endif 