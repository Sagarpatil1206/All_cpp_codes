#include<iostream>
#include "threadedBTHeader.h"
using namespace std;

void threadedBT::creat_threaded_binery_search_tree()
{
    cout << "Enter the no of Nodes to be present in your BST :";
    cin >> num;
    root->data = num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the " << i + 1 << " element : ";
        int temp;
        cin >> temp;
        node *new1 = new node(temp);
        if (root->left == root) // for the first element insertion
        {

            current = new1;
            current->left = root->left;
            root->left = current;
            root->lthread = 1; // means its left is now having a node to it
            current->right = root;
        }
        else
        {
            bool theleft = 0;
            bool theright = 0;
            current = root->left;
            while (1) // after this while loop we will get the currect position of the current and in where it is going to insert the new1node means  left or right of the current
            {
                if (temp > current->data)
                {
                    if (current->rthread == 0)
                    {
                        theright = 1;
                        theleft = 0;
                        break;
                    }
                    else // for current->rthread==1 // means there is a node at the right of the current
                    {
                        current = current->right;
                    }
                }
                else // for temp<current->data
                {
                    if (current->lthread == 0)
                    {
                        theright = 0;
                        theleft = 1;
                        break;
                    }
                    else // for current->rthread==1 // means there is a node at the right of the current
                    {
                        current = current->left;
                    }
                }
            }
            if ((theleft == 1) && (theright == 0)) // this implies that we have to insert the new1 node to the left of the current and it isthe left node
            {
                new1->left = current->left;
                new1->right = current;
                current->left = new1;
                current->lthread = 1;
            }
            if ((theleft == 0) && (theright == 1))
            {
                new1->right = current->right;
                new1->left = current;
                current->right = new1;
                current->rthread = 1;
            }
        }
    }
}

void threadedBT::inorder_traversal()
{
    current = root->left;
    while (current != root)
    {
        if (current->lthread == 1)
        {
            current = current->left;
        }
        else
        {
            cout << current->data << " ";
            while ((current->right != root) && (current->rthread != 1))
            {
                current = current->right;
                cout << current->data << " ";
            }
            if (current->right == root)
            {
                //cout<<current->data; // this is the creatical case please debuge the while loop of the line 123 cearfully
                break;
            }
            else // when current->rthread==1
            {
                current = current->right;
            }
        }
    }
    cout << endl;
}

void threadedBT::preorder_traversal()
{
    current = root->left;
    while (current != root)
    {
        if (current->lthread == 1)
        {
            cout << current->data << " ";
            current = current->left;
        }
        else
        {
            cout << current->data << " ";
            while ((current->right != root) && (current->rthread != 1))
            {
                current = current->right;
            }
            if (current->right == root)
            {
                //cout<<current->data; // this is the creatical case please debuge the while loop of the line 123 cearfully
                break;
            }
            else // when current->rthread==1
            {
                current = current->right;
            }
        }
    }
    cout << endl;
}