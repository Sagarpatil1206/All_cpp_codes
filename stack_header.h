#ifndef STACK_HEADER_H_
#define STACK_HEADER_H_

template<class T>
class stack{
    T *arr=new T[n];
    int top=-1;
    
    public:

    void push();

    void pop();

    void peek();

    void display();

    bool empty();
};

#endif
