#include<iostream>
using namespace std;
int findDigits(int n){
    int ans=0;
    int temp=n;
    while(n){
        int ld=0;
        ld=n%10;
        if(temp%ld==0){
            ans++;
        }n=n/10;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cout<<findDigits(arr[i]);
    }
}