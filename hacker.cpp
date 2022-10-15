#include<iostream>
#include<cmath>
using namespace std;
void update(int *a,int *b) {
   int sum=*a+*b;
   int difference=abs(*a-*b);//it is important to make sum and diff var 
   //because 'cuz *a is updated to *a + *b in the earlier operation. 
   //You see maths in c++ dosen't work like that on paper.
   *a=sum;
   *b=difference; 
}
int main() {
    int a, b;
    //int *pa = &a;int *pb = &b;
    cin>>a>>b;
    update(&a,&b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
