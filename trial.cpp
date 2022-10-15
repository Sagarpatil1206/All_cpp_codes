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
    // int n,r;
    // cin>>n>>r;
    // cout<<nCr(n,r)<<endl;
    // return 0;
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){for(int j=0;j<=i;j++){cout<<nCr(i,j)<<" ";}
    cout<<endl;}
}