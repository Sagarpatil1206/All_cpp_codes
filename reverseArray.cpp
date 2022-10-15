#include<iostream>
using namespace std;

void reverseArray(int arr[],int n){
  int start=0;int end=n-1;
  while(start<end){
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++;end--;
  }
}

int main(){
  int arr[]={1,2,5,8,9};
  int n=sizeof(arr)/sizeof(arr[0]);
  reverseArray(arr,n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
  }
}