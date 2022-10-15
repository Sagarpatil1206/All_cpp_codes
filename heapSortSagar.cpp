//Heapify procedure can be applied to a node only if its children nodes are heapified
//15/12/2021

#include<iostream>
using namespace std;

class heapSort{
    public:
    void heapsort(int[],int);
    void heapify(int[],int,int);
    void printHeapSort(int[],int);
};

void heapSort::heapify(int arr[],int n,int i){//heapify acepting array its size and index of node where we have to heapify
    int largest=i;//storing largest index as nodes index initially
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]){//as l has to be l<n as it has to be exist
        largest=l;//change l=largest if let children of node is greater
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){//if we find that either of children is greater than its node
        swap(arr[i],arr[largest]);//swapping them as largest will be node now
        heapify(arr,n,largest);//applying heapify on new swap on larger node which is node now to heapify that node as well
    }
}

void heapSort::heapsort(int arr[],int n){//heapsort function
    for(int i=n/2-1;i>=0;i--){//i upto 0th index to heapify given array at first
        heapify(arr,n,i);//Heapify procedure can be applied to a node only if its children nodes are heapified thats why bottom up
    }
    for(int i=n-1;i>=0;i--){//from last element to 0
        swap(arr[0],arr[i]);//swap last element with highest which is at 0 th index
        heapify(arr,i,0);//Heapify procedure can be applied to a node only if its children nodes are heapified thats why can apply top down
    }//applying heapify on 0th index everytime as we are wwapping and reduxing array size
}

void heapSort::printHeapSort(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    heapSort hps;
    int arr[10]={5,8,3,6,4,0,9,1,2,7};
    hps.heapsort(arr,10);
    hps.printHeapSort(arr,10);
}