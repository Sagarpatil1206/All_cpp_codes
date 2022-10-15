#include<iostream>
using namespace std;
int greatest(int a,int b,int c){
    if(a>b && a>c){return a;}
    if(b>a && b>c){return b;}
    if(c>a && c>b){return c;}
}
bool pytha (int a,int b,int c){
   if(greatest(a,b,c)==a){if(a*a==b*b+c*c){return true;}else{return false;}}
   if(greatest(a,b,c)==b){if(b*b==a*a+c*c){return true;}else{return false;}}
   if(greatest(a,b,c)==c){if(c*c==a*a+b*b){return true;}else{return false;}}
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(pytha(a,b,c)){cout<<"yes it is a pythagorian triplet";}
    else{cout<<"no it is not a pythagorian triplet";}
    return 0;}