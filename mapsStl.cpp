#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    map<int,string> m;
    m[11]="abc";
    m[5]="def";
    m[88]="ghi";
    m.insert({4,"fgh"});
    for(auto &x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<*(m.find(4)).second;
    m.insert({4,"fgh"});
    cout<<(m.size());

}