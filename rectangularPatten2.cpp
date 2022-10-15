#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n; //n=rows
    cin >> m; //m=colums
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << "*";
        }
        cout << endl;
    } //imp step i.e. to add a break
    return 0;
}