#include<iostream>
using namespace std;
int main(){
    int var=50;
    int *p;//asterisk used to declare pointer 
    p=&var;// OR int *p=&var;

    cout<<var<<endl;//outputs var's value i.e. 50
    cout<<p<<endl;//output address(memory location) of var here i.e. 0x61ff08
    cout<<*p<<endl;//here asterisk used as a dereferance operator
    //output will be value store at pointer p i.e. 50
    *p=20;
    cout<<var<<endl;//outputs var's value i.e. 50
    cout<<p<<endl;//output address(memory location) of var here i.e. 0x61ff08
    cout<<*p<<endl;
    
}//therefore other than declaration we used * as a dereferance operator