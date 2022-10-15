#include<iostream>
using namespace std;
bool isPower2(int n){
    return (n && !(n & n-1));
}
int main(){
    int n;
    cin>>n;
    if(isPower2(n)){cout<<"Given number is a power of 2";}
    else{cout<<"given number is not a power of 2";}
    return 0;
}