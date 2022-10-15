#include<iostream>
using namespace std;
int uniqueNumber(int arr[],int n){
    int xorSum=0;
    for(int i=0;i<n;i++){
        xorSum=xorSum^arr[i];//by commutative property all same elements will nullify
    }
    return xorSum;  
}
int main(){
 int arr[7]={6,5,9,7,6,7,5}; 
 cout<<uniqueNumber(arr,7);
}