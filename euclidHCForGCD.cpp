#include<iostream>
using namespace std;
int euclid(int a,int b){
    while(b!=0){int c=a%b;
    a=b;
    b=c;}
    return a;
}
int main(){
    cout<<euclid(24,42)<<" ";
    //if initially a<b then after first modulo operation c=b's value (as a%b will be b then) and
    //a's value will be b's value that is bigger value in this case so new pair will be
    //corrected pair with (bigger,smaller)
}