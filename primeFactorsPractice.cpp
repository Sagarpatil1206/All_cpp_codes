#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    // int arr[n];
    for(int i=2;i<=n;i++){
        while(n%i==0){ 
            cout<<i<<" ";
            n=n/i;
        }
    }
    // for(int i=2;i<n;i++){
    //     for(int j=2;j<n;j++){
    //         if(i%j==0){
    //             arr[i]=j;
    //             break;
    //         }
    //     }
    // }
    // while(n!=1){
    //     cout<<arr[n];
    //     n=n/arr[n];
    // }
    return 0;
}