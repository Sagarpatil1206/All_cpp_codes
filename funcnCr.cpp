#include<iostream>
using namespace std;
int fact(int n){
    int facto=1;
    for(int i=1;i<=n;i++){facto=facto*i;}
    return facto;
}
int nCr(int n,int r){
   int nCr=fact(n)/(fact(n-r)*fact(r));
    return nCr; 
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<nCr(a,b);
}