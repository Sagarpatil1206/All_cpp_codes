#include<iostream>
using namespace std;
void subsets(int arr[],int n){
    for(int i=0;i<(1<<n);i++){//1<<n is a 2^n as that no. of subsets will be formed...
        for(int j=0;j<n;j++){
            if(i & (1<<j)){//here we have use its bitwise operator so i will pass as binary
            //its get bit for particular i for its every place (i.e. 1 will be there)
                cout<<arr[j]<<" ";
            }
        }cout<<endl;
    }
}
int main(){
      int arr[4]={1,2,3,4};
      subsets(arr,4);
      return 0;
}