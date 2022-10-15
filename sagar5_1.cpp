#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"What is your age?";
    cin>>age;
    if(age>14){if(age>=18){cout<<"You are adult";}
    else{cout<<"You are teenager";}
    }
    else{if(age>0){cout<<"You are child";}
    else{cout<<"please recheak your data";}
    }
    return 0;
}//This is nested if that is condition ke andar condition.But for nested condition is the subset of condition specified first (or outside i.e. in first if)