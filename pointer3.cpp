#include<iostream>
using namespace std;
int main(){
    int a=10;
    int *p;
    p=&a;//p is a pointer declared earlier
    cout<<*p<<endl;
    int **q=&p;
    cout<<*q<<endl;
    cout<<**q<<endl;
}