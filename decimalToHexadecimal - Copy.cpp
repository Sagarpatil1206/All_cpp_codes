#include<iostream>
using namespace std;
string decimalToHexadecimal(int n){
    int x=1;
    string ans="";
    while(x<=n){x=x*16;}
    x=x/16;
    int lastdigit=0;
    while(x>0){lastdigit=n/x;
    n=n-lastdigit*x;
    x=x/16;
    if(lastdigit<=9){ans=ans+ to_string(lastdigit);}
    else{char c='A'+lastdigit-10;
    ans.push_back(c);}}
    return ans;}
    int main(){
        int n;cin>>n;
        cout<<decimalToHexadecimal(n)<<endl;
        return 0;
    }