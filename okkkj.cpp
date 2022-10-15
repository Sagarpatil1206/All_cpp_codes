#include<iostream>
using namespace std;
#define n 5

class stack_1
{
    int arr[n];
    int top=-1;;
    int size;

    public :
    stack_1();
    void push(int);
    void pop();
    void display();

};
stack_1::stack_1()
{
    // int top=-1;
    int size=5;
}
void stack_1::push(int x)
{
    if (top==n-1)
    {
        cout<<"stack is full";
        return;
    }
    top++;
    arr[top]=x;
    cout<<"the element pushed is "<<x<<endl;
}
void stack_1::pop()
{
    if(top=-1)
    {
        cout<<"stack is empty";
        return;
    }
    top--;
}
void stack_1::display()
{
    int i;
    if(top==-1)
    {
        cout<<"stack is empty";
        return;
    }
    else{
        for (i=top;i<=0;i--)
        cout<<arr[i];
    }
}
int main(){
    cout<<"hello world"<<endl;
    stack_1 s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.display();
    
}