#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }int ans=INT_MIN;
    for(int i=0;i<n;i++){int sum=0;
        for(int j=i;j<n;j++){sum=sum+arr[j];
        cout<<sum<<" ";
        ans=max(sum,ans);}
        cout<<endl;
    }cout<<ans<<endl;
}