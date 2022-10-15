#ifndef STACKADT_H_
#define STACKADT_H_
template <typename T>
struct Node
{
    T symbol;
    Node<T> *next;
};
template <class T>
class StackAdt
{
    Node<T> *top;

public:
    StackAdt();
    bool isEmpty();
    void push(T);
    T pop();
    T peep();
    void display();
    ~StackAdt();
};
#endif