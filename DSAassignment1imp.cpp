#include <iostream>
#include <cstring>
using namespace std;

struct studb
{
    int rno;
    string name;
    float sgpa;
};

class student
{

    int count;           // No of students records i have
    struct studb st[15]; //student database's object which storing 15 different student info with studb struct data

public:
    student(int c)
    {
        count = c;
        cout << "Total number of students are :" << count << endl;
    };

    void read_data();   //Database creation
    void display();     //display all records from database
    void search_sgpa(); // searching roll number
    void sortdb();      // sorting records by roll number using bubble sort
    int partition();
    void swap();
    void qsortsgpa(int, int);
    void sortnameInsertion();
    int getcount();
    void binarySearch();
    bool rollNo_validation(int);
    bool name_validation(string);
    void displayRanklist();

};


void student::displayRanklist(){
    cout<<"==================================================================================================="<<endl;
    cout << "Roll Number" << '\t' << "Name " << '\t'<<'\t'<<'\t'<< "SGPA" << endl;
    for (int i = count-1; i >=0 ; i--)
    {
        cout <<'\t'<< st[i].rno << '\t';
        cout << st[i].name << '\t' << '\t';
        cout << st[i].sgpa << endl;
    }
    cout<<"==================================================================================================="<<endl;
}

//validating name
bool student::name_validation(string name)//every s[i] belongs to a to z OR A to Z or space
{
    for(int i=0;i<name.length();i++){
        if((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z') || (name[i]==32)){
            i++;
            if(i==name.length()){
                return true;
            }
        }else{
            cout<<"Enter the valid name :"<<endl;
            return false;
        }
    }
}

//definition of readdata function
void student::read_data()
{

    for (int i = 0; i < count; i++)
    {
        bool valid;
        do{
        cout << "Enter the Student Roll Number :";
        cin >> st[i].rno;
        valid=rollNo_validation(i);
        }while(!valid);//roll number validation

        do{
        cout << "Enter the Student Name:";
        cin.ignore();
        getline(cin, st[i].name);
        valid = name_validation(st[i].name); //name validation
        }while (!valid);
        do{                                 //validating sgpa
        cout << "Enter the sgpa :";
        cin >> st[i].sgpa;
        if(st[i].sgpa<0 || st[i].sgpa>10){valid=0;cout<<"Enter valid sgpa"<<endl;}
        }while(!valid);
        
    }
}

//defining roll number validation function
bool student::rollNo_validation(int i)//non negative and unique
{
    if (st[i].rno < 0)
    {
        cout << "Roll number should not be negative" << endl;
        return false; //if it matches return false
    }
    for (int j = 0; j < i; j++)
    {
        if (st[i].rno == st[j].rno) //comparing roll number with all previous roll numbers
        {
            cout << "Roll number should be unique" << endl;
            return false; //if it matches return false
        }
    }
    return true;
}

int student::getcount()//getting count
{
    return count;
}

//definition of quicksort
void student::qsortsgpa(int left, int right)//sorting by quicksort
{
    int pass = 0;      //to display pass wise output
    int n = right + 1; //quick sort
    if (left >= right){
        return;
    }
    int i = left;
    int j = right + 1;
    studb pivot = st[left];
    while (1)//putting pivot element at its correct position
    {
        do
        {
            i++;
        } while (st[i].sgpa < pivot.sgpa);

        do
        {
            j--;
        } while (st[j].sgpa > pivot.sgpa);
        if (i >= j)
            break;
        else
        {
            studb temp = st[i];
            st[i] = st[j];
            st[j] = temp;
        }
    }
    st[left] = st[j];
    st[j] = pivot; //pass wise output

    qsortsgpa(left, j - 1); //recursion
    qsortsgpa(j + 1, right);
}

/*
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place 
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
         If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} */

//definition of display
void student::display()
{
    cout<<"==================================================================================================="<<endl;
    cout << "Roll Number" << '\t' << "Name " << '\t'<<'\t'<<'\t'<< "SGPA" << endl;
    for (int i = 0; i < count; i++)
    {
        cout <<'\t'<< st[i].rno << '\t';
        cout << st[i].name << '\t' << '\t';
        cout << st[i].sgpa << endl;
    }
    cout<<"==================================================================================================="<<endl;
}

//definition of search_sgpa
void student::search_sgpa()//linear search
{
    float key;
    cout << "Enter sgpa to be searched" << endl;
    cin >> key;
    bool flag = 0;
    for (int i = 0; i < count; i++)
    {
        if (st[i].sgpa == key)
        {//printing all database of same record
            cout << "student with given sgpa is :"
                 << "Name :" << st[i].name << " "
                 << "Roll Number :" << st[i].rno << " "
                 << "SGPA :" << st[i].sgpa << endl;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "no student with given sgpa" << endl;
    }
}

//definition of sortdb
void student::sortdb()//bubbble sort
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (st[j].rno > st[j + 1].rno)//just j's
            {
                struct studb temp;//just to swap we create temp database as we are swapping whole database
                temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }
}

//definition of sortnameInsertion
void student::sortnameInsertion()
{
    for (int i = 0; i < count; i++)
    {
        struct studb current = st[i];
        int j = i - 1;//comparison starts from previous index
        while (j >= 0 && st[j].name > current.name)//direct comparison and always with st[i].name
        {
            st[j + 1] = st[j];//just move greater element by 1 to the right until while loop breaks
            j--;//as its getting its position in sorted array
        }//as last wala bhi j-- so
        st[j + 1] = current;
    }
}

//definition of binary search
void student::binarySearch()
{
    sortnameInsertion(); //first sort the names to apply binary search
    int left = 0;        //s and e are starting and ending indices
    int right = count;
    string key;
    cout << "Enter name to be searched" << endl;
    cin.ignore();
    getline(cin,key);
    bool flag=0;
    while (left <= right)
    {
        int mid = (left + right) / 2; //defining mid index
        if (((st[mid].name).compare(key)) == 0)
        {
            cout << "student found in database :" <<"Name:"<<st[mid].name << " " <<"ROll number :"<<st[mid].rno << " " <<"SGPA :"<<st[mid].sgpa << endl;
            flag=1;
            break;
        }
        else if (((st[mid].name).compare(key)) > 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(flag==0){cout << "No record found" << endl;}
}

int main()
{

    int n, pos;
    int valid=0;
    do{
    cout << "Enter the number of Students:" << endl;
    cin >> n;//taking input of number of students}
    if(n<=0){valid=1;
    cout<<"Enter valid number of students !!! :"<<endl;}else{valid=0;}}while  (valid);
    student s(n);
    s.read_data();
    //Inserting Menu

    int left = 0;
    int right = s.getcount();

    int choice;
    int cont = 1;

    do//applying do while loop
    {
        cout << "1: sort by name \n 2: Display Records \n 3: Search records by sgpa \n 4: Sort records by roollnum\n 5: Merit list by sgpa\n 6:Search name by binary";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.sortnameInsertion();
            break;
        case 2:
            s.display();
            break;
        case 3:
            s.search_sgpa();
            break;
        case 4:
            s.sortdb();
            break;
        case 5:
            s.qsortsgpa(left, right - 1);
            s.displayRanklist();
            break;
        case 6:
            s.binarySearch();
            break;
        }
        cout << endl
             << "Do you want to continue?";
        cin >> cont;
    } while (cont == 1);

    return 0;
}

/* Enter the number of Students:
-60
Enter valid number of students !!! :
Enter the number of Students:       
15
Total number of students are :15
Enter the Student Roll Number :12
Enter the Student Name:Sagar Patil
Enter the sgpa :15
Enter valid sgpa
Enter the sgpa :9.5
Enter the Student Roll Number :16
Enter the Student Name:Harshal Patil
Enter the sgpa :6.8
Enter the Student Roll Number :12
Roll number should be unique
Enter the Student Roll Number :27
Enter the Student Name:Kunal Patil
Enter the sgpa :7.8
Enter the Student Roll Number :65
Enter the Student Name:Varun Gavit
Enter the sgpa :5.8
Enter the Student Roll Number :26
Enter the Student Name:Rohan Bari
Enter the sgpa :6.3
Enter the Student Roll Number :20
Enter the Student Name:Karan Vani  
Enter the sgpa :7.6
Enter the Student Roll Number :27
Roll number should be unique
Enter the Student Roll Number :29
Enter the Student Name:Romi Disuza
Enter the sgpa :7.4
Enter the Student Roll Number :55
Enter the Student Name:Watt Bulb   
Enter the sgpa :7.2
Enter the Student Roll Number :46
Enter the Student Name:Radha Shyam
Enter the sgpa :8.7
Enter the Student Roll Number :36
Enter the Student Name:Gaya Mathura
Enter the sgpa :7.8
Enter the Student Roll Number :59
Enter the Student Name:varsha vani
Enter the sgpa :7.5 
Enter the Student Roll Number :18
Enter the Student Name:Arjun Shaha
Enter the sgpa :4.8
Enter the Student Roll Number :44
Enter the Student Name:Pawan Hava
Enter the Student Name:Pawan Hava
Enter the sgpa :4.1
Enter the Student Roll Number :23
Enter the Student Name:Rony Mathur
Enter the sgpa :6.4
Enter the Student Roll Number :16
Roll number should be unique
Enter the Student Roll Number :17
Enter the Student Name:Ram Shyamal
Enter the sgpa :9.5
1: sort by name 
 2: Display Records
 3: Search records by sgpa
 4: Sort records by roollnum
 5: Merit list by sgpa
 6:Search name by binary2
===================================================================================================
Roll Number     Name                    SGPA
        12      Sagar Patil             9.5
        16      Harshal Patil           6.8
        27      Kunal Patil             7.8
        65      Varun Gavit             5.8
        26      ohan Bari               6.3
        20      aran Vani               7.6
        29      Romi Disuza             7.4
        55      Watt Bulb               7.2
        46      Radha Shyam             8.7
        36      aya Mathura             7.8
        59      varsha vani             7.5
        18      Arjun Shaha             4.8
        44      awan Hava               4.1
        23      Rony Mathur             6.4
        17      Ram Shyamal             9.5
===================================================================================================

Do you want to continue?1
1: sort by name 
 2: Display Records
 3: Search records by sgpa
 4: Sort records by roollnum
 5: Merit list by sgpa
 6:Search name by binary1

Do you want to continue?1
1: sort by name 
 2: Display Records
 3: Search records by sgpa
 4: Sort records by roollnum
 5: Merit list by sgpa
 6:Search name by binary2
===================================================================================================
Roll Number     Name                    SGPA
        18      Arjun Shaha             4.8
        16      Harshal Patil           6.8
        27      Kunal Patil             7.8
        46      Radha Shyam             8.7
        17      Ram Shyamal             9.5
        29      Romi Disuza             7.4
        23      Rony Mathur             6.4
        12      Sagar Patil             9.5
        65      Varun Gavit             5.8
        55      Watt Bulb               7.2
        20      aran Vani               7.6
        44      awan Hava               4.1
        36      aya Mathura             7.8
        26      ohan Bari               6.3
        59      varsha vani             7.5
===================================================================================================

Do you want to continue?1
1: sort by name 
 2: Display Records
 3: Search records by sgpa
 4: Sort records by roollnum
 5: Merit list by sgpa
 6:Search name by binary3
Enter sgpa to be searched
4.1
student with given sgpa is :Name :awan Hava Roll Number :44 SGPA :4.1

Do you want to continue?1
1: sort by name 
 2: Display Records
 3: Search records by sgpa
 4: Sort records by roollnum
 5: Merit list by sgpa
 6:Search name by binary4

Do you want to continue?1
1: sort by name 
 2: Display Records
 3: Search records by sgpa
 4: Sort records by roollnum
 5: Merit list by sgpa
 6:Search name by binary2
===================================================================================================
Roll Number     Name                    SGPA
        12      Sagar Patil             9.5
        16      Harshal Patil           6.8
        17      Ram Shyamal             9.5
        18      Arjun Shaha             4.8
        20      aran Vani               7.6
        23      Rony Mathur             6.4
        26      ohan Bari               6.3
        27      Kunal Patil             7.8
        29      Romi Disuza             7.4
        36      aya Mathura             7.8
        44      awan Hava               4.1
        46      Radha Shyam             8.7
        55      Watt Bulb               7.2
        59      varsha vani             7.5
        65      Varun Gavit             5.8
===================================================================================================

Do you want to continue?1
1: sort by name 
 2: Display Records
 3: Search records by sgpa
 4: Sort records by roollnum
 5: Merit list by sgpa
 6:Search name by binary5
===================================================================================================
Roll Number     Name                    SGPA
        17      Ram Shyamal             9.5
        12      Sagar Patil             9.5
        46      Radha Shyam             8.7
        27      Kunal Patil             7.8
        36      aya Mathura             7.8
        20      aran Vani               7.6
        59      varsha vani             7.5
        29      Romi Disuza             7.4
        55      Watt Bulb               7.2
        16      Harshal Patil           6.8
        23      Rony Mathur             6.4
        26      ohan Bari               6.3
        65      Varun Gavit             5.8
        18      Arjun Shaha             4.8
        44      awan Hava               4.1
===================================================================================================

Do you want to continue?1
1: sort by name 
 2: Display Records
 3: Search records by sgpa
 4: Sort records by roollnum
 5: Merit list by sgpa
 6:Search name by binary6
Enter name to be searched
Varun Gavit
student found in database :Name:Varun Gavit ROll number :65 SGPA :5.8*/