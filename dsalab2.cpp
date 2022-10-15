#include <iostream>
using namespace std;//Structure definition
struct studb
{
int rno;
char name[20];
float sgpa;
}; 
void read_data(struct studb st[],int count)
{ for(int i=0;i<count;i++)
{ cout<<"Enter the Student Roll Number :";
cin>>st[i].rno;
cout<<"Enter the Student Name:";
cin>> st[i].name;
cout<<"Enter the sgpa";
cin>>st[i].sgpa;
}
}
void display(struct studb s[],int count)
{
cout<<"Roll Number"<<'\t'<<"Name "<<'\t'<<"SGPA"<<endl;
for(int i=0;i<count;i++)
{
cout<<s[i].rno<<"\t";
cout<<s[i].name<<'\t'<<'\t';
cout<<s[i].sgpa<<endl;
}
}
int main()
{
int n; 
cout<<"Enter the number of Students:"<<endl;
cin>>n;
/*
cout<<"enter name rollnumber abd sgpa of student"<<endl;
cin>>s1.name;
cin>>s1.rno;
cin>>s1.sgpa;
cout<<"The Name, Roll No. and SGPA of student is"<<s1.name<<s1.rno<<s1.sgpa;
*/
struct studb st[83];//created structure variable array of structures
read_data(st,n); display(st,n);
//st.sortdb(st,n);
//st.display(st,n);
return 0;
}

