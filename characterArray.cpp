#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char arr[n+1];
    cin>>arr;
    int i=0;
    cout<<arr[6]<<endl;//null character(if character array is of 5)
    while(arr[i]!='\0'){//'\0' =null character as our sixth character is null 
        cout<<arr[i]<<endl;
        i++;
    }cout<<arr<<endl;
    cout<<arr[2];
}