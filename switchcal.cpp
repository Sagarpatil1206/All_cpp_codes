//switch cases calculator
#include<iostream>
using namespace std;
int main(){
    int num1,num2;
    cout<<"Enter two numbers :";
    cin>>num1>>num2;
    int n;
    do{char op;
    cout<<"Enter the operation :";
    cin>>op;
    switch(op){
        case '+':
        cout<<num1+num2;
        break;
        case '-':
        cout<<num1-num2;
        break;
        case '*':
        cout<<num1*num2;
        break;
        case '/':
        if(num2!=0){cout<<num1/num2;}
        else{cout<<"Division by 0 is not possible";}
        break;
        default:
        cout<<"Enter valid operation";
        int n;
       cin>>n;
    }
    cout<<"do you want to continue(1/0";
    cin>>>n;
    while(n==1);
}
}