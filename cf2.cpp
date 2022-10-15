#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ansArr[t];
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        int sArr[26];
        for(int k=0;k<26;k++){
            sArr[s[k]-'a']=k;
        }

        string str;
        cin>>str;
        int ans=0;
        for(int j=0;j<str.length()-1;j++){
            int c=abs(sArr[str[j]-'a']-sArr[str[j+1]-'a']);
            ans+=c;
        }
        ansArr[i]=ans;
    }

    for(int i=0;i<t;i++){
        cout<<ansArr[i]<<endl;
    }
}