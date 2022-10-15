#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string s1="sagar";
    cout<<s1.size()<<endl;
    s1.insert(0,"patil");
    cout<<s1<<endl;

    cout<<s1.size()<<endl;
    for(int i=0;i<s1.size();i++){
        cout<<s1[i]<<" ";
    }cout<<endl;

    string s=s1.substr(1,3);
    cout<<s<<" "<<s1.substr(1,6)<<endl;

    string s2="1206";
    int x=stoi(s2);//string to integers
    cout<<x+12<<endl;//addition

    int x1=1206;
    cout<<to_string(x1)+"12"<<endl;//appending

    string s3="jksdhqbcfhasnolqibapzknuest rpqo wijvdkb";
    sort(s3.begin(),s3.end());//imp sort(staringIterators and endingIterator
    cout<<s3;
}
