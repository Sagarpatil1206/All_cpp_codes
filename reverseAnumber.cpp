#include<iostream>
//#include<math.h>
using namespace std;
int main(){
int n;
cin>>n;
int reverse=0;
int originaln=n;
while(n!=0){
    int lastdigit=n%10;
    reverse=reverse*10 +lastdigit;
    n=n/10;}
    cout<<reverse<<endl;
   //cout<<pow(originaln,3)<<endl;
   //cout<<sizeof(5.211l)<<endl;
    return 0;
}