#include<iostream>
using namespace std;
int main()
{
    int num=1;
    int total=0;//here initaial value of variable totle is=0
    int number;
    while(num<=5){cout<<"enter a number=";//we can also write this is in for loop as for(;x<=5;)
    cin>>number;
    total=total+number;//or we cam also enter total+=number
    num++;}
    cout<<"The total is="<<total;
    return 0;
}
