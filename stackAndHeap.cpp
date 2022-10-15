#include<iostream>
using namespace std;
int main(){
    int a=10;//stored in stack
    cout<<a<<endl;
    int *p=new int();//we allote memory for int int heap
    *p=20;//giving valur
    cout<<p<<" "<<*p;
    delete(p);//deallocating memory
    p=new int[4];
    delete[]p;
    p=NULL;//here we remove dangling pointer
}