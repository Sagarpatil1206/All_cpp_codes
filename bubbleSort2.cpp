#include<iostream>
using namespace std;
int main(){
    int arr[6]={3,7,5,4,9,8};
    for(int i=0;i<(6-1);i++){
        int swapped=0;
        for(int j=0;j<(6-i-1);j++){
        if(arr[j+1]<arr[j]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            swapped=1;
        }}
        if(!swapped){break;}
    }for(int i=0;i<6;i++){
         cout<<arr[i]<<" ";
    }
}