#include<iostream>
using namespace std;
void swap(int *a,int *b){//locals pointers are created to take address as value 
//its called by reference
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a=10;
    int b=20;
    swap(&a,&b);
    cout<<a<<" "<<b<<endl;
}