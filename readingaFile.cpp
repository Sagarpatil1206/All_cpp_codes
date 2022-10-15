#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string line;
    ifstream MyFile("test.txt"); //input file stream that reads information from file
    while(getline(MyFile,line)){//getline=reads characters from an input stream and places them into a string
        cout<<line<<'\n';
    }
    MyFile.close();
   }

