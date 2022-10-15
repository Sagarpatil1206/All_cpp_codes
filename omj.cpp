#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int arr[m];
        for(int j=0;j<m;j++){
            cin>>arr[i];
        }
        for(int j=0;j<m;j++){
            int sum1=0;
            int sum=0;
            while(j<i){
                sum+=arr[j];
            }
            while(j>i){
                sum1+=arr[j];
            }
            if(sum==sum1){
                cout<<"YES";
            }else{cout<<"NO";}
        }
    }
}