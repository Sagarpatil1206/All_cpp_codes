// As we have seen in tut55.cpp that BASE class pointer pointing to DERIVED class object can only access BASE class inherited members which is a default behavior.
// But if you want to change default behavior and  want to access the members of derived class by a pointer pointing to derived class object then use virtual keyword in front of BASE class member function.

#include<iostream>
using namespace std;
class Enemy{
    protected: 
    int attackPower;
    public:
    virtual void attack(){cout<<"enemy"<<endl;}//we are overriding the default behaviour of pointer as in int main
};//without virtual function other pointers will still execute this function from base class
class Ninja:public Enemy{
    public:
    void attack(){cout<<"Ninja!"<<endl;}
};
class Monster:public Enemy{
    public:
    void attack(){cout<<"Monster!"<<endl;}
};

int main(){
    Enemy e;
    Ninja n;
    Monster m;
    Enemy *e1=&n;
    Enemy *e2=&m;
    Enemy *e3=&e;
    e1->attack();
    e2->attack();
    e3->attack();
}