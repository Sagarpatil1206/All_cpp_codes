#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 20
//Structure definition
struct studb
{
    int rno;
    string name;
    char mname[MAX_LEN];
    float sgpa;
};

void read_data(struct studb st[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Enter the Student Roll Number :";
        cin >> st[i].rno;
        cin.ignore();
        cout << "Enter the Student Name:";
        getline(cin, st[i].name);
        cout << "Enter the Mothers Name:";
        cin.getline(st[i].mname, 20);
        cout << "Enter the sgpa";
        cin >> st[i].sgpa;
    }
}
void display(struct studb s[], int count)
{
    cout << "Roll Number" << '\t' << "Name " << '\t' << "SGPA" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << s[i].rno  << "\t";
        cout << s[i].name << '\t' << '\t';
        cout << s[i].sgpa << endl;
    }
}
void search_roll(struct studb s[], int count)
{
    int key;
    cout << "Enter Roll Number to be searched" << endl;
    cin >> key;

    bool flag = 0;
    
    for (int i = 0; i < count; i++)
    {
        if (s[i].rno == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Number found !!" << endl;
    else
        cout << "Number not available in the list !!" << endl;
}

int main()
{

    int n;

    cout << "Enter the number of Students:" << endl;
    cin >> n;
    /*
cout<<"enter name rollnumber abd sgpa of student"<<endl;
cin>>s1.name;
cin>>s1.rno;
cin>>s1.sgpa;
cout<<"The Name, Roll No. and SGPA of student is"<<s1.name<<s1.rno<<s1.sgpa;
*/
    struct studb st[n]; //created structure variable array of structures
    read_data(st, n);
    display(st, n);
    search_roll(st, n);
    //st.sortdb(st,n);
    //st.display(st,n);
    return 0;
}