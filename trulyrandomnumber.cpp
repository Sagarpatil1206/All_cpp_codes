#include<iostream>
#include<cstdlib>// to introduce rand and srand operator
#include<ctime>// to introduce time operator
using namespace std;
int main(){
    srand(time(0));
    for(int x=1;x<=10;x++){cout<<1+(rand()%6)<<endl;}
}