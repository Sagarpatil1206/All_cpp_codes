#incldue<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[n][m];
        }
    }int x;
    cin>>x;
    bool flag=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==x){flag==1;}
        }}
        if(flag){cout<<"It's in the array";}
        else{cout<<"It's not in the array";}
        return 0;
}