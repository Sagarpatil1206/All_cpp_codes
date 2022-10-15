#include<iostream>
using namespace std;
int gcd(int a,int b){//gcd= sabse bada common factor
    while(b!=0){
       int rem=a%b;
       a=b;
       b=rem;
    }
    return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(24,18);
    cout<<gcd(a,b);
}