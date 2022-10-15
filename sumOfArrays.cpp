#include<iostream>
using namespace std;
int main()
{
    int arr[]={15,25,35,16,45};
    int sum=0;
    for(int x=0;x<5;x++){sum+=arr[x];}
    cout<<sum;
    return 0;
}