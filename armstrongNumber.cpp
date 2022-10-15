#include<iostream>
//#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int armstrong=0;
    int originaln=n;//imp step as we reduce n to 0 by deviding several times
    //so to store original n we store it in new variable originaln
    while(n!=0){
     int lastdigit=n%10;
     armstrong=armstrong + (lastdigit*lastdigit*lastdigit);//pow(lastdigit,3);
     n=n/10;
    }if(armstrong==originaln){cout<<originaln<<" is an armstrong number";}
    else{cout<<originaln<<" is not an armstrong number";}
    return 0;
}