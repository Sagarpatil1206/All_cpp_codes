#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter three numbers :";
    cin>>a>>b>>c;
    if(a>b){
        if(a>c){
            cout<<"Maximum of three numbers is "<<a;
        }else{
            cout<<"Maximum of three numbers is "<<c;
        }
    }else{
        if(c>b){
        cout<<"Maximum of three numbers is "<<c;
        }else{cout<<"Maximum of three numbers is "<<b;}
    }
}