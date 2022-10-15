#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int j=2;j<=n;j++){int i;
    for(i=2;i<j;i++){
    if(j%i==0){cout<<j<<" = non prime\n";
    break;}
    }
    if(i==j){cout<<j<<" = prime"<<endl;}
    }
return 0;
}