#include<iostream>
using namespace std;
struct employee_db{
    string name;
    int Emp_ID;
    int salary;
};
void read_data(struct employee_db em[],int count){
    for(int i=0;i<count;i++){
    cout<<"Enter the Employee name :";
    cin>>em[i].name;
    cout<<"Enter the Emp_ID:";
    cin>>em[i].Emp_ID;
    cout<<"Enter the salary";
    cin>>em[i].salary;
    }
}
void display(struct employee_db edb[],int count){
    cout<<"name"<<'\t'<<"Emp_ID "<<'\t'<<"salary"<<endl;
     for(int i=0;i<count;i++){
        cout<<edb[i].name<<"\t";
        cout<<edb[i].Emp_ID<<'\t'<<'\t';
        cout<<edb[i].salary<<endl;}
}
void search_employee(struct employee_db em[],int count,string key){
    for(int i=0;i<count;i++){
        if(em[i].name==key){
            cout<<"This Employee is from our Company";
            break;
        }
    }cout<<"employee is not from our conmpany ";
}
int main(){
    int n;
    cout<<"Enter number of employees :";
    cin>>n;
    struct employee_db em[50];
    read_data(em,n);
    display(em,n);
    string key;
    cout<<"Enter employee name to be found :";
    cin>>key;
    search_employee(em,n,key);
    return 0;
}