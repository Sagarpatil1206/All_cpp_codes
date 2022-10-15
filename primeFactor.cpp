#include<iostream>
using namespace std;
void primeFactor(int n){
    int spf[100]={0};//all marked 0 (spf=smallest prime factor)
    for(int i=2;i<=n;i++){
        spf[i]=i;//all marked with their resp value as if not found its a prime itself so it has its
        //own value then
    }
    for(int i=2;i<n;i++){
        if(spf[i]==i){//meanse its not processed yet
            for(int j=i*i;j<=n;j+=i){
                spf[j]=i;//here spf of every j is marked with i as for the first time its getting marked so 
                //i is the smallest number to get j marked so id is its one of prime factor
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";//smallest for n
        n=n/spf[n];//new n is obtained after dividing with prev spf and we get reduce number for which spf has 
        //to be found and so on until unless spf becomes number itself and gives 1
    }
}
int main(){
    int n;
    cin>>n;
    primeFactor(n);

}