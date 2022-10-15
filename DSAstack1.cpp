#include<iostream>
#include "stack_implementations.cpp"
using namespace std;
#define n 3





int main(){
    stack<char> s;
    int op,cont;
    
    do{
        cout<<"1.Push\t"<<"2.Pop\t"<<"3.Peek\t"<<"4.Display\t"<<"5.Empty\t"<<endl;
        cin>>op;
        switch(op){
            case 1:
            s.push();
            break;
            case 2:
            s.pop();
            break;
            case 3:
            s.peek();
            break;
            case 4:
            s.display();
            break;
            case 5:
            cout<<s.empty();
            break;
        }
        cout<<"Do you want to continue (1/0)"<<endl;
        cin>>cont;
    }while(cont);
}