#include <iostream>
// #define max 15
using namespace std;
struct student
{
    int RollNo;
    string name;
    float fees;
};
class AdmissionQ
{
    struct student st[10];
    int count;
    int f, r;

public:
    AdmissionQ();
    void enqueue();
    void dequeue();
    void display();
} ;
 AdmissionQ::AdmissionQ()
{
    count =10;
    f = r = -1;
}
void AdmissionQ ::enqueue()
{
    if ((r + 1) % count == f)
    {
        cout << "overflow!!" << endl;
        return;
    }
    r = (r + 1) % count;
    cout<<"Enter roll no.";
    cin >> st[r].RollNo;
    cout<<"Enter name:";
    cin.ignore();
    getline(cin,st[r].name);
    cout<<"Enter fees details:";
    cin >> st[r].fees;
    cout<< "Item added in queue:\n"<<"RollNo."<<'\t'<<"Name\t"<<"fees\n";
    cout << st[r].RollNo <<"\t"<<st[r].name<<"\t"<<st[r].fees<<'\n'<< endl ;
    if (f == -1)
        f = 0;
    cout << "F= " << f << "  r= " << r << endl;
}
void AdmissionQ ::dequeue()
{
    if (f == -1)
    {
        cout << "underflow!!" << endl;
        return;
    }
    cout << "Deleted details are:\n"<<"RollNo."<<'\t'<<"Name\t"<<"fees\n" << st[f].RollNo <<"\t"<<st[f].name<<"\t"<<st[f].fees<<'\n'<< endl;
    if (r == f)
    {
        f = r = -1;
        return;
    }
    f = (f + 1) % count;
    cout << "F " << f << "  R " << r << endl;
}
void AdmissionQ ::display()
{
    if (f == -1)
        cout << "underflow!!" << endl;
    else
    {
        cout <<"RollNo."<<'\t'<<"Name\t"<<"fees\n";
        int i = f;
        while (1)
        {
            cout << st[i].RollNo << "\t"<<st[i].name<<"\t"<<st[i].fees<<"\n"<<endl;
            if (i == r)
                break;
            i = (i + 1) % count;
        }
    }
}
int main()
{
    // int c;
    // cout<<"Enter no. of max students in queue:";
    // cin>>c;
    AdmissionQ  q;
    int choice, cont;
    do
    {cout<<"********************"<<endl;
        cout << "1.Enqueue 2.Dequeue 3.Display" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        }
        cout << "continue (1/0)?" << endl;
        cin >> cont;
        
    } while (cont==1);
    return 0;
}