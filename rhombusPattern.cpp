#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){for(int j=1;j<=(n-i);j++){cout<<" ";}
    for(int k=1;k<=n;k++){cout<<"*";}//after excusion of first statement 2nd will execute
    cout<<endl;}
    return 0;
}