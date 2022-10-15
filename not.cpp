#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter your age=";
    cin>>age;
    if(!(age>16)){cout<<"You are elligible";}
    else{cout<<"Sorry,You are not eligible";}
    return 0;
}