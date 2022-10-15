#include<iostream>
#define maxSize 100
using namespace std;

void heapify(int arr[],int n){//top down

    int i=1;
    int larger=i;
    int left=2*i;
    int right=2*i+1;

    while(n>1){
        if(left<n && arr[left]>arr[i]){
        larger=left;
        }
        
        if(right<n && arr[right]>arr[i]){
        larger=right;
        }
        if(larger!=i){
        swap(arr[i],arr[larger]);
        }
    }
}

void deleteRoot(int arr[],int n){
    swap(arr[1],arr[n]);
    n=n-1;//decreasing the size of a heap by 1;
    heapify(arr,n);
}

int main(){
    int arr[maxSize]={0};
    int n;
    cout<<"Enter number of nodes to be inserted in heap :";
    cin>>n;
    arr[0]=n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    deleteRoot(arr,n);

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}