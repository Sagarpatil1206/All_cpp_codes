#include<iostream>
using namespace std;
int main(){
   string s1="saGAr PatiL";
   //cout<<s1.size();
   for(int i=0;i<s1.size();i++){
       if(s1[i]>='a' && s1[i]<='z'){
           s1[i]-=32;
       }
   }cout<<s1;
}