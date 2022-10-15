#include<iostream>
#include<stack>
using namespace std;

void reverseAstring(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main(){
    string s="sagar, How are you?";
    reverseAstring(s);
}