#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    int top=0,bottom=n-1,left=0,right=m-1;// top++  1   2   3   4
    while(top<=bottom && left<=right){    //        5   6   7   8 
         for(int k=left;k<=right;k++){    //        9   10  11  12
            cout<<arr[top][k]<<" ";}     //bottom-- 13  14  15  16
            top++;                        //       left++     -- right
        for(int k=top;k<=bottom;k++){
            cout<<arr[k][right]<<" ";}
            right--;
        for(int k=right;k>=left;k--){
            cout<<arr[bottom][k]<<" ";}
            bottom--;
        for(int k=bottom;k>=top;k--){
            cout<<arr[k][left]<<" ";}
            left++;
    }
}