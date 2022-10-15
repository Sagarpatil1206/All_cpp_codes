// #include<iostream>
// using namespace std;
// void increament(int x){
    /*here local variable(x) is created and judt value of a which is 2 is talen
  and put it in this variable and then this variables value is increase not a's value actually*/
//     x++;
//     cout<<x<<endl;
// }
// int main(){
//     int a=2;
//     increament(a);
//     cout<<a<<endl;
//     return 0;
// }
#include<iostream>
using namespace std;
void increament(int *x){//here local pointer variable a is created in which we give &a
    ++*x;//so here a=&a(prev) and *a gives value o
}
int main(){
    int a=2;
    increament(&a);
    cout<<a<<endl;
    
}
