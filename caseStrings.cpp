#include<iostream>
using namespace std;
int main(){
   string s1="saGAr PaTiL";
   //cout<<s1.size();
   for(int i=0;i<s1.size();i++){
       if(s1[i]>='a' && s1[i]<='z'){
           s1[i]-=32;//convering to upper case
       }}
       cout<<s1<<endl;
    //converting to lower case
   for(int i=0;i<s1.size();i++){
       if(s1[i]>='A' && s1[i]<='Z')
        s1[i]+=32;
   }cout<<s1;
}