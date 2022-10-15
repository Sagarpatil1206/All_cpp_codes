#include<iostream>
#include<string>//for definig string
using namespace std;
class myClass{
    public:
    string name;//define a attribute which is a string named 'name' in "public" access specifier.
};
int main(){
    myClass myObj;//give name and form a object(instntination)
    myObj.name="SoloLearn";//modified and access from outside
    cout<<myObj.name;//but dot we are calling specific attribute of specific object
    return 0;
}