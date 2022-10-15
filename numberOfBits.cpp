#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    while(n){//we are doing this operation till all bits get unset
        n=n & n-1;//here rightmost bit of n gets unset
        ans++;
    }
 cout<<ans;
}