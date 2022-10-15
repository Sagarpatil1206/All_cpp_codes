#include<iostream>
using namespace std;
class Animal{
    public:
    void behaviour(){ cout<<"barking"<<endl;}
};
int main()
{
    Animal dog;
    dog.behaviour();
}