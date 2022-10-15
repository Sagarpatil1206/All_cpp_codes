#include<iostream>
using namespace std;
void sievePrime(int n){
    int arr[100]={0};
    for(int i=2;i<=n;i++){
        if(arr[i]==0){//just for unmarked
            for(int j=i*i;j<=n;j+=i){//from i*i as pichhle wale to already mark ho chuke honge 
                arr[j]=1;
            }
        }
    }for(int i=2;i<=n;i++){
        if(arr[i]==0){cout<<i<<" ";}
    }
}
int main(){
  int n;
  cin>>n;
  sievePrime(n);
}