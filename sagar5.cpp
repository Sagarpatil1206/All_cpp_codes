#include<iostream>
using namespace std;
int main()
{
    int marks;
    cout<<"enter your marks =";
    cin>>marks;
    if(marks>=50){cout<<"Congratulations You are passed\n";
                  cout<<"You Are Awesome\n";
            if(marks==100) {cout<<"you are brilliant";}
            }
    else cout<<"Sorry You are failed";
    //for non nested mense single statement you can avoid braces
        return 0;
}