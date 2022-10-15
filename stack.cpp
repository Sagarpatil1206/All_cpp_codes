#include<iostream>
using namespace std;
#define n 3

class stack{
    int *arr=new int[n];
    int top=-1;
    
    public:
    // stack(){
    //     arr=new int[n];
    //     top=-1;
    // }

    void push(){
        if(top==n-1){cout<<"\nStack overflow !!!";return;}
        int x;
        cout<<"Enter number to be push :";
        cin>>x;
        top++;
        arr[top]=x;
        cout<<'\n'<<x<<" is added at "<<top<<" position"<<endl;
    }

    void pop(){
        if(top==-1){cout<<"\nStack is underflow";return;}
        cout<<"Element "<<arr[top]<<" is removed"<<endl;
        top--;
    }

    void peek(){
        if(top==-1){
            cout<<"\nstack is empty ,so no element at top "<<endl;
        }
        cout<<"\nElement at top is "<<arr[top];
    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }
    bool empty(){
        if(top==-1){
            return 1;
        }else{return 0;}
    }
};
int main(){
    stack s;
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