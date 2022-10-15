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

    void read_data();
    void display();
    void sortdb();
    void search();
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

void student::search(){
    int key;
    cout<<"Enter roll number to be search";
    cin>>key;
    for(int i=0;i<count;i++){
        if(st[i].rno==key){
            cout<<"Roll number found"<<endl;
            break;
        }
        if(i==count-1){
            cout<<
        }
    }
}
int main()
{

    int n;

    cout << "Enter the number of Students:" << endl;
    cin >> n;

    student s(n);
    s.read_data();

    s.display();
    s.sortdb();
    s.display();

    return 0;
}