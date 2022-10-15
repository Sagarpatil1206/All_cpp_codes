#include<iostream>
using namespace std;
int main(){
    int arr[]={10,20,30};
    cout<<*arr<<endl;//here varianle arr is storing 0'th  element's address
    //dereferancing arr[0]and *(arr+1)will give next value i.e. arr[1]
    cout<<arr<<endl;//its actually a indexing pointer pointer as now cout arr gives &arr[0]
    int *ptr=arr;//thats why it is very similar to int *ptr=&arr[0];
    for(int i=0;i<3;i++){
        cout<<*ptr<<endl;
        ptr++;//here we are pointing towards next available address which is 4bytes+ from prev. one.
    }//here we cannot use arr at the place of ptr as (arr++) is not allow as it is a non modifiable indexing pointer
    //OR
    for(int i=0;i<3;i++){
        cout<<*(arr+i)<<endl;//here arr is a constant indexing pointer thats why +i gives us a next index's pointer
    }//so we cannot inc./dec. its memory location as its constant but we can change its indexing by aboveme method
}