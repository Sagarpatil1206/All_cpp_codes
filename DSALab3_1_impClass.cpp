//============================================================================
// Name : ass1DSAL.cpp
// Author : Deepali
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

struct studb
{
    int rno;
    char name[10];
    float sgpa;
};

class student
{

    int count;           // No of students records i have
    struct studb st[10]; //student database

public:
    student(int c)
    {
        count = c;
        cout << "no.of students" << count << endl;
    };

    void read_data();     //Database creation
    void insert_record(); //insert one record in database
    void display();       //display all records from database
    int search_roll();    // searching roll number
    void sortdb();        // sorting records by roll number using bubble sort
};
void student::read_data()
{

    for (int i = 0; i < count; i++)
    {
        cout << "Enter the Student Roll Number :";
        cin >> st[i].rno;
        cout << "Enter the Student Name:";
        cin >> st[i].name;
        cout << "Enter the sgpa";
        cin >> st[i].sgpa;
    }
}

void student::insert_record()
{

    cout << "Enter the Student Roll Number :";
    cin >> st[count].rno;
    cout << "Enter the Student Name:";
    cin >> st[count].name;
    cout << "Enter the sgpa";
    cin >> st[count].sgpa;
    count++;
}

void student::display()
{
    cout << "Roll Number" << '\t' << "Name " << '\t' << "SGPA" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << st[i].rno << '\t';
        cout << st[i].name << '\t' << '\t';
        cout << st[i].sgpa << endl;
    }
}
int student::search_roll()
{
    int key;
    cout << "Enter Roll Number to be searched" << endl;
    cin >> key;

    int flag = 0;
    int pos = 0;
    for (int i = 0; i < count; i++)
    {
        if (st[i].rno == key)
        {
            pos = i;
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Number found !!" << endl;
    else
        cout << "Number not available in the list !!" << endl;
    return pos;
}

void student::sortdb()
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (st[j].rno > st[j + 1].rno)
            {
                struct studb temp;

                temp = st[j];

                st[j] = st[j + 1];

                st[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int n, pos;
    cout << "Enter the number of Students:" << endl;
    cin >> n;
    student s(n);
    s.read_data();
    //Inserting Menu

    int choice;
    int cont = 1;

    do
    {
        cout << "1: Insert Student Records \n 2: Display Records \n 3: Search records \n 4: Sort records \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.insert_record();
            break;
        case 2:
            s.display();
            break;
        case 3:
            pos = s.search_roll();
            cout << endl
                 << "The position where record is found is " << pos;
            break;
        case 4:
            s.sortdb();
            break;
        }
        cout << endl
             << "Do you want to continue?";
        cin >> cont;
    } while (cont == 1);

    return 0;
}