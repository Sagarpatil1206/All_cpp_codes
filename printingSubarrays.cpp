#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
     cin>>arr[i];
    }
    for(int i=0;i<n;i++){//for traversing over the whole array one by one
        for(int j=i;j<n;j++){//chosing j's staring and ending and goes one by one
            for(int k=i;k<=j;k++){//selecting subarray from selectes i(=j) to j as we get it one by one
                cout<<arr[k]<<" ";
            }cout<<endl;
        }
    }
}