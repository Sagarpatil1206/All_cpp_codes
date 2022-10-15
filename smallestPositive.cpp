#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int N=1e5+2;
    bool check[N];
    for(int i=0;i<N;i++){
            check[i]=0;//assigning value //assigning 0 to all elements of this large array
        }
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            check[arr[i]]=1;//assigning value 1 to the positive 
            //numbers(actually index of check[]) in array.
        }
    }
    int ans=-1;
    for(int i=1;i<N;i++){
        if(check[i]==0){//checking equality// as we first strike on any index with 0 value it will be the ans.
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}