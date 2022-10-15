// #include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    const int N=1e5+2;
    int idx[N];//its storing the indices of elements of array arr[n] at indices = their value
    for(int i=0;i<N;i++){idx[i]=-1;}
    int minidx=INT_MAX;
    for(int i=0;i<n;i++){
        if(idx[arr[i]]=-1){idx[arr[i]]=i;}//they are occuru=ing for first time thats why -1 is there
        else{minidx=min(minidx,idx[arr[i]]);}//if its not there its already occured and we noe we have
        //to store that index which is
    }
    if(minidx==INT_MAX){
        cout<<"-1"<<endl;}
    else{cout<<minidx+1<<endl;}
    }