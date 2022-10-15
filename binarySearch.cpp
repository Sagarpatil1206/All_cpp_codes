
#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        int s=0;//s and e are starting and ending indices
        int e=n;
        while(s<=e){
            int mid=(s+e)/2;//defining mid index
            if(arr[mid]==key){return mid;}
            else if(arr[mid]>key){
                e=mid-1; 
            }
            else{ s=mid+1;}
        }
    }return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<binarySearch(arr,n,key)<<endl;
}