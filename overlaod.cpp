#include<iostream>
using namespace std;
void printNumber(int x){
    cout<<"Prints an integer:"<<x<<endl;
    }/*we us void mainly in case of cout and things where we are not defining
    some functions like sum or etc.*/

void printNumber(float x){//void denotes no return and if we use int or float main then it returns the corresponding things.
    cout<<"Print a float:"<<x<<endl;
}
int main(){
    int a=16;
    float b=54.541;// here when we are defing int or float then function automatically identify which
    // funcion we want to perform corresponding to given data type
    printNumber(a);
    printNumber(b);
    return 0;
    }//so basicallly functions call is baseed upon argumrnt provided.so here integer argument calls the function which has integer
    // parameter and so on.