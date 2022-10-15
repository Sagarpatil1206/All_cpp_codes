#include <iostream>
#include <fstream>
#include <iomanip>
#define SIZE 100
using namespace std;

class Student
{
private:
    int rollno;
    int marks;
    char name[SIZE];
    char address[SIZE];

public:
    void accept();
    void display();
    void modify();
    int getrno();
    int create(int);
    void display(int);
    int add(int);
    void deleterec(int);
    void modifyrec(int);
};