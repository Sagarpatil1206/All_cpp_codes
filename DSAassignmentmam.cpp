//============================================================================
// Name : ass1DSAL.cpp
// Author : Deepali
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
#define max 20

struct studb
{
    int rno;
    string name;
    float sgpa;
};

class student
{
private:
    int count;           // No of students records i have
    struct studb st[10]; //student database

public:
    student(int c) //Constructor
    {
        count = c;
        cout << "no.of students" << count << endl;
    };

    void read_data();     //Database creation
    void insert_record(); //insert one record in database
    void display();       //display all records from database
    int search_roll();    // searching roll number
    void sortdb();        // sorting records by roll number using bubble sort
    void qsort(int, int);
    int getcount();
};

int student::getcount()
{
    return count;
}

void student::qsort(int l, int r) //Perform sort on the basis of SGPA
{
    if (l >= r)
        return;
    int i = l;
    int j = r + 1;
    struct studb prec;
    int p = st[l].sgpa; //Select pivot element
    prec = st[l];       //temporarily storing pivot record prec
    while (1)
    {
        do
        {
            i++;
        } while (st[i].sgpa < p);
        do
        {
            j--;
        } while (st[j].sgpa > p);
        if (i >= j)
            break;
        //Swap(st[i],st[j])
        struct studb temp;
        temp = st[j];
        st[j] = st[i];
        st[i] = temp;
    }
    st[l] = st[j];
    st[j] = prec;
    qsort(l, j - 1); //left list
    qsort(j + 1, r); //right list
}
void student::read_data()
{

    for (int i = 0; i < count; i++)
    {
        cout << "Enter the Student Roll Number :";
        cin >> st[i].rno;
        cin.ignore();
        cout << "Enter the Student Name:";
        getline(cin, st[i].name);
        cout << "Enter the sgpa";
        cin >> st[i].sgpa;
    }
}

void student::insert_record()
{

    cout << "Enter the Student Roll Number :";
    cin >> st[count].rno;
    cin.ignore();
    cout << "Enter the Student Name:";
    getline(cin, st[count].name);
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

void student::sortdb() //Bubble sort
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (((st[j].name).compare(st[j + 1].name)) > 0) //Swapping process
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
    if (n > max)
        cout << "Maximum records can be inserted are 10";

    student s(n);
    s.read_data();
    //Inserting Menu

    int choice;
    int cont = 1;

    do
    {
        cout << " 1: Insert Student Records \n 2: Display Records \n 3: Search records \n 4: Sort records \n 5: Quick Sort SGPA\n";
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
        case 5:
            int l = 0;
            int r = s.getcount();
            s.qsort(l, r - 1);
            break;
        }
        cout << endl
             << "Do you want to continue?";
        cin >> cont;
    } while (cont == 1);

    return 0;
}
