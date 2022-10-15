#include<iostream>
#include<string>
using namespace std;
class myClass{
    public:
    void setName(string x){name=x;}
    private://if we make it public we will get a output "john"
    string name;
};
int main(){
    myClass myObj;
    myObj.setName("john");
    cout<<myObj.name<<endl;
    return 0;
}