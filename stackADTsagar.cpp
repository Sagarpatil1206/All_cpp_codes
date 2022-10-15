#include<iostream>
#include "stack_header.h"
using namespace std;

template<class T>
void stack<T>::push(){
        if(top==n-1){cout<<"\nStack overflow !!!";return;}
        T x;
        cout<<"Enter number to be push :";
        cin>>x;
        top++;
        arr[top]=x;
        cout<<'\n'<<x<<" is added at position "<<top<<endl;
    }

template<class T>
void stack<T>::pop(){
        if(top==-1){cout<<"\nStack is underflow";return;}
        cout<<"Element "<<arr[top]<<" is removed"<<endl;
        top--;
    }

template<class T>
void stack<T>:: peek(){
        if(top==-1){
            cout<<"\nstack is empty ,so no element at top "<<endl;
        }
        cout<<"\nElement at top is "<<arr[top];
    }


template<class T>
void stack<T>:: display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }

template<class T>
bool stack<T>:: empty(){
        if(top==-1){
            return 1;
        }else{return 0;}
    }