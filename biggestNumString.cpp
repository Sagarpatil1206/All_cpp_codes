#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str="54085215";
    sort(str.begin(),str.end(),greater<char>());
    reverse(str.begin(),str.end());
    cout<<str;
}