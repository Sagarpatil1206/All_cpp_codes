#include<iostream>
using namespace std;

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }int temp1=arr[r];
    arr[r]=arr[i+1];
    arr[i+1]=temp1;
    return i+1;
}

void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}

int main(){
    int arr[9]={5,2,8,4,3,6,7,9,1};
    quicksort(arr,0,8);
    for(int i=0;i<9;i++){
        cout<<arr[i];
    }
}