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

/*             OUTPUT
===========================================
1.Enqueue       2.Dequeue       3.Display  
2
Underflow!!!   
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
1
Enter the roll number :12
Enter the name :Sagar
Enter the sgpa :8.5
Data added is :: ROll number : 12   Name :Sagar   sgpa :8.5
F=0 R=0
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
1
Enter the roll number :58
Enter the name :Shyamala
Enter the sgpa :9.5
Data added is :: ROll number : 58   Name :Shyamala   sgpa :9.5
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
1
Enter the roll number :65
Enter the name :Ramya
Enter the sgpa :7.5
Data added is :: ROll number : 65   Name :Ramya   sgpa :7.5
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
1
Overflow !!!
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
3
======================================================================
Roll Number     Name            SGPA
        12      Sagar           8.5
        58      Shyamala                9.5
        65      Ramya           7.5
======================================================================
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
2
Data deleted is :: ROll number : 12   Name :Sagar   sgpa :8.5
F=1 R=2
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
2
Data deleted is :: ROll number : 58   Name :Shyamala   sgpa :9.5
F=2 R=2
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
3
======================================================================
Roll Number     Name            SGPA
        65      Ramya           7.5
======================================================================
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
1
Enter the roll number :75
Enter the name :Puja
Enter the sgpa :5.5
Data added is :: ROll number : 75   Name :Puja   sgpa :5.5
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
3
======================================================================
Roll Number     Name            SGPA
        65      Ramya           7.5
        75      Puja            5.5
======================================================================
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
2
Data deleted is :: ROll number : 65   Name :Ramya   sgpa :7.5
F=0 R=0
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
2
Data deleted is :: ROll number : 75   Name :Puja   sgpa :5.5
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
2
Underflow!!!
Continue ?(1/0)
1
1.Enqueue       2.Dequeue       3.Display
3
UnderFlow!!!
======================================================================*/