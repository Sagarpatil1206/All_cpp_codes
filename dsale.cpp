#include <iostream>
using namespace std;
using namespace std;void print(int b[], int size)
{​​
cout << "The elements of array are ->"; for(int i=0;i<size;i++)
cout<<" "<<b[i];
}​​void printAdress(int b[], int size)
{​​
cout<<"Size of int is "<<sizeof(int)<<endl;
cout<<"The address of elements are ->"<<endl;
for(int i=0;i<size;i++)
cout<<"b["<<i<<"]--> "<<int(& b[i])<<endl;}​​
int main() {​​
int size;
int a[5]={​​3,4,5,6,7}​​;
size=sizeof(a)/sizeof(int); //calculate sizeof array
print(a,size);
printAdress(a,size);return 0;
}​​

