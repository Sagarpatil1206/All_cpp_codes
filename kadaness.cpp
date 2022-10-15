#include<iostream>
using namespace std;
int kadan(int arr[],int n){
    int max=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>max){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }return max;
}
int main(){
    int arr[5]={-1,4,-6,7,-4};
    cout<<kadan(arr,5);
}