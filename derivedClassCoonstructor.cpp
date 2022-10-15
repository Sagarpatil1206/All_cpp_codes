#include<iostream>
using namespace std;
class mother{
public:
    mother()
{cout<<"Mother ctor"<<endl;}
    ~mother()
{cout<<"Mother dtor"<<endl;}
};
class daughter:public mother{
public:
     daughter(){
         cout<<"daughter ctor"<<endl;
     }
     ~daughter(){
         cout<<"daughter dtor"<<endl;
     }
};
int main(){
    //mother m;
    daughter d;//so constructor and destructor of base class are also called when object in derived class is created
}//and first base class' constructor is called and at last its destructor