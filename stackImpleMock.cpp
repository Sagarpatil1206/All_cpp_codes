#include<iostream>
#include "mock_header.h"

template <class T>
stack_LL<T>::stack_LL()//constructor of stack declaring top of it null at start
{
    top = NULL;
}

template <class T>
node<T> *stack_LL<T>::getNode(int x) //allocating memory for new LL node and passing data for node
{
    node<T> *new_ptr=new node<T>();//get a new node
    int a;
    new_ptr->data = x;//given data is set in data field of node
    new_ptr->next = NULL;//next pointer of node is set null
    return new_ptr;//returning desired node
}

template <class T>
void stack_LL<T>::push(int x)//push operartion od stack
{
    node<T> *temp;
    temp = getNode(x);//getting node with desired data to be pushed into the stack
    if (top == NULL)
    {
        top = temp;
    }
    else//by this part we are adding new node at top and pointing new node's next to previous top
    {
        temp->next = top;
        top = temp;
    }
}

template <class T>
T stack_LL<T>::pop()//for popping elemt from stack
{
    node<T> *temp;
    T element;
    if (top == NULL)
    {
        cout << "Underflow" << endl;
        return 0; 
    }
    else//
    {
        temp = top;
        top = top->next;//moving top element to its next attached element
    }//so here top element is now no more connected in our linked list and just free in a memory
    element = temp->data;//getting element that we deleted
    return element;//returning the deleted element
}

template <class T>
void stack_LL<T>::display()//for dispaying stack
{
    node<T> *temp = top;
    if (temp == NULL)
    {
        cout << "Underflow" << endl;
    }
    while (temp != NULL)//through while loop until we get last element of linked list we will print it
    {
        cout << "Data is " << temp->data << endl;
        temp = temp->next;
    }
}