#include<iostream>
using namespace std;
int sum(int n){
    if(n==1){return 1;}
    return n+sum(n-1);
}
int power(int n,int p){
    if(p==0){return 1;}
    return n*power(n,p-1);
}
int fact(int n){
    if(n==0){return 1;}
    return n*fact(n-1);
}
int fibo(int n){
    if(n==1){return 1;}
    if(n==0){return 0;}
    return fibo(n-1)+fibo(n-2);
}
int main(){
    cout<<sum(100)<<" ";
    cout<<power(5,3)<<" ";
    cout<<fact(6)<<" ";
    cout<<fibo(6);
}