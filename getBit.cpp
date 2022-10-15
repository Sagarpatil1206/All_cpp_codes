#include<iostream>
using namespace std;
int getBit(int n,int pos){
    if(( n & (1<<pos))!=0){return 1;}
    else{return 0;}}

int setBit(int n,int pos){
    return (n | (1<<pos));}

int clearBit(int n,int pos){
        int mask= ~(1<<pos);
        return (n & mask);
}
int updateBit(int n,int pos,int value){
    int mask=~(1<<pos);
    n=(n & mask);//clearing the position
    return (n | (value<<pos));//here value can be 1 or 0 so we ca update either of them 
    //not like setBit where only  0 is updated to 1 so its is clearBit+setBit
}
int main(){
 cout<<getBit(5,2)<<endl;//as 5 is 101 and 1<<2 is 100
 cout<<setBit(5,1)<<endl;//as 5 is 101 and 1<<1 is 010 so after |/ it is 111
 cout<<clearBit(5,2)<<endl;//as 5 is 101 and 1<<2 is 100 so after & it is 001
 cout<<updateBit(5,1,1)<<endl;//as 5 is 101 then 1<<1 is 010 and ~ will be 101 and then & i.e.
 //101 and 010 clears 1st position as it gives 101 and now 101(n) | with value<<pos will give 111 if its 0
 // it would have been given 101
  return 0;
}