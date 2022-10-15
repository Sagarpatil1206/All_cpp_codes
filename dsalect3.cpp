#include<iostream>
using namespace std;
void addrTD(int b[][3],int s)
{
for(int i=0;i<s;i++)
  for(int j=0;j<s;j++)
cout<<"b["<<i<<"]["<<j<<"]"<<b[i][j]<<"  Address->"<<(int)&b[i][j]<<endl;
}
void TDarrayInput()
{
int A[3][3];
cout<<"Enter the elements of 3*3 array-->";
for(int i=0;i<3;i++)
  for(int j=0;j<3;j++)
cin>> A[i][j];
addrTD(A,3);//get the address
}
int main() {
TDarrayInput();
return 0;
}
