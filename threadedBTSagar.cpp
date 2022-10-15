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
        lthread = 0;//initializing with 0
        rthread = 0;//intializing with 0
    }
};

class threadedBT
{
    node *current; // this will be the real root of the tree
    node *root;//this will be the dummy node
    int num;//no of nodes

public:
    void creat_threaded_binery_search_tree();//create tbst
    void preorder_traversal();//preorder
    void inorder_traversal();//inorder
};

void threadedBT::creat_threaded_binery_search_tree()
{
    cout << "Enter the no of Nodes to be present in your BST :";
    cin >> num;

    root->data = num;//putting number of nodes in a data field of a dummy node
    root->left=root->right=root;
    root->lthread=0;root->rthread=1;

    for (int i = 0; i < num; i++)//iterating for all nodes to add
    {
        cout << "Enter the " << i + 1 << " element : ";

        int temp;
        cin >> temp;//taking input of data of new node to be add in tbt
        node *new1 = new node(temp);//making new node having data "temp"

        if (root->left == root && root->right == root) // for the first element insertion current node insertion
        {
            current = new1;
            current->left = root;
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
                if (temp > current->data)//check if new nodes data is grater than current node
                {
                    if (current->rthread == 0)//that is there is no node on right of current
                    {
                        theright = 1;//theright=1 i.e. we have to put new node with temp data on right of current
                        theleft = 0;
                        break;
                    }
                    else // for current->rthread==1 // means there is a node at the right of the current
                    {
                        current = current->right;//else move forward
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
                new1->left = current->left;//make that new nodes left points to root as same as its previous current node
                new1->right = current;//mark new nodes inorder successor i.e. its current(prev) node
                current->left = new1;//put current-.left as new node
                current->lthread = 1;//make current's lthread as 1
            }
            if ((theleft == 0) && (theright == 1))
            {
                new1->right = current->right;//new node will point to root now as same as current's right use to be
                new1->left = current;//inorder predecor of new node will be current
                current->right = new1;//making currents right as new node
                current->rthread = 1;//make right of current as 1
            }
        }
    }
}

void threadedBT::inorder_traversal()//LVR
{
    current = root->left;
    while (current != root)
    {
        if (current->lthread == 1)
        {
            current = current->left;
        }
        else//when current->lthread == 0;
        {
            cout << current->data <<" ";
            while ((current->right != root) && (current->rthread == 0))
            {
                current = current->right;
                cout << current->data << " ";
            }
            if (current->right == root)
            {
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
        else//current->lthread == 0
        {
            cout << current->data << " ";
            while ((current->right != root) && (current->rthread == 0))
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

int main(){
    threadedBT t1;
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

/*
Enter
1->Create threaded Binery Tree
2->For Inorder Traversal
3->For Preorder Traversal
4->To Exit
->7
Enter the Proper number!
Enter
1->Create threaded Binery Tree
2->For Inorder Traversal
3->For Preorder Traversal
4->To Exit
->1
Enter the no of Nodes preasent in your BST exept dummy node :7
Enter the 1 element : 10
Enter the 2 element : 20
Enter the 3 element : 5
Enter the 4 element : 6
Enter the 5 element : 7
Enter the 6 element : 50
Enter the 7 element : 60
Enter
1->Create threaded Binery Tree
2->For Inorder Traversal
3->For Preorder Traversal
4->To Exit
->2
5 6 7 10 20 50 60 
Enter
1->Create threaded Binery Tree
2->For Inorder Traversal
3->For Preorder Traversal
4->To Exit
->3
10 5 6 7 20 50 60 
Enter
1->Create threaded Binery Tree
2->For Inorder Traversal
3->For Preorder Traversal
4->To Exit
->5
Enter the Proper number!
Enter
1->Create threaded Binery Tree
2->For Inorder Traversal
3->For Preorder Traversal
4->To Exit
->4
PS C:\Users\dell\Desktop\C++ programs\C++ Files> */