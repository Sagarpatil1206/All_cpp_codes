#include<bits/stdc++.h>//bits standard c++
using namespace std;
bool pytha(int a,int b,int c){int big=max(a,max(b,c));
int sum=a*a+b*b+c*c-big*big;
if(sum==(big*big)){return 1;}
return 0;}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(pytha(a,b,c)){cout<<"yes it is a pythagorian triplet";}
    else{cout<<"no it is not a pythagorian triplet";}
    return 0;}