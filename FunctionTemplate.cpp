#include<iostream>
using namespace std;
template<class T>
T sum(T a,T b){
    return a+b;
}
int main(){
    int a=5,b=6;
    cout<<sum(a,b)<<endl;
    double c=5.4,d=6.5;
    cout<<sum(c,d)<<endl;
}