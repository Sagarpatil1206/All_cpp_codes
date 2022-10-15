#include<iostream>
using namespace std;
void printArray(int arr[],int size){//by arr[] we are introducing array and when we call it we have to write a name overe there of array                                                                                                                                        n                                                                                                                                                                                                                                                                                                                                             ``
    for(int x=0;x<size;x++){cout<<arr[x];}//here x is a index
}
int main(){
    int myarr[5]={1,2,3,4,5};//defines any random array 
    printArray(myarr,4);//use function printArray (also calling areal array)
    return 0;
}