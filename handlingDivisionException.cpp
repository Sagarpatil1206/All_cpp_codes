#include<iostream>
using namespace std;
int main(){
  
  int num1;
  cout<<"Enter number 1"<<endl;
  cin>>num1;
  int num2;
  cout<<"Enter number 2"<<endl;
  cin>>num2;
  try{  //trying on this code may contain error
  if(num2==0){throw 0;}
  cout<<"Result:"<<num1/num2<<endl;
  }
  catch(int x){cout<<"Division by zero is not alowed!"<<endl;}//we ctch the exception of type integer only
  }
  