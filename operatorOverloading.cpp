#include<iostream>
using namespace std;

class complex{
    int real;int img;
    public:

    complex(){
        real=0;
        img=0;
    }

    complex(int a,int b){
        real=a;
        img=b;
    }

    complex operator+(complex &a){//return type is complex  and operator overloading is on + passing a object of complex passed
        complex temp;//here a's value is of c2's vlaue
        temp.real=real+a.real;//here real and img is of c1's 
        temp.img=img+a.img;
        return temp;
    }

    void printcomplex(complex &c){
        cout<<c.real<<"+"<<c.img<<"i"<<endl;
    }

};

int main(){
    complex c1(10,15);
    complex c2(18,13);
    complex c3;
    c1=c2+c3;
    c3=c1+c2;//here c3=c1.add(c2) i.e. c1 calling add (+) operator by passing c2 value
    c3.printcomplex(c3);//calling method by ibjects name and then passing a parameter
}