#include<iostream>
using namespace std;
int getbit(int n,int pos){
    return (n & 1<<pos);// in getbit we will get to know which bit is there; at specific position
}
void twoUnique(int arr[],int n){
    int xorSum=0;
    for(int i=0;i<n;i++){
        xorSum=xorSum^arr[i];//we will get xor of twoUnique numbers
    }
    int temp=xorSum;
    int getPos=0;
    int pos=0;
    while(getPos!=1){//jab tak equal to 1 nahi milta tab tak
        getPos=xorSum & 1;
        pos++;//updating postion
        xorSum=xorSum>>1;//proceeds towards next bit of xorSum as next bit will
    }//we just get position for 1 of xorsum from here
    int newXor1=0;
    int newXor2=0;
    for(int i=0;i<n;i++){//at pos-1 both unique numbers have different bits
        if(getbit(arr[i],pos-1)){//getting the bit of pos-1 position of evry (binary) numberfrom getbit and 
        //if its 1 it will pass here 
        //it will pass (as 1= true).
            newXor1=newXor1^arr[i];//as others will get nullify except 1 the unique number
        }
        else{newXor2=newXor2^arr[i];}//numbers with 0 at given (pos-1) will pass and we will get 
    }
    cout<<newXor1<<" "<<newXor2<<endl;//newXors are two unique numbers
}
int main(){
   int arr[8]={1,2,3,1,2,3,4,5};
   twoUnique(arr,8);
   return 0;
}