#include<iostream>
using namespace std;
class Enemy{
    protected: 
    int attackPower;
    public:
    virtual void attack(){cout<<"enemy"<<endl;}
};
class Ninja:public Enemy{
    public:
    void attack(){cout<<"Ninja!"<<endl;}
};
class Monster:public Enemy{
    public:void attack(){
        cout<<"Monster!"<<endl;
    }
};
int main(){
    Ninja n;
    Monster m;
    Enemy *e1=&n;
    Enemy *e2=&m;
    e1->attack();
    e2->attack();
    }
/*if a function in the base class is virtual,the function's implementation in the derived class is class is type called according to the
actual type of the object reffered to,reagrdless of the declared type of the pointer*/
/*so virtual function=a function or method whose behaviour can be overridden within an inheriting class 
by a function with the same signature....by using it ,it allows us to use enemy pointers to call the derived classes' functions 
every derived class will override the attack() function and have a separate implementation*/ //so here enemy class is polymorphic class as it declares/inherites a virtual function