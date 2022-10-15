#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int n;cin>>n;
	    string s;getline(cin,s);
	    
	    int arr[n]={0};int max=0;
	    for(int j=0;j<n;j++){
	        arr[s[j]]++;
	        if(arr[s[j]]>max){
	            max=arr[s[j]];
	        }
	    }
	    
	    if(n%2!=0 && max>(n/2)){
	        cout<<"NO"<<endl;
	    }else{
	        cout<<"YES"<<endl;
	    }
	}
	return 0;
}