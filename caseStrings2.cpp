#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s1="sagaDasdHFkk";
    transform(s1.begin(),s1.end(),s1.begin(),::toupper);
    cout<<s1;
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    cout<<s1;
}