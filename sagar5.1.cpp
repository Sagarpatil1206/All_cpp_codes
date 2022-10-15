#include<iostream>
using namespace std;
int main()
{
    int age;
    cin>>age;
    if(age>14){if(age>=18){cout<<"You are adult";}
    else{cout<<"You are teenager";}
    }
    else{if(age>0){cout<<"You are child";}
    else{cout<<"please recheck your data";}
    }
}