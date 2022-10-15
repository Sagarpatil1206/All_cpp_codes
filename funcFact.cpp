#include<iostream>
using namespace std;
int fact(int n){
    int a=1;
    for(int i=2;i<=n;i++){a=a*i;}
   return a;//return outside as any first 'return' strikes..
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}