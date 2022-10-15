#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string str;
        cin>>str;
        int count=0;
        for(int i=1;i<=n;i++){
           for(int j=i+1;j<n;j++){
                int z=abs(int(str[j])-int(str[i]));
                if(z==(j-i)){
                    count++;
                }
            }
        }cout<<count<<endl;
    }    
	return 0;
}