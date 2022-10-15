#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){if(arr[j]<arr[i]){//starts with i+1 as earlier array is already sorted
            int temp=arr[i];//swap
            arr[i]=arr[j];
            arr[j]=temp;}
        }
    }
        for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}//selection sort=find the minimum element in unsorted array and swap it with element at beginning of same.