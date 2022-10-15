#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
			cin>>n;
			int ans=n/5;
			if((n-((n/5)*5))==1 || (n-((n/5)*5))==4){
				ans+=2;
			}else if((n-((n/5)*5))==2 || (n-((n/5)*5))==3){
				ans++;
			}
	}
	return 0;
}