#include <iostream>
using namespace std;
struct studentdb
{
    int Rollnum;
    string name;
    float sgpa;
};
void rollcall(struct studentdb st[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (st[j].Rollnum > st[j + 1].Rollnum)
            {
                int temp = st[j].Rollnum;
                st[j].Rollnum = st[i].Rollnum;
                st[i].Rollnum = temp;
            }
        }
    }
}

void sortName(struct studentdb st[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (st[j].name > st[j + 1].name)
            {
                string temp = st[j].name;
                st[j].name = st[i].name;
                st[i].name = temp;
            }
        }
    }
}

void searchSgpa(struct studentdb st[], int n)
{
    int key;
    cout << "Enter Key ";
    cin >> key;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (st[i].sgpa == key)
        {
            cout << "Student with given SGPA is " << st[i].name << endl;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "Data not found";
    }
}

int main()
{
    int n;
    cout << "Number of students in a class :";
    cin >> n;
    studentdb st[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter roll number of student "<<i+1<<" : ";
        cin>>st[i].Rollnum;
        cout<<"Enter name of student "<<i+1<<" : ";
        cin>>st[i].name;
        cout << "Enter sgpa of student " << i + 1 << " : ";
        cin >> st[i].sgpa;
    }

    // rollcall(st,n);
    // sortName(st,n);

    cout<<"Roll number \t"<<"Name \t"<<"sgpa \t"<<endl;
    for(int i=0;i<n;i++){
        cout<<"\t";
        cout<<st[i].Rollnum<<"\t";
        cout<<st[i].name<<"\t";
        cout<<st[i].sgpa<<"\t";
        cout<<endl;
    }
    searchSgpa(st, n);
}