#include<iostream>
using namespace std;
int factorial(int x){//defining a function name factorial
    if(x==0){return 1;}
    else{return x*factorial(x-1);}
}
int main(){int a;
cout<<"enter a number:";
    cin>>a;
    cout<<factorial(a)<<endl;
    return 0;
}