#include "studentFileHandle.cpp"

int main()
{
    int choice, i, flag, cntr = 0;
    Student st;

    while (1)
    {
        cout << "\nStudents Database" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Add" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Modify" << endl;
        cout << "6. Exit program" << endl;
        cout << "\nEnter your choice:- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cntr = st.create(cntr);
            break;
        }

        case 2:
        {
            st.display(cntr);
            break;
        }
        case 3:
        {
            if (cntr == 0)
                cout << "\nPlease build a master table first" << endl;
            else
                cntr = st.add(cntr);
            break;
        }

        case 4:
        {
            if (cntr == 0)
                cout << "\nPlease build a master table first" << endl;
            else
                st.deleterec(cntr);
            break;
        }
        case 5:
        {
            if (cntr == 0)
                cout << "\nPlease build a master table first" << endl;
            else
                st.modifyrec(cntr);
            break;
        }
        case 6:
            return 0;
        default:
            cout << "Error in choice,try again" << endl;
        }
    }
    return 0;
}

/*
Students Database   
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program     

Enter your choice:- 1
Enter the roll number:- 78
Enter the name of the student:- Sagar
Enter the address of the student:- Shirpur
Enter the marks:- 98

Do you want to add another record?(y/n):- y
Enter the roll number:- 45
Enter the name of the student:- Samir
Enter the address of the student:- Pune
Enter the marks:- 79

Do you want to add another record?(y/n):- y
Enter the roll number:- 98
Enter the name of the student:- samrat
Enter the address of the student:- Thane
Enter the marks:- 73

Do you want to add another record?(y/n):- n

Students Database
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program

Enter your choice:- 2

-----------------------------------------------------------------
Sr No. Roll No.    Name    Address      Marks

-----------------------------------------------------------------
  1     78         Sagar        Shirpur         98
  2     45         Samir        Pune    79
  3     98         samrat       Thane           73

Students Database
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program

Enter your choice:- 3
Enter the details of the record you want to insert:- 
Enter the roll number:- 56
Enter the name of the student:- Sachin
Enter the address of the student:- Mumbai
Enter the marks:- 65
Record inserted successfully

Students Database
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program

Enter your choice:- 3
Enter the details of the record you want to insert:- 
Enter the roll number:- 12
Enter the name of the student:- Sakshi
Enter the address of the student:- Nainital
Enter the marks:- 71
Record inserted successfully

Students Database
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program

Enter your choice:- 2

-----------------------------------------------------------------
Sr No. Roll No.    Name    Address      Marks

-----------------------------------------------------------------
  1     78         Sagar        Shirpur         98
  2     45         Samir        Pune    79
  3     98         samrat       Thane           73
  4     56         Sachin       Mumbai          65
  5     12         Sakshi       Nainital        71

Students Database
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program

Enter your choice:- 4
Enter the roll number of the record you want to delete:- 45
Record with roll number 45 deleted successfully

Students Database
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program

Enter your choice:- 5
Enter the roll number of the record you want to edit:- 12
Enter new name of student:- Sanika
Enter the new marks:- 87
Record with roll number 12 edited successfully

Students Database
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program

Enter your choice:- 2

-----------------------------------------------------------------
Sr No. Roll No.    Name    Address      Marks

-----------------------------------------------------------------
  1     78         Sagar        Shirpur         98
  2     98         samrat       Thane           73
  3     56         Sachin       Mumbai          65
  4     12         Sanika       Nainital        87

Students Database
1. Create
2. Display
3. Add
4. Delete
5. Modify
6. Exit program

Enter your choice:- 6
PS C:\Users\dell\Desktop\C++ programs\C++ Files> 
*/