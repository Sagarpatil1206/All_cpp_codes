#include<iostream>
using namespace std;
class Enemy{
    protected: 
    int attackPower;
    public:
    virtual void attack()=0;//this is a abstract class...it can be use to create pointers and fumction is called pure virtual function
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
    return 0;
}