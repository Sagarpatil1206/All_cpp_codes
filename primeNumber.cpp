#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int i; //declare outside so as to acsess for outside the
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        { 
            cout << "non prime\n";
            break;
        }
    }

    if (i == n)
    {
        cout << "prime" << endl;
    }
    return 0;
}