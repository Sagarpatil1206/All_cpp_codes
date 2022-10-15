#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n>=0){int y=n%10;//
              int z=n/10;//
              if(y==z){cout<<"0";break;}
              else{cout<<"1";break;}}
    return 0;
}
