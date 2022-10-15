#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool flag=0;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){cout<<n<<"is non prime";
        flag=1;
        break;}//imp step
    }
    if(flag==0){cout<<n<<" is prime";}
    return 0;
}