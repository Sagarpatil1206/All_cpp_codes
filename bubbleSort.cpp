#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){bool swap=false;//it will for n-1 times and index n-2 as n-1(index) will swap with n-2
    for(int j=0;j<n-i-1;j++){if(arr[j]>arr[j+1]){//for comparisons in each pass
        int temp=arr[j];//swap
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        swap=true;
        cout<<"runs"<<j<<"time"<<endl;    }}
    if(!swap){break;}
}for(int j=0;j<n;j++){cout<<arr[j]<<" ";}//take i or j doesnt matter
}