#include<iostream>
using namespace std;
void divisible(int n,int div1,int div2){
    int c1=n/div1;
    int c2=n/div2;
    int c3=n/(div1*div2);
    cout<<c1+c2-c3;
}
int main(){
    // int count=0;
    // for(int i=1;i<=40;i++){
    //     if(i%5==0){count++;}
    //     if(i%7==0){count++;}
    //     if(i%35==0){count--;}
    // }cout<<count;
    divisible(40,5,7);
}