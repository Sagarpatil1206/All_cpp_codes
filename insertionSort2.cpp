#include<iostream>
using namespace std;
int main(){
    int arr[6]={6,4,9,7,3,8};
    for(int i=1;i<6;i++){
        int temp=arr[i];
        int j=i-1;
        while(arr[j]>temp && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
    arr[j+1]=temp;}
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}
