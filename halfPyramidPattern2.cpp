#include<iostream>
#incldue<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    //for(int i=1;i<=n;i++){for(int j=1;j<=(n-i);j++){cout<<" ";}
    //for(int j=i;j>=1;j--){cout<<"*";}
    //cout<<endl;}
    for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){
        if(j<=(n-i)){cout<<" ";}
        else{cout<<"*";}}
        cout<<endl;
    }
    return 0;
}