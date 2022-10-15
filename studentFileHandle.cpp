#include "studentFileHandle.h"

void Student::accept()//to accept student database
{
    cout << "Enter the roll number:- ";
    cin >> rollno;
    cin.ignore();
    cout << "Enter the name of the student:- ";
    cin.getline(name, SIZE);
    cout << "Enter the address of the student:- ";
    cin.getline(address, SIZE);
    cout << "Enter the marks:- ";
    cin >> marks;
}

void Student::display()//to display student data
{
    cout << "\t" << rollno << "\t   " << name << "   \t" <<  address << "   \t"<< marks << "\n";
}

void Student::modify()//for modifying record
{
    cin.ignore();
    cout << "Enter new name of student:- ";
    cin.getline(name, SIZE);
    cout << "Enter the new marks:- ";
    cin >> marks;
}

int Student::getrno()//returns roll number
{
    return rollno;
}

int Student::create(int cntr)//creating student database
{
    int rno;
    Student m;
    ofstream fout("recs.dat", ios::binary | ios::out);
    cntr = 0;
    char ask = 'y';
    while (ask == 'y' || ask == 'Y')
    {
        m.accept();
        fout.write((char *)&m, sizeof(m));
        cntr++;
        cout << "\nDo you want to add another record?(y/n):- ";
        cin >> ask;
    }
    fout.close();
    return cntr;
}

void Student::display(int cntr)//for displaying student database
{
    int i;
    Student m;
    if (cntr == 0)
        cout << "\nPlease build a master table first" << endl;
    else
    {
        ifstream fin("recs.dat", ios::binary | ios::in);
        cout << "\n-----------------------------------------------------------------" << endl;
        cout << "Sr No. " << setw(5) << "Roll No.  ";
        cout << "  Name  ";
        cout << "  Address ";
        cout << "     Marks" << endl;
        cout << "\n-----------------------------------------------------------------" << endl;
        i = 1;
        while (fin.read((char *)&m, sizeof(m)))
        {
            cout << "  " << i << "  ";
            m.display();
            i++;
        }
        fin.close();
    }
}

int Student::add(int cntr)//for adding new record
{
    Student m;
    ofstream fout("recs.dat", ios::binary | ios::app);
    cout << "Enter the details of the record you want to insert:- " << endl;
    m.accept();
    fout.write((char *)&m, sizeof(m));
    fout.close();
    cntr++;
    cout << "Record inserted successfully" << endl;
    return cntr;
}

void Student::deleterec(int cntr)//for deleting certain record
{
    Student m;
    int flag;
    int rno;
    ifstream fin("recs.dat", ios::binary | ios::in);
    cout << "Enter the roll number of the record you want to delete:- ";
    cin >> rno;
    flag = 0;
    while (fin.read((char *)&m, sizeof(m)))
    {
        if (rno == m.getrno())
        {
            flag = 1;
            cntr--;
            break;
        }
    }
    fin.close();
    if (!flag)
        cout << "\nRecord with roll number " << rno << " not found" << endl;
    else
    {
        ofstream fout("temp.dat", ios::binary | ios::out);
        ifstream fin("recs.dat", ios::binary | ios::out);
        fin.seekg(0, ios::beg);
        fin.read((char *)&m, sizeof(m));
        while (!fin.eof())
        {
            if (m.getrno() != rno)
                fout.write((char *)&m, sizeof(m));
            fin.read((char *)&m, sizeof(m));
        }
        fout.close();
        fin.close();
        cout << "Record with roll number " << rno << " deleted successfully" << endl;
        remove("recs.dat");
        rename("temp.dat", "recs.dat");
    }
}

void Student::modifyrec(int cntr)//to modify reocord
{
    Student m;
    int rno;
    int flag;
    ifstream fin("recs.dat", ios::binary | ios::in);
    cout << "Enter the roll number of the record you want to edit:- ";
    cin >> rno;
    flag = 0;
    while (fin.read((char *)&m, sizeof(m)))
    {
        if (rno == m.getrno())
        {
            flag = 1;
            cntr--;
            break;
        }
    }
    fin.close();
    if (!flag)
        cout << "\nRecord with roll number " << rno << " not found" << endl;
    else
    {
        ofstream fout("temp.dat", ios::binary | ios::out);
        ifstream fin("recs.dat", ios::binary | ios::out);
        fin.read((char *)&m, sizeof(m));
        while (!fin.eof())
        {
            if (m.getrno() == rno)
            {
                m.modify();
                fout.write((char *)&m, sizeof(m));
            }
            else
                fout.write((char *)&m, sizeof(m));
            fin.read((char *)&m, sizeof(m));
        }
        fout.close();
        fin.close();
        cout << "Record with roll number " << rno << " edited successfully" << endl;
        remove("recs.dat");
        rename("temp.dat", "recs.dat");
    }
}