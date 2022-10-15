#include<iostream>
using namespace std;
bool isPowerof2(int n){
    if(!(n & (n-1))){
        return true;
    }else{return false;}
}
int main(){
    int n;
    if(isPowerof2(n)){cout<<"Yes";}
}