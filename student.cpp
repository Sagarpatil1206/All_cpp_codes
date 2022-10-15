/*
* Student.cpp
* Author: Megha Sonavane
*/
#include <iostream>
#include "Student.h"
    using namespace std;
Student::Student()
{
    // TODO Auto-generated constructor stub
}
//===================definition of input()===========================
void Student::input()
{
    cout << "Enter details of student:" << endl;
    cout << "Roll No:";
    cin >> rollNo;
    cin.ignore();
    cout << "Name:";
    getline(cin, name);
    cout << "Division:";
    getline(cin, div);
    cout << "Address:";
    getline(cin, address);
}
//=================definition of show()===============================
void Student::show()
{
    cout << rollNo << "\t" << name << "\t" << div << "\t" << address << endl;