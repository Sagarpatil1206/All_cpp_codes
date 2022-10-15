#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t;
    cin>>t;
    long long int ans[t];
    for(long long int i=0;i<t;i++){
        long long int initialPos;long long int jumps;
        cin>>initialPos;
        cin>>jumps;
        for(long long int j=1;j<=jumps;j++){
            if(initialPos%2==0){
                initialPos=initialPos-j;
            }else{
                initialPos=initialPos+j;
            }
        }
        ans[i]=initialPos;
    }
    for(long long int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}