#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=1;i<=n;i++){
        cin>>array[i];
    }
    int maxNo=INT_MIN;//we have given opposite values ,,,remember it further 
    int minNo=INT_MAX;
    for(int i=1;i<=n;i++){
    //         if(array[i]>maxNo){maxNo=array[i];}
    //         if(array[i]<minNo){minNo=array[i];}
               maxNo=max(maxNo,array[i]);
               minNo=min(minNo,array[i]);
 }
    cout<<maxNo<<" "<<minNo<<endl;
}