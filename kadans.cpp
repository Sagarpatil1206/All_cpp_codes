#include<iostream>
#include<climits>
using namespace std;
int kadane(int arr[],int n){
    int currentSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        currentSum+=arr[i];
        if(currentSum<0){
            currentSum=0;
        }
        if(currentSum>maxSum){
            maxSum=currentSum;
        }
    }
    return maxSum;
}
int main(){
    int arr[6]={10,20,30,40,-40,90};
    cout<<kadane(arr,6);
}