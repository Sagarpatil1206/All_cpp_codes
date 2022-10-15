#include <iostream>
// Threaded binery Search tree
using namespace std;

template <typename T>
class Tree;

template <typename N>
class Node
{
    N info;
    Node<N> *left;
    Node<N> *right;
    int lbit;
    int rbit;

public:
    Node()
    {
        lbit = 0; // this implement that left side is indicating the thread
        rbit = 0; // this implement that right side is indicating the thread
        // if it is 1 it implement the another Node
        left = this;  //this will always give the adress of same object
        right = this; // this implies that left and right of our new node will always implies it self
    }
    template <typename T>
    friend class Tree;
};

template <typename T>
class Tree
{                     // in this graph the root is the dummy node that we we creat which does not stores any thing
    Node<T> *current; // this will be the real root of the tree
    Node<T> *root;
    int num; //length
public:
    Tree()
    {
        Node<T> *d = new Node<T>;
        root = d;
    }
    void creat_threaded_binery_search_tree()
    {
        cout << "Enter the no of Nodes preasent in your BST exept dummy node :";
        cin >> num;
        root->info = num;
        for (int i = 0; i < num; i++)
        {
            cout << "Enter the " << i + 1 << " element : ";
            T temp;
            cin >> temp;
            Node<T> *new1 = new Node<T>;
            new1->info = temp;
            if (root->left == root) // for the first element insertion
            {

                current = new1;
                current->left = root->left;
                root->left = current;
                root->lbit = 1; // means its left is now having a node to it
                current->right = root;
            }
            else
            {
                bool theleft = 0;
                bool theright = 0;
                current = root->left;
                while (1) // after this while loop we will get the currect position of the current and in where it is going to insert the new1node means  left or right of the current
                {
                    if (temp > current->info)
                    {
                        if (current->rbit == 0)
                        {
                            theright = 1;
                            theleft = 0;
                            break;
                        }
                        else // for current->rbit==1 // means there is a node at the right of the current
                        {
                            current = current->right;
                        }
                    }
                    else // for temp<current->info
                    {
                        if (current->lbit == 0)
                        {
                            theright = 0;
                            theleft = 1;
                            break;
                        }
                        else // for current->rbit==1 // means there is a node at the right of the current
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
                    current->lbit = 1;
                }
                if ((theleft == 0) && (theright == 1))
                {
                    new1->right = current->right;
                    new1->left = current;
                    current->right = new1;
                    current->rbit = 1;
                }
            }
        }
    }

    void inorder_traversal()
    {
        current = root->left;
        while (current != root)
        {
            if (current->lbit == 1)
            {
                current = current->left;
            }
            else
            {
                cout << current->info << " ";
                while ((current->right != root) && (current->rbit != 1))
                {
                    current = current->right;
                    cout << current->info << " ";
                }
                if (current->right == root)
                {
                    //cout<<current->info; // this is the creatical case please debuge the while loop of the line 123 cearfully
                    break;
                }
                else // when current->rbit==1
                {
                    current = current->right;
                }
            }
        }
        cout << endl;
    }

    void preorder_traversal()
    {
        current = root->left;
        while (current != root)
        {
            if (current->lbit == 1)
            {
                cout << current->info << " ";
                current = current->left;
            }
            else
            {
                cout << current->info << " ";
                while ((current->right != root) && (current->rbit != 1))
                {
                    current = current->right;
                }
                if (current->right == root)
                {
                    //cout<<current->info; // this is the creatical case please debuge the while loop of the line 123 cearfully
                    break;
                }
                else // when current->rbit==1
                {
                    current = current->right;
                }
            }
        }
        cout << endl;
    }

    // postorder traversal is not there in the TBT
};

int main()
{
    Tree<int> t1;
    while (1)
    {
        cout << "Enter\n1->Create threaded Binery Tree\n2->For Inorder Traversal\n3->For Preorder Traversal\n4->To Exit\n->";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case (1):
        {
            t1.creat_threaded_binery_search_tree();
            break;
        }
        case (2):
        {
            t1.inorder_traversal();
            break;
        }
        case (3):
        {
            t1.preorder_traversal();
            break;
        }
        case (4):
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Enter the Proper number!" << endl;
        }
        }
    }

    return 0;
}