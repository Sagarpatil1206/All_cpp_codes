#include<iostream>
using namespace std;
bool pairSum(int arr[],int n,int key){
    int low=0;
    int high=n-1;
    while(low<high){
        if(arr[low]+arr[high]==key){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low]+arr[high]>key){
            high--;
        }else{
            low--;
        }
    }return false;

}
int main(){
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];}
        cin>>key;
    cout<<pairSum(arr,n,key);
}