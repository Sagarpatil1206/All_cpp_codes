#include<iostream>
using namespace std;
int main(){
    try{//the code may cause an exception
        int motherAge=29;
        int sonAge=36;
        if(sonAge>motherAge){
            throw 99;//throwing exception causing value or error code that we define
        }
    }
    catch(int x){
        cout<<"wrong age values-Error "<<x;//catch will catch the throw thing and handle exception
    }
    return 0;
}