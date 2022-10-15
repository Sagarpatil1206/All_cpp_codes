#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"Enter tesst cases :";
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int j=0;j<n;i++){
            for(int k=i+1;k<n;k++){
                int counta=0;int countb=0;
                string str=s.substr(j,k);
                for(int l=j;l<=k;l++){
                    if(str[l]=='a'){
                        counta++;
                    }else{countb++;}
            }if(counta==countb && counta>1){
                cout<<j<<" "<<k<<endl;
                break;
            }
        }
    }
}
}