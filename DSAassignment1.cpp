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
    struct studb st[15]; //student database

public:
    student(int c)
    {
        count = c;
        cout << "no.of students" << count << endl;
    };

    void read_data();     //Database creation
    void display();       //display all records from database
    void search_sgpa();    // searching roll number
    void sortdb();        // sorting records by roll number using bubble sort
    int partition();
    void swap();
    void qsortsgpa(int, int);
    void sortnameInsertion();
    int getcount();
    void binarySearch();
};

int student::getcount(){
	return count;
}

void student::qsortsgpa(int l,int r)//Perform sort on the basis of SGPA
{
	if (l>=r)   return;

	cout<<endl<<"Sorting with l="<<l<<"  and r="<<r<<endl;
		int i=l;
		int j=r+1;
		struct studb prec;
		int p=st[l].sgpa;  //Select pivot element
		prec=st[l];   //temporarily storing pivot record prec

		cout<<endl<<"Pivot element selected is "<<p;

	while(1)
	{       do{  i++;  } while(st[i].sgpa<p &&i<r);
			do{  j--;  } while(st[j].sgpa>p && j>=l);
			if(i>=j)  break;
			cout<<endl<<"Swapping"<<st[i].sgpa<<"and"<<st[j].sgpa<<endl;
			//Swap(st[i],st[j])
			struct studb temp;
			temp=st[j];
			st[j]=st[i];
			st[i]=temp;

	}

	cout<<endl<<"Asssigning"<<st[j].sgpa<<"To"<<st[l].sgpa<<endl;
	st[l]=st[j];
	cout<<endl<<"Asssigning"<<prec.sgpa<<"To"<<st[j].sgpa<<endl;
	st[j]=prec;
	display();
	qsortsgpa(l,j-1);  //left list
	qsortsgpa(j+1,r);  //right list
}


void student::read_data()
{

    for (int i = 0; i < count; i++)
    {
        cout << "Enter the Student Roll Number :";
        cin >> st[i].rno;
        cout << "Enter the Student Name:";
        cin.ignore();
        getline(cin,st[i].name);
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

void student::search_sgpa()
{
    float key;
    cout << "Enter sgpa to be searched" << endl;
    cin >> key;
    bool flag=0;
    for (int i = 0; i < count; i++)
    {
        if (st[i].sgpa == key)
        {
            cout<<"student with given sgpa is :"<<st[i].name<<" "<<st[i].rno<<" "<<st[i].sgpa<<endl;
            flag=1;
        }
    }
    if(flag==0){
        cout<<"no student with given sgpa"<<endl;
    }
}

void student::sortdb()
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count -i- 1; j++)
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

void student::sortnameInsertion(){
    for(int i=1;i<count;i++){
         string current=st[i].name;
         int j=i-1;
        while(((st[j].name).compare(st[j+1].name))>0 && j>=0){
         st[j+1]=st[j];
         j--;
        }
         st[j+1].name=current;
    }
}

void student:: binarySearch(){
        sortnameInsertion();//first sort the names to apply binary search
        int s=0;//s and e are starting and ending indices
        int e=count;
        string key;
        cout << "Enter name to be searched" << endl;
        cin.ignore();
        getline(cin,key);
        while(s<=e){
            int mid=(s+e)/2;//defining mid index
            if(((st[mid].name).compare(key))==0){cout<<"student found in database :"<<st[mid].name<<" "<<st[mid].rno<<" "<<st[mid].sgpa<<endl;}
            else if(((st[mid].name).compare(key))>0){
                e=mid-1; 
            }
            else{ s=mid+1;}
    }cout<<"No record found"<<endl;
}



int main()
{

    int n, pos;
    cout << "Enter the number of Students:" << endl;
    cin >> n;
    student s(n);
    s.read_data();
    //Inserting Menu

    int left=0;
    int right=s.getcount();

    int choice;
    int cont = 1;

    do
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
    		s.qsortsgpa(left,right-1);
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