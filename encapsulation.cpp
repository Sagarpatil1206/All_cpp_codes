#include<iostream>
using namespace std;

class encapsulation{
    public:
    void printA(){
        cout<<"Hii,its a public access modidfier of encapuslation class"<<endl;
    }
    private:
    void printB(){//private data memebrs and member functions cannot be accessible from outside
        cout<<"Hii,its a private access modidfier of encapuslation class"<<endl;
    }
    protected:
    void printC(){
        cout<<"Hii,its a protected access modidfier of encapuslation class"<<endl;
    }
};

class second{
    public:
    void printSecond(){
        cout<<"This is from second class"<<endl;
    }
};

class derived:public encapsulation,public second{//this class can access public and protected members of class encapsulation
//multiple inheritance
    public:
    void display(){
        return printA();
    }

};

class third:public second{
    public:
    void printThird(){
        cout<<"This is from third class"<<endl;
    }
};

class derived1:public third{
    public:
    void printderived1(){
        cout<<"This is from derived1 class"<<endl;
    }
};

int main(){
    encapsulation obj;
    obj.printA();//single inheritance
    derived obj1;
    obj1.printSecond();//multiple inheritance
    derived1 obj2;
    obj2.printSecond();//multilevel inheritance
}