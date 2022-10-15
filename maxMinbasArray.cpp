#include<iostream>
using namespace std;
int addition(int a,int b){
return a+b;
}
int mul(int a,int b){
return a*b;
}
int main(){
    int a,b;
    cin>>a>>b;
cout<<"Addition of a and b is ==>"<<addition(a,b)<<endl;
cout<<"Subtraction of a and b is ==>"<<a-b<<endl;
cout<<"Multiplication of a and b is ==>"<<mul(a,b)<<endl;
cout<<"Division of a and b is ==>"<<a/b;
//Display subtraction, multiplication, and division of a and b
return 0;
}