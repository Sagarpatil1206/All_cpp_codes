#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<=100;j++){
            if(j%2==0){cout<<arr[i][j];}
            if(j%2!=0){cout<<arr[i][j];}
        } 
    }
    return 0;
}