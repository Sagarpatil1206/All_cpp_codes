#include<bits/stdc++.h>
using namespace std;
void reverseStr(string str){
    if(str.size()==0){
        return;
    }
    reverseStr(str.substr(1));//recursion //passing substring from 1st index onwards i.e. ommit 0th index and 1st i become 
    //0th indez
    //here we pass it until str size become 0 then it returns to previous str i.e. last char only and cout it
    //then 
    cout<<str[0];
}
int main(){
    string s;
    cin>>s;
    reverseStr(s);
    int j=s.length()-1;
    int i=0;
    //OR
    while(j!=0){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;j--;
    }
    cout<<"\nreverse string is :"<<s;
}