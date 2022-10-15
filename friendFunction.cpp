#include<iostream>
using namespace std;
class myClass{
    public:
    myClass(){
        regVar=0;
    }
    private:
    int regVar;
    friend void someFunc(myClass &obj);//it allows to access to private members of a class
};                                     //passing an object through function by & operator 
void someFunc(myClass &obj){
    obj.regVar=42;
    cout<<obj.regVar;
int main(){
    myClass obj;
    someFunc(obj);
}