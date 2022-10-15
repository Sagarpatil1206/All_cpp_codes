#include<bits/stdc++.h>
#include<stack>
using namespace std;

class conversionInToPre{
    public:
    string s;
    int precedance(char);
    bool associativity(char);
    string InfixToPrefix(string);

};

int conversionInToPre:: precedance(char c){
    if(c=='^'){return 3;}
    if(c=='*' || c=='/'){return 2;}
    if(c=='+' || c=='-'){return 1;}
    else{return -1;}
}

bool conversionInToPre::associativity(char c){
    if(c=='^'){return 0;}else{
        return 1;
    }
}

string conversionInToPre::InfixToPrefix(string s){
    reverse(s.begin(),s.end());
    stack<char> st;
    string ans;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            ans+=s[i];
            cout<<"ans string is "<<ans<<endl;
        }else if(s[i]==')'){
            st.push(s[i]);
        }else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                ans+=st.top();
                cout<<"ans string is "<<ans<<endl;
                st.pop();
            }
            if(!st.empty()){cout<<st.top()<<" top";st.pop();}
        }
        else{
            while(!st.empty() && ((precedance(st.top())>precedance(s[i])) || 
            (precedance(st.top())==precedance(s[i]) && associativity(st.top())==0 && associativity(s[i])==0))){
               ans+=st.top();
               cout<<"ans string is "<<ans<<endl;
               st.pop();
            }
               st.push(s[i]);
        }
    }
    while(!st.empty()){
            ans+=st.top(); 
            cout<<"ans string is "<<ans<<endl;
            st.pop();      
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    // string s;
    conversionInToPre
 obj;
    // cin>>obj.s;
    //cout<<InfixToPrefix(obj.s);
    cout<<obj.InfixToPrefix("a+b*c^d^e-f/g*h");
}