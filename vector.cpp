#include<bits/stdc++.h>
#include<vector>
using namespace std;
void printVec(vector<int> v){
    cout<<"size:"<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
int main(){
    // vector<int> v;
    // v.push_back(500);
    // v.push_back(10);
    // v.push_back(150);
    
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    
    vector<int>::iterator it;//iterator is a pointer
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    // v.pop_back();

    // for(auto x:v){//element signifies the elements of vector and auto decides element type from vector
    //     cout<<x<<" ";
    // }
    // vector<int> v2(5,20);//5 elements with 15 as a value ,v2(10) then elements with 0 value
    // swap(v,v2);
    // for(int x:v){
    //     cout<<x<<" ";
    // }
    // for(int x:v2){
    //     cout<<x<<" ";
    // }
    // sort(v2.begin(),v2.end());
    // for(int x:v2){
    //     cout<<x<<" ";
    // }
    // printVec(v2);
    vector<int> v1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v1.push_back(k);
        cout<<v1[i];
    }
}