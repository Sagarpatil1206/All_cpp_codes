#include<bits/stdc++.h>
using namespace std;
void search(int arr[],int n,int key){
    for(int i=0;i<10;i++){
        if(arr[i]==key){
            cout<<"KEY IS found"<<endl;
            break;
        }
        return;
    }
}
int main(){
    int arr[10];
    int key;
    cout<<"Enter the key :";
    cin>>key;
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    cout<<*max_element(arr,arr+10);
    return 0;
}