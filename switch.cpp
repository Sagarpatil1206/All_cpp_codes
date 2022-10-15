#include<iostream>
using namespace std;
int main()
{
    int age=23;
    switch(age){
        case 16:
        cout<<"Too Young";
        break;
        case 25:
        cout<<"Adult";
        break;
        case 65:
        cout<<"Senior";
        break;
        default:
        cout<<"This is not specified";
    }
    return 0;
}
/*usually we use switch in a case in which we have so many conditions for a particular value and we have to use "if"  loop so many times then
to avoid this we use switch*/