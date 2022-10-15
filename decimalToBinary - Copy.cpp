#include<iostream>
using namespace std;
int decimalToBinary(int n){
    int ans=0;
    int x=1;
    while(x>0){
       int lastdigit=n/x;
       n=n-lastdigit*x;
       x=x/2;
       ans=ans*10+lastdigit;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<decimalToBinary(n)<<endl;
    return 0;
}