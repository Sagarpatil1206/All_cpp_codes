#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=2;
    int pd=arr[1]-arr[0];
    int current=2;
    int j=2;
    for(int i=0;i<n;i++){
       if(arr[j]-arr[j-1]==pd){
           current++;
           j++;
       }else{pd=arr[j]-arr[j-1];
       current=2;}
       ans=max(ans,current);
       j++;

    }cout<<ans;
} /*steps
1)identify all variables that gonna require;
2)define condition rewuire and how wen gonna get ans and its updation;
3)Identify which variable has to increament and where;
4)Identify which exact operation we have to perform;*/
