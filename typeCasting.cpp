#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int a,cont;
    do{
    cout<<"Enter a ascii value :";
    cin>>a;
    cout<<"This is a ASCII value of :"<<char(a)<<endl;//here we typecasted int operator to get the lower char data type
    cout<<"Do you want to continue (1/0) :";//we get higher data type from lower data type if int(a)*float(b)=float(a*b);
    cin>>cont;
    }while(cont);
}