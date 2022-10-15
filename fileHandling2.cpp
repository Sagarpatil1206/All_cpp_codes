#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    char data[100];
    // open a file in write mode.
    ofstream outfile;
    outfile.open("afile.dat",ios::out); //,ios::app
    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);
    // write inputted data into the file.
    outfile << data << endl;
    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();
    outfile << data << endl; //write to file
    // close the opened file.
    outfile.close();

    ifstream infile;
    //char data[100];
    string line;
    infile.open("afile.dat");
    cout << "Reading from the file" << endl;

    while (infile)
    {

        // Read a Line from File
        getline(infile, line);

        // Print line in Console
        cout << line << endl;
    }

    /* infile >> data;
 write the data at the screen.
cout << data << endl;
again read the data from the file and display it.
infile >> data;
cout << data << endl;
close the opened file.*/

    infile.close();
    return 0;
}