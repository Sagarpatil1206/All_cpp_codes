#include <iostream>
#include "mock_header.h"
#include "conversionINtoPOSTmock.cpp"
#include "stackImpleMock.cpp"

using namespace std;

int main()
{
    string z;
    ExpressionConversion<string> obj;//creating a object
    cout << "Enter a appropriate expression :";
    cin >> z;
    cout << "Postfix Expression is : " << obj.infixToPostfix(z) << endl;//using the operation infixTopostfix for string

    // cout<<obj.infixToPostfix("a+b*c^d^e-f/g*h");
}

/*
Enter a appropriate expression :a+b*c^d^e-f/g*h
Symbol          Stack           Expression
a                               a
+               +               a
b               +               ab
*               + *             ab
c               + *             abc
^               + * ^           abc
d               + * ^           abcd
^               + * ^ ^                 abcd
e               + * ^ ^                 abcde
-               -               abcde^^*+
f               -               abcde^^*+f
/               - /             abcde^^*+f
g               - /             abcde^^*+fg
*               - *             abcde^^*+fg/
h               - *             abcde^^*+fg/h
                -               abcde^^*+fg/h*
                -               abcde^^*+fg/h*-
Postfix Expression is : abcde^^*+fg/h*-

Enter a appropriate expression :a+b*c^d^e-f/(d*j
Postfix Expression is : Entered expression is INVALID

Enter a appropriate expression :a+b*c^d^e-f/*h+k
Postfix Expression is : Entered expression is INVALID

Enter a appropriate expression :*a+b*c^d^e-f/g*h
Postfix Expression is : Entered expression is INVALID

*/