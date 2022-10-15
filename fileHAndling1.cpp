#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
    string fileName;
    cout<<"Enter the fileName :";
    cin>>fileName;
    fileName+=".dat";
    ofstream outFile(fileName,ios::app);
    if(!outFile){
        cerr<<"File could not be opened"<<endl;
        exit(1);
    }
    cout<<"Enter the account ,name ,and balance.\n"<<"Enter end-of-file to end ibput.?";
    int account;
    char name[30];
    float balance;
    while(cin>>account>>name>>balance){
        outFile<<account<<' '<<name<<' '<<balance<<'\n';
    }
    outFile.close();
    return 0;
}