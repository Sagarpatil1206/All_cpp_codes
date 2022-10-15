#include <iostream>
using namespace std;
int main()
{
    int n1, n2;
    cout<<"enter 2 numbers:"<<endl;
    cin >> n1 >> n2;
    char operation;
    cout<<"enter a character:"<<endl;
    cin >> operation;
    switch(operation){
        case '+':
        cout<<n1+n2<<endl;
        break;
        case '-':
        cout<<n1-n2<<endl;
        break;
        case '*':
        cout<<n1*n2<<endl;
        break;
        case '/':
        cout<<n1/n2<<endl;
        break;
        default:
        cout<<"enter correct operation\n";
            }
            return 0;
}
int  a;
a=10
*p =&a;

