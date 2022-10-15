#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
using namespace std;
class Student
{
    int rollNo;
    string name;
    string address;
    string div;

public:
    Student();
    void input();
    void show();
    int getRollNo();
    void setName(string);
    void setAddress(string);
    void setDivision(string);
    virtual ~Student();
};
#endif /* STUDENT_H_ */