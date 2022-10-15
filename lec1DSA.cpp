#include <iostream>
using namespace std;
int main()
{
    // cout<<"My name is Sagar\n";
    // cout<<"Roll no. 23258\n";
    // cout<<"My department is IT\n";
    // cout<<"My sem 1 sgpa is 9.95";
    int num1, num2;
    
    cout << "Enter two numbers :";
    cin >> num1 >> num2;
    cout << "Sum of num1 and num2 is " << num1 + num2;
    cout << "\nSubraction of num1 and num2 is " << num1 - num2;
    cout << "\nMultiplication of num1 and num2 is " << num1 * num2;
    if (num2 == 0)
    {
        cout << "\nDivision by 0 is not valid";
    }
    else
    {
        cout << "\nDivision of and num2 is " << num1 / num2;
    }
}