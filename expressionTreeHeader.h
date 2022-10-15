#ifndef EXPRESSIONTREEHEADER_H
#define EXPRESSIONTREEHEADER_H
#include<iostream>

using namespace std;

template<class T>
struct node{
    T data;
    node<T>* left;
    node<T>* right;

    node(T val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

template<class T>
class binaryTreeOP{
    public:
    void preorder(node<T>*);
    void postorder(node<T>*);
    void inorder(node<T>*);
    bool isoperator(T);
    node<T>* constructExpressionTree(string);
    // void inorder(node<T>*);
    double evaluate(node<T>*);
    bool isLeaf(node<T>*);
    double process(string,double,double);
    void nonRecursivePreorder(node<T>*);
    void nonRecursivePostorder(node<T>*);
    void nonRecursiveInorder(node<T>*);
    bool validations(string str);
    int precedance(T);
    bool associativity(T c);
    string infixToPostfix(string s);
};

#endif