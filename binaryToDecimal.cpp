#include<iostream>
using namespace std;
int binaryTodecimal(int n){
    int ans=0;
    int x=1;
    // while(n!=0){
    //     int y=n%10;
    //     ans=ans+ x*y;
    //     x=x*2;
    //     n=n/10;
    // }return ans;
    while(n>0){
        int lastdigit=n%10;
        ans+=lastdigit*x;
        x*=2;
        n=n/10;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter binary number :";
    cin>>n;
    cout<<"Ans is :"<<binaryTodecimal(n)<<endl;
}