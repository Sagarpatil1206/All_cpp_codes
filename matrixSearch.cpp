#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }int key;
    cin>>key;
    int r=0,c=m-1;
    bool found=false;
    while(r<n && c>=0){
        if(key==arr[r][c]){
            found= true;
        }
        if(key<arr[r][c]){
            c--;
        }else{r++;}
    }
    if(found){cout<<"yes";}
    else{cout<<"No";}

}