#include<iostream>
#include<climits>
using namespace std;
int kadane(int arr[],int n){
    int maxSum=INT_MIN;
    int currentSum=0;
    for(int i=0;i<n;i++){
        currentSum=currentSum+arr[i];
        if(currentSum<0){
            currentSum=0;
        }
        maxSum=max(maxSum,currentSum);
    }return maxSum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }
    int wrapsum=0;
    int nonwrapsum=kadane(arr,n);
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
        arr[i]=-arr[i];//
    }
    wrapsum=totalsum+kadane(arr,n);
    cout<<max(wrapsum,nonwrapsum)<<endl;
    return 0; 
}