#include<iostream>
using namespace std;
bool sorted(int arr[],int n){
    if(n==1){
        return true;
    }
    return((arr[0]<arr[1]) && sorted(arr+1,n-1));//we are just checking first 2 numbers and passing
    //next array excluding starting element until it becomes array of single number i.e. n==1 and then
    //we will use base condition.If at any point arr[0]<arr[1] gets false overall result will be false/0 due to &&.
}
void dec(int n){
    if(n==1){cout<<n<<" ";return;}
    cout<<n<<" ";
    dec(n-1);
}
void inc(int n){
    if(n==1){cout<<n<<" ";return;}
    inc(n-1);
    cout<<n<<" ";
}
int firstLast(int arr[],int n,int key){
    
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<sorted(arr,5)<<endl;
    dec(10);
    inc(10);
}