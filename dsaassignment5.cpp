/*
* Bst_header.h
*
* Created on: 22-Oct-2021
* Author: Deepali
*/

#ifndef BST_HEADER_H_
#define BST_HEADER_H_

struct BSTNode
{
    int data;
    BSTNode *Lchild;
    BSTNode *Rchild;
};
class BST
{
private:
    BSTNode *Root;

public:
    BST();
    BSTNode *getRoot();
    void setRoot(BSTNode *);
    BSTNode *createNode(int data);
    BSTNode *insertBSTRec(BSTNode *, int);
    BSTNode *insertBSTNonRec(BSTNode *, int);
    void preOrderBST(BSTNode *);
    void inOrderBST(BSTNode *);
    void postOrderBST(BSTNode *);
    void nonRecursiveInOrder(BSTNode *);
    void nonRecursivePreOrder(BSTNode *);
    void nonRecursivePostOrder(BSTNode *);
    BSTNode *MirrorBST(BSTNode *);
    int heightBST(BSTNode *);
    int nonRecHeightBST();
    void deleteItem(BSTNode *, BSTNode *, int);
    //void deleteNode(BSTNode*,BSTNode*);
    // void levelwiseBST(BSTNode*);
    void nonRecLevelwiseBST(BSTNode *);
    BSTNode *maxBST(BSTNode *);
    BSTNode *searchBST(BSTNode *, int);
    BSTNode *nonRecSearchBST(BSTNode *, int);
    void DisplayParentandChild(BSTNode *temp);
    void DisplayLeaf(BSTNode *temp);
    BSTNode *copyBST(BSTNode *temp);
};

#endif /* BST_HEADER_H_ */

/*int BST::nonRecHeightBST()
{
    ​ if (Root == NULL)
    {
        ​ return 0;
    }
    ​
        queue<BSTNode *>
            queue;
    queue.push(Root);

    int height = 0;
    int nodeCount = 0;
    BSTNode *temp;

    while (1)
    {
        ​
            // nodeCount (queue size) indicates number of nodes
            // at current level.
            nodeCount = queue.size();
        if (nodeCount == 0)
        {
            ​ return height - 1;
        }
        ​
            height++;
        while (nodeCount > 0)
        {
            ​
                temp = queue.front();
            queue.pop();
            if (temp->Lchild != NULL)
            {
                ​
                    queue.push(temp->Lchild);
            }
            ​ if (temp->Rchild != NULL)
            {
                ​
                    queue.push(temp->Rchild);
            }
            ​
                nodeCount--;
        }
        ​
    }
    ​ return height - 1;
}
*/