#include<iostream>
using namespace std;
#define n 30
class queue{
    int *arr;
    int front;
    int back;
    public:
      queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }
    void enqueue(int x){
        if(back==n-1){
            cout<<"Queue is overflow !!!"<<endl;
            return;
        }
        if(front==-1){
            front++;
        }
        back++;
        cout<<"Element added at position "<<back<<" is "<<x<<endl;
        arr[back]=x;
    }
    void dequeue(){
        if(front==-1 || front>back){
            cout<<"Queue is underflow !!!"<<endl;
            return;
        }
        cout<<"Element deleted is "<<arr[front]<<endl;
        front++;
    }
    void display(){
        int f=front;int b=back;
        cout<<"Queue elements are :";
        while(f<=b || front ==-1 ){
            cout<<arr[f]<<" ";
            f++;}
    }
    void peek(){
        if(front>back || front==-1){
            cout<<"Queue is underflow !!!"<<endl;  
            return;
        }
        cout<<"Front element is "<<arr[front]<<endl;
    }
    bool empty(){
        if(front>back || front==-1){
            return 1;
        }else{return 0;}
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(80);
    q.enqueue(60);
    q.enqueue(40);
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.display();
    cout<<"\n"<<q.empty();
}