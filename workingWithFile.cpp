#include<iostream>
using namespace std;
int main(){
    ofstream MyFile("test.txt");
    MyFile<<"This is awesome!\n";
    MyFile.close()
} 