#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];}}
    
    cout<<"the printed matrics is = \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;}}
//     }int x;
//     cout<<"what you want to search in array\n";
//     cin>>x;
//     bool flag=false;
//      for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==x){cout<<"element is at row "<<i+1<<" and column "<<j+1<<endl;
//             flag=true;}
//         }
//         }
//         if(flag){cout<<"It's in the array";}
//         else{cout<<"It's not in the array";}
//         return 0;

// }