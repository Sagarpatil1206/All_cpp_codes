#include<iostream>
using namespace std;
int unique3(int arr[],int n){
    int result=0;
    for(int i=0;i<64;i++){//we are iterating over each box of 64 bit here
        int sum=0;//defining sum's value 0 everytime we iterate over it.we are now in 'i'th box of bits. 
        for(int j=0;j<n;j++){//here in that 'i'th box we will pass each number
            if(arr[j]&1<<i){//we will check if bit is set at ith position of that number by grtbit operation
            sum+=1;}//if yes qe will add one bit in that position 
        }
        if(sum%3!=0){//here we will condition.
            result=result|1<<i;//if yes then we will set the bit there with setbit operation
            //and update the result and we proceed towards next iteration
        }
    }return result;//returning the result
}
int main(){
    int arr[7]={2,3,2,2,3,3,4};
    cout<<unique3(arr,7);
}