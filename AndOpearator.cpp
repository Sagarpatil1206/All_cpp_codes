#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter your age=";
    cin>>age;
    if(age>16 && age<60){cout<<"You are elligible";}
    else{cout<<"Sorry,You are not eligible";}
    return 0;
}//we use || for OR statement inn which condn is true if any one of its operand is right.