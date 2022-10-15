#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){//just upto <n as n is not included in index
        if(arr[i]==key){
            return i;}
    }return -1;
}
int main(){
    int n;
    cout<<"Enter size of an array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter key";
    int key;
    cin>>key;
    cout<<"index of entered key is "<<linearSearch(arr,n,key)<<endl;
}