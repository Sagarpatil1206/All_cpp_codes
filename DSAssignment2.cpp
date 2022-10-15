#include<iostream>
using namespace std;

struct studb{
    int rno;
    string name;
    float sgpa;
};

class admissionQueue{
    int N;
    int F,R;
    struct studb st[3];
    public:
    admissionQueue();
    void enqueue();
    void dequeue();
    void display();
};

admissionQueue::admissionQueue(){
        N=3;
        F=R=-1;
    }

void admissionQueue::enqueue(){
    if((R+1)%N==F){
        cout<<"Overflow !!!"<<endl;
        return;}
        R=(R+1)%N;
        cout<<"Enter the roll number :";
        cin>>st[R].rno;
        cout<<"Enter the name :";
        cin.ignore();
        getline(cin,st[R].name);
        cout<<"Enter the sgpa :";
        cin>>st[R].sgpa;
        cout<<"Data added is :: ROll number : "<<st[R].rno<<"   Name :"<<st[R].name<<"   sgpa :"<<st[R].sgpa<<endl;
        if(F==-1){
            F=0;
            cout<<"F="<<F<<" R="<<R<<endl;
        }
}

void admissionQueue::dequeue(){
    if(F==-1){
        cout<<"Underflow!!!"<<endl;
        return;
    }
    cout<<"Data deleted is :: ROll number : "<<st[F].rno<<"   Name :"<<st[F].name<<"   sgpa :"<<st[F].sgpa<<endl;
    if(F==R){
        F=R=-1;
        return;
    }
    F=(F+1)%N;
    cout<<"F="<<F<<" R="<<R<<endl;
}

void admissionQueue::display(){
    if(F==-1){
        cout<<"UnderFlow!!!"<<endl;
    }else{
        int i=F;
        cout<<"======================================================================"<<endl;
        cout << "Roll Number" << '\t' << "Name " << '\t'<<'\t'<< "SGPA" << endl;
        while(1){
        cout <<'\t'<< st[i].rno << '\t';
        cout << st[i].name << '\t' << '\t';
        cout << st[i].sgpa << endl;
            if(i==R){
                break;
            }
            i=(i+1)%N;
        }
        
    }
    cout<<"======================================================================"<<endl;
}
int main(){
    admissionQueue q;
    int op,cont;
    cout<<"==========================================="<<endl;
    do{
        cout<<"1.Enqueue\t2.Dequeue\t3.Display"<<endl;
        cin>>op;
        switch(op){
            case 1:q.enqueue();
            break;
            case 2:q.dequeue();
            break;
            case 3:q.display();
            break; 
        }
        cout<<"Continue ?(1/0)"<<endl;
        cin>>cont;
    }while(cont);
}