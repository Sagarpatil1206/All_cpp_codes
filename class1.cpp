#include<iostream>
using namespace std;
class student{
    string name;
  public:
    int age;
    bool gender;

    student(){//default constructor
        cout<<"Default constructor "<<endl;
    }

    student(string n,int a,int g){//parameterise constructor
        cout<<"parameterise constructor"<<endl;
        name=n;
        age=a;
        gender=g;
    }

    student(student &a){
        cout<<"Copy constructor";
        name=a.name;
        age=a.age;
        gender=a.gender;
    }
    
    void setName(string s){//private data member is access like this
        name=s;
    }
    void getName(){//outputting after setting prive data member
        cout<<name<<"\t"<<age<<"\t"<<gender<<endl;
    }

    void printInfo(){
        cout<<"Name :"<<name<<endl;
        cout<<"Age :"<<age<<endl;
        cout<<"Gender :"<<gender<<endl;
    }

};

int main(){
    // student arr[3];//define array of instances/objects
    // for(int i=0;i<3;i++){
    //     cout<<"Enter name :";
    //     //cin>>arr[i].name;
    //     string s;
    //     cin>>s;
    //     arr[i].setName(s);//every function and attribute of class will be access through its object
    //     cout<<"Enter age :";
    //     cin>>arr[i].age;
    //     cout<<"Enter gender :";
    //     cin>>arr[i].gender;
    //     arr[i].printInfo();
    // }

    student sagar("sagar",20,1);
    sagar.getName();
    student ram;
    student shyam=sagar;
    shyam.getName();  
}