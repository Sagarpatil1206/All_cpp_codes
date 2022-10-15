#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1="ABCd";//uppercase is given preferance 
    string s2="ABCd";
    cout<<s1.compare(s2)<<endl;//value decide by lexicographically
    if(!s1.compare(s2)){
            cout<<"Strings sre equal"<<endl;}
    //s1.clear();
    cout<<s1.empty()<<endl;
    if(s1.empty()){
        cout<<"YES its empty"<<endl;
    }
    //s1.erase(1,2);//erase from index  and erase 2 letters 
    //cout<<s1; 
    cout<<"Given word strts from "<<s1.find("ABC")<<"th index"<<endl;
    s1.insert(2,"IamHear");
    cout<<s1<<endl;
    string s3="30";string s4="40";
    cout<<s3+s4;
}