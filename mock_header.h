#ifndef MOCK_HEADER_H
#define MOCK_HEADER_H

#include <iostream>
#include "stackImpleMock.cpp"
using namespace std;

template <class T>
struct node//making a node for linked list
{
    T data;//data with templated code
    node *next;//next pointer of node will store pointer to next node
};

template <class T>
class ExpressionConversion//class for expression conversion
{
public:
    stack<char> st;
    string s;
    int precedance(char);
    bool associativity(char);
    T infixToPostfix(T);
    void displayStack();
    bool validations(T);
};

template <class T>
class stack_LL//class for stack using linked list
{
    node<T> *top;//top pointer of stack declared private

public:
    stack_LL();
    node<T> *getNode(int);
    void push(int);
    T pop();
    void display();
};

#endif