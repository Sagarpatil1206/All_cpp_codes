//============================================================================
// Name : Assignment10.cpp
// Author : Megha Sonavane
// Description : Student database using sequential file
//============================================================================
#include <iostream>
#include "FileOperation.cpp"
using namespace std;
int main()
{
    FileOperation fileOp;
    int ch;
    do
    {
        cout << "================MENUS=================================" << endl;
        cout << "1:Create new database" << endl
             << "2:Add new record" << endl
             << "3:Display all record" << endl
             << "4:Search a record" << endl;
        cout << "5:Modify a record" << endl
             << "6:Delete a record" << endl
             << "0:Exit" << endl;
        cout << "Enter choice:";
        cin >> ch;
        cout << "======================================================" << endl;
        switch (ch)
        {
        case 1:
            //create database
            fileOp.create();
            break;
        case 2:
            //adding new record
            fileOp.addnew();
            break;
        case 3:
            //display all records
            fileOp.display();
            break;
        case 4:
            //search a particular record
            fileOp.search();
            break;
        case 5:
            //modify record
            fileOp.modify();
            break;
        case 6:
            //delete record
            fileOp.delet();
            break;
        case 0:
            //exit
            cout << "Thank you...";
            break;
        default:
            cout << "Enter valid choice.." << endl;
            break;
        }
    } while (ch != 0);
    return 0;
}
/*
 Output
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:1
======================================================
New database created...
Enter details of student:
Roll No:1001
Name:abcd
Division:se11
Address:abcd
Added successfully..
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:2
======================================================
Enter details of student:
Roll No:1002
Name:pqrs
Division:pqrs
Address:pqrs
Added successfully..
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:2
======================================================
Enter details of student:
Roll No:1002
Name:xyz
Division:xyz
Address:xyz
Student with roll number1002 already exist...
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:3
======================================================
RollNo Name Division Address
1001 abcd se11 abcd
1002 pqrs pqrs pqrs
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:5
======================================================
Enter roll number of student:1005
Record not found...
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:5
======================================================
Enter roll number of student:1002
Record found...
Enter updated details==>
Name:pqrs
Address:pqrs
Division:TE4
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:4
======================================================
Enter roll number to be search:1002
Record found..
RollNo Name Division Address
1002 pqrs TE4 pqrs
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:3
======================================================
RollNo Name Division Address
1001 abcd se11 abcd
1002 pqrs TE4 pqrs
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:2
======================================================
Enter details of student:
Roll No:1003
Name:xyz
Division:fe4
Address:xyz
Added successfully..
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:3
======================================================
RollNo Name Division Address
1001 abcd se11 abcd
1002 pqrs TE4 pqrs
1003 xyz fe4 xyz
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:6
======================================================
Enter roll number of student to be deleted:1005
Record not found..
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:6
======================================================
Enter roll number of student to be deleted:1002
Record deleted..
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:4
======================================================
Enter roll number to be search:1002
Record not found..
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:3
======================================================
RollNo Name Division Address
1001 abcd se11 abcd
1003 xyz fe4 xyz
================MENUS=================================
1:Create new database
2:Add new record
3:Display all record
4:Search a record
5:Modify a record
6:Delete a record
0:Exit
Enter choice:0
======================================================
Thank you...
*/