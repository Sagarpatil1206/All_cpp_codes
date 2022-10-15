#include<iostream>
using namespace std;

//stack using linked list

template <class T>
struct node{//we have created the structure of node
    T data;//data
    node *next;//next pointer
};

template<class T>
class stack_LL{
    node<T> *top;//private
    public:
    stack_LL();//constructor
    node<T> *getNode(int);//getnode for getting
    void push(int);
    T pop();
    void display();
    void peep();
};

template<class T>
stack_LL<T>::stack_LL(){
    top=NULL;
}

template <class T>
node<T> *stack_LL<T>::getNode(int x){ //allocating memory for new LL node
    node<T> *new_ptr;
    new_ptr=new node<T>();
    new_ptr->data=x;
    new_ptr->next=NULL;
    return new_ptr;
}

template <class T>
void stack_LL<T>::push(int x){
    node<T> *temp;
    temp=getNode(x);
    if(top==NULL){
        top=temp;
    }else{
        temp->next=top;
        top=temp;-
    }
}

template <class T>
T stack_LL<T>::pop(){
    node<T> *temp;
    T element;
    if(top==NULL){
        cout<<"Underflow"<<endl;
        return 0;//if T is int
    }
    else{
        temp=top;
        top=top->next;
    }
    element=temp->data;
    //free(temp);
    return element;
}

template <class T>
void stack_LL<T>::display(){
    node<T> *temp=top;
    if(temp==NULL){
        cout<<"Underflow"<<endl;
    }
    while(temp!=NULL){
        cout<<"Data is "<<temp->data<<endl;
        temp=temp->next;
    }
}

template <class T>
void stack_LL<T>::peep(){
    cout<<"Top element is "<<top->data<<endl;
}

int main(){
    stack_LL<int> ll;
    int ele;
    ll.display();
    ll.push(8);
    cout<<"After pushing 1"<<endl;
    ll.display();
    ll.push(12);
    cout<<"after pushing 2"<<endl;
    ll.display();
    ele=ll.pop();
    cout<<"After poping "<<ele<<endl;
    ll.display();
    ll.peep();
    int ele1;
    ele1=ll.pop();
    cout<<"After popping "<<ele1<<endl;
    int ele2;
    ele2=ll.pop();
    cout<<"After popping "<<ele2<<endl;
    return 0;
}