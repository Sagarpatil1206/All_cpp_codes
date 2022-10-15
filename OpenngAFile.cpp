#include<iostream>
#include<fstream>
using namespcae std;
int main(){
    ofstream MyFile;
    MyFile.open("test.txt");
    MyFile<<"some text.\n";
    MyFile.close()
}