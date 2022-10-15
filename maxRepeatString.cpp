#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="jskdgakssldjfdsfjad";
    int charFreq[26];
    for(int i=0;i<26;i++){}
        charFreq[i]=0;}//charFreq array initiate with 0 for all
    for(int i=0;i<str.size();i++){
        charFreq[str[i]-'a']+=1;}//so a's freq is store in  and b's in st and so on...

    char ans=0;int maxFreq=0;

    for(int i=0;i<26;i++){
        if(charFreq[i]>maxFreq){
            maxFreq=charFreq[i];
            ans='a'+i;//these operations are done by ascii value operations as ans a is char ascii value
            //get converted into respective character
            }
    }cout<<ans<<" "<<maxFreq;
}