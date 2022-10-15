#include<iostream>
using namespace std;
bool isPowerof2(int n){
    if(!(n & (n-1))){//as n and n-1 in binary have diff bits diff at same index
        return true;
    } else{return false;} //or just return !(n & n-1) as it will be false as & gives 1;
}
int main(){
    int n;
    cin>>n;
    if(isPowerof2(n)){cout<<"Yes";}
    else{cout<<"No";}
}