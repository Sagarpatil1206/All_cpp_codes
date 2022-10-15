#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream MyFile("test.txt");
    if (MyFile.is_open()){//here is
        MyFile<<"this is awesome!\n";
    }
    else{cout<<"something went wrong";}
    MyFile.close();
}
