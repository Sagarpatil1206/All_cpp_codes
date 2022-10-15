#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={5,8,3,7,2,6};
    int n=sizeof(arr)/sizeof(n);
    int min=INT_MAX;int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"Max is "<<max<<" and min is "<<min<<endl;
}