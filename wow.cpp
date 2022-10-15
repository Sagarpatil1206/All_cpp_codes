#include <bits/stdc++.h>
using namespace std;

unsigned long long int power( int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    bool flag=0;
	    cout<<power(10,100)<<endl;
	    for(unsigned long long int j=power(10,n-1);j<power(10,n);j++){
	        bool flag1=1;
	        if(j%2!=0){
	        unsigned long long int temp=j;
	        int ld=0;
	        int count=0;  
	        while(temp){   
	            ld=temp%10;
	            if(ld==0){flag1=0;break;}
	            count+=ld;
	            temp=temp/10;
	        }
	        
	        if(count%3==0 && count%9!=0 &&  flag1){
	            cout<<j<<endl;
	            flag=1;
	            break;
	        }
	  }
	}}
	return 0;
}