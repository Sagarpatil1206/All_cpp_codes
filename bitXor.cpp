#include<iostream>
using namespace std;
int unique(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            else{if(arr[i]^arr[j]){
                continue;
            }if(!(arr[i]^arr[n])){return arr[i];}
            }
        }
    }
}
int main(){
   int arr[7]={2,4,6,3,4,6,2};
   cout<<unique(arr,7);
}