#include<iostream>
using namespace std;
int main()
{int n;
cin>>n;
   do{cout<<n<<endl;
    cin>>n;} 
    while(n>0);
    return 0;
}
/*so basically it's like while loop but it first execute do wala statement first meanse atleast once a time
    (and actually first a time as well)and then go for regular while loop whose condition is written over there and sttement in curly brackets in front of do*/
    /* The do...while loop executes the sttements at least once, and then the condition.
    The while loop executes the statements after testing condition.
    that is if condition in while loop is evaluated false,statement in do would still run once*/