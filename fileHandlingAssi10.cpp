//============================================================================
// Name : seqFile_Bin.cpp
// Author : Deepali
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
//#include<cconio>
//#include<cprocess>
using namespace std;

struct Student{
    int stud_rollno;
    char stud_name[30];
    char stud_divison;
    char stud_address[30];
    DoB stud_DoB;
    float stud_percent;
    char stud_grade;
};

struct DoB{
    int stud_day;
    int stud_month;
    int stud_year;
};

class seqfile{
    Student stud_rec;
    ostream outfile;
    istream infile;

    public:
    void create();
    void display(int);
    void add();
    void search(int);
    void modified(int);
    void Delete(int);
};

class file
{
private:
    int roll;
    float marks;
    char name[100];

public:
    void input();
    void show();
    int getroll()
    {
        return roll;
    }
};
file fileobj;
file modified;
fstream fil; //declration of file pointer/object
void file::input()
{
    
    cout << "Enter the roll, marks and name :";
    cin >> roll >> marks;
    cin.ignore();
    gets(name);
}
void file::show()
{
    cout << "Roll==> " << roll << endl;
    cout << "marks ==> " << marks << endl;
    cout << "Name==> " << name << endl;
}
void Create();
void Add();
void Display();
void DisplayP();
void Modify();
void Delete();

int main()
{
    int opt;
    while (1)
    {

        cout << "1.Create Data File" << endl;
        cout << "2.Add New Record in Data File" << endl;
        cout << "3.Display Record From Data File" << endl;
        cout << "4.Display Particular Record From Data File" << endl;
        cout << "5.Modify Particular Record From Data File" << endl;
        cout << "6.Delete Particular Record From Data File" << endl;
        cout << "7.Exit From the Program" << endl;
        cout << "Enter your Option : " << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            Create();
            cout << "Display Main Menu" << endl;

            break;
        }
        case 2:
        {
            Add();
            cout << "Display Main Menu" << endl;

            break;
        }
        case 3:
        {
            Display();
            cout << "Display Main Menu" << endl;

            break;
        }
        case 4:
        {
            DisplayP();
            cout << "Display Main Menu" << endl;

            break;
        }
        case 5:
        {
            Modify();
            cout << "Display Main Menu" << endl;

            break;
        }
        case 6:
        {
            Delete();
            cout << "Display Main Menu" << endl;

            break;
        }
        case 7:
            exit(0);

        default:
        {
            cout << "Wrong Choice....Press Key For View the Main Menu";
        }
        }
    }
}

void Create() //Function to Create Data File
{
    char ch = 'y';
    fil.open("binary.dat", ios::out | ios::binary);

    while (ch == 'y' || ch == 'Y')
    {
        fileobj.input();
        fil.write((char *)&fileobj, sizeof(fileobj));
        cout << "Want to Continue.....";
        cin >> ch;
    }
    fil.close();
}

void Add() //Function to Add New Record in Data File
{
    char ch = 'y';
    fil.open("binary.dat", ios::app | ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        fileobj.input();
        fil.write((char *)&fileobj, sizeof(fileobj));
        cout << "Want to Continue.....";
        cin >> ch;
    }
    fil.close();
}

void Display() //Function to Display All Record from Data File
{
    fil.open("binary.dat", ios::in | ios::binary);
    if (!fil)
    {
        cout << "File not Found";
        exit(0);
    }
    else
    {
        fil.read((char *)&fileobj, sizeof(fileobj)); // read 108 bytes block
        while (!fil.eof())
        {
            fileobj.show();
            fil.read((char *)&fileobj, sizeof(fileobj)); // next 108 bytes block
        }
    }
    fil.close();
}

void DisplayP() //Function to Display particular Record from Data File
{
    int rollnu;
    cout << "Enter Roll No that should be searched:";
    cin >> rollnu;
    fil.open("binary.dat", ios::in | ios::binary);
    if (!fil)
    {
        cout << "File not Found";
        exit(0);
    }
    else
    {
        fil.read((char *)&fileobj, sizeof(fileobj));
        while (!fil.eof())
        {
            if (rollnu == fileobj.getroll())
                fileobj.show();
            else
                cout << "Press Any Key....For Search" << endl;

            fil.read((char *)&fileobj, sizeof(fileobj));
        }
    }
    fil.close();
}
void Modify() //Function to Modify Particular Record from Data File
{
    int rollnu;
    cout << "Enter Roll No. that should be modified:";
    cin >> rollnu;
    ofstream m;
    fil.open("binary.dat", ios::in | ios::out | ios::binary);
    m.open("new.dat", ios::out | ios::binary);
    if (!fil)
    {
        cout << "File not Found";
        exit(0);
    }
    else
    {
        fil.read((char *)&fileobj, sizeof(fileobj));
        while (!fil.eof())
        {
            if (rollnu == fileobj.getroll())
            {
                cout << "Enter New Record.." << endl;
                modified.input();
                m.write((char *)&modified, sizeof(modified));
            }
            else
                m.write((char *)&fileobj, sizeof(fileobj));

            fil.read((char *)&fileobj, sizeof(fileobj));
        }
    }
    m.close();
    fil.close();
    remove("binary.dat");
    rename("new.dat", "binary.dat");
}

void Delete() //Function to Delete Particular Record from Data File
{
    int rollnu;
    cout << "Enter Roll No. that to be deleted:";
    cin >> rollnu;
    ofstream o;
    o.open("new.dat", ios::out | ios::binary);     //writting to the file
    fil.open("binary.dat", ios::in | ios::binary); //reading from file
    if (!fil)
    {
        cout << "File not Found";
        exit(0);
    }
    else
    {
        fil.read((char *)&fileobj, sizeof(fileobj)); //reading binary.dat
        while (!fil.eof())
        {
            if (rollnu != fileobj.getroll())
                o.write((char *)&fileobj, sizeof(fileobj)); //copy the record into new file if it is not matching to the record to be deleted

            fil.read((char *)&fileobj, sizeof(fileobj)); //reading binary.dat
        }
    }
    o.close();
    fil.close();
    remove("binary.dat");
    rename("new.dat", "binary.dat");
}