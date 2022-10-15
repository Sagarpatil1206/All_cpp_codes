#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int currency[]={1,2,5,10,20,50,100,200,500,2000};
int n=sizeof(currency)/sizeof(currency[0]);

void minNotes(int value){
    vector<int> ans;
    sort(currency,currency+n);
    for(int i=n-1;i>=0;i--){
        while(value>=currency[i]){
            value=value-currency[i];
            ans.push_back(currency[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int value;
    cout<<"Enter value :";
    cin>>value;
    minNotes(value);
}