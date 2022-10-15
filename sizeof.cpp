#include<iostream>
using namespace std;
int main()
{
    cout<<"char:"<<sizeof(char)<<endl;
    cout<<"int:"<<sizeof(int)<<endl;
    cout<<"float:"<<sizeof(float)<<endl;
    cout<<"double:"<<sizeof(double)<<endl;
    double myarr[10];
    cout<<sizeof(myarr)<<endl;
    cout<<sizeof(myarr[0]);
    return 0;
}