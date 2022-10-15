#include<iostream>
#include "threadedBTCLass.cpp"
#include "threadedBTHeader.h"
using namespace std;

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