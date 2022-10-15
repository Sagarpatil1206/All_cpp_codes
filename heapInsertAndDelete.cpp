#include<iostream>
#define maxSize 1000
using namespace std;

void heapify(int arr[],int i){//down top

    while(i>1){
        int parent=i/2;
        if(arr[i]>arr[parent]){
            swap(arr[parent],arr[i]);
            i=parent;
        }
        else{
            break;
        }
    }
}

void insertInHeap(int arr[],int size,int key){
    size=size+1;//increasing size of heap by 1 as we are increasing its number by 1
    arr[size]=key;
    heapify(arr,size);//as its new size is increased by 1 than previous size
}

int main(){

    int arr[maxSize];
    int n;
    cin>>n;
    arr[0]=0;

    cout<<"Enter node elements :";
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the key to be inserted :";
    cin>>key;

    insertInHeap(arr,n,key);

    for(int i=1;i<=n+1;i++){
        cout<<arr[i]<<" ";
    }
}