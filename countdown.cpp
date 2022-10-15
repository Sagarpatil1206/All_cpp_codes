#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i;
    for(int i=n;i>=1;i--){cout<<i<<endl;
    if(i%5==0){cout<<"beep"<<endl;}}
    return 0;
}