#include<iostream>
using namespace std;
template<class T>
class MyClass{public: MyClass(T x){
    cout<<x<<"-is not a char"<<endl;}
};
template<> //starting with template<>
class MyClass<char>{public:MyClass(char x){ //then class MyCLass but with <> and having a data type mentioned in these paranthesis
    cout<<x<<"-is a char"<<endl;}
};
int main(){
    MyClass<int> obj1(15);
    MyClass<double> obj2(12.56);
    MyClass<char> obj3('s');
}