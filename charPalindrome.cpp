#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char arr[n+1];
    cin>>arr;
    bool check=1;
    for(int i=0;i<n;i++){//(n+1)th character with index 'n' will be null character
    //so we are just checking upto (n-1)th index
        if(arr[i]!=arr[n-1-i]){
            check=0;
            break;}
    }
    if(check)
    cout<<"Word it is palindrome";//you can drop braces if statement is 1 liner
    else
    cout<<"Word is not a palindrome";
}
