#include<iostream>
using namespace std;

int arr[100][100]={0};

void adjMatrix(int i,int j){
    arr[i][j]=arr[j][i]=1;
}

void displayAdjMatrix(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter number of rows and columns of adjancy matrix :";
    cin>>n;
    adjMatrix(1,2);
    adjMatrix(3,4);
    adjMatrix(2,4);
    displayAdjMatrix(n);
}