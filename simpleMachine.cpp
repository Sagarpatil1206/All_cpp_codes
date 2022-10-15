#include <iostream>
using namespace std;

float currentBalance(int p, int r, float t)
{
    float balance = (p * r * t) / 100;
    return balance;
}

bool validations(int p, int r, int currMonth, int depoMonth)
{
    if (p < 0 || r <= 0 || currMonth < 1 || currMonth > 12 || depoMonth < 1 || depoMonth > 12)
    {
        if (p < 0)
        {
            cout << "Enter appropriate amount";
        }
        if (r <= 0)
        {
            cout << "Enter appropriate rate of interest";
        }
        if (currMonth < 1 || currMonth > 12)
        {
            "Enter appropriate currentmonth ";
        }
        if (depoMonth < 1 || depoMonth > 12)
        {
            "Enter appropriate depoMoth ";
        }
        return false;
    }
    return true;
}

int main()
{
    int principal, depositMonth;
    cout << "What is your deposit amount : ";
    cin >> principal;
    cout << "Enter your amount deposit month : ";
    cin >> depositMonth;
    int rate;
    cout << "Enter rate of interset : ";
    cin >> rate;
    int currentMonth;
    cout << "Enter currentMonth : ";
    cin>>currentMonth;
    
    int totalmonths = currentMonth - depositMonth;
    if (validations(principal,rate,currentMonth,depositMonth))
    {

        float balance = currentBalance(principal, rate, totalmonths);
        cout << "Balance of your account is : " << balance <<endl;

        int withdraw;
        cout << "Enter amount to be withdraw : ";
        cin >> withdraw;

        if (balance - withdraw >= 0)
        {
            int remainBalance = balance - withdraw;
            cout << "Your remaining balance is : " << remainBalance;
        }
        else
        {
            cout << "Insufficient balance to withdraw given amount ";
        }
    }
}