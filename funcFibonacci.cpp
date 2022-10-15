#include<iostream>
using namespace std;
int fib(int n){
    int n1=0;
    int n2=1;
    int next;
   for(int i=1;i<=n;i++){
    cout<<n1<<endl;
    next=n1+n2;
    n1=n2;
    n2=next;}
    }
int main(){
    int a;
    cin>>a;
    fib(a);
    return 0;
}