#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];}

    int maxSum=INT_MIN;
    int currentSum=0;//initializing the mx for taking max of sums
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        if(currentSum<0){currentSum=0;}
        else{maxSum=max(maxSum,currentSum);}
       }cout<<maxSum<<endl;
       return 0;
    }