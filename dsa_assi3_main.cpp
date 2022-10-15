#include<bits/stdc++.h>
using namespace std;
#include "dsa_assi3_header.h"
#include "dsa_assi3_imple.cpp"


int main()
{
    int op,cont;string z;

    do{
        ExpressionConversion<string> obj;
        cout<<"Select operation to be perform :\n1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix"<<endl;
        cin>>op;
        cout << "Enter a appropriate expression :";
        cin >> z;
        switch (op)
        {
            case 1:
            cout << "Postfix Expression is : " << obj.infixToPostfix(z)<<endl;break;

            case 2:
            cout << "Prefix Expression is : " << obj.InfixToPrefix(z)<<endl;break;

            case 3:
            z=obj.s;
            cout << "Postfix Expression is : " << z<<endl;
            for(int i=0;i<z.length();i++){
                if(isalpha(z[i])){
                    int a;cout<<"Enter a value of "<<z[i]<<": ";cin>>a;
                    z[i]='0'+a;
                }
            } cout<<"Z is "<<z<<endl;
            cout<<"Evaluation of postfix is :"<<obj.postfixCalculation(z)<<endl;break;

            case 4:
            z=obj.s;
            cout << "Postfix Expression is : " << z<<endl;
            for(int i=0;i<z.length();i++){
                if(isalpha(z[i])){
                    int a;cout<<"Enter a value of "<<z[i]<<": ";cin>>a;
                    z[i]='0'+a;
                }
            } cout<<"Z is "<<z<<endl;
            cout<<obj.prefixCalculation(z)<<endl;break;

        }
        cout<<"Do you want to continue (1/0) "<<endl;
        cin>>cont;

    }while(cont);
    // cout<<obj.infixToPostfix("a+b*c^d^e-f/g*h");
    // cout<<obj.infixToPostfix("a^b^c"1);
    //46+2/5*7+  //ab+c/d*e+ //32
    //-+7*45+20  //-+a*bc+de //25
    //a+b*c^d^e-f/(j-k)
}

// Select operation to be perform :
// 1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix
// 1
// Enter a appropriate expression :a+b*c^d^e-f/g*h
// Symbol          Stack           Expression
// a                               a
// +               +               a
// b               +               ab
// *               + *             ab
// c               + *             abc
// ^               + * ^           abc
// d               + * ^           abcd
// ^               + * ^ ^                 abcd
// e               + * ^ ^                 abcde
// -               -               abcde^^*+
// f               -               abcde^^*+f
// /               - /             abcde^^*+f
// g               - /             abcde^^*+fg
// *               - *             abcde^^*+fg/
// h               - *             abcde^^*+fg/h
//                 -               abcde^^*+fg/h*
//                                 abcde^^*+fg/h*-
// Postfix Expression is : abcde^^*+fg/h*-
// Do you want to continue (1/0)
// 1
// Select operation to be perform :
// 1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix
// 2
// Enter a appropriate expression :a+b*c^d^e-f/g*h
// Prefix Expression is : -+a*b^c^de*/fgh
// Do you want to continue (1/0)
// 1
// Select operation to be perform :
// 1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix
// 3
// Enter a appropriate expression :ab+c/d*e+
// Postfix Expression is : ab+c/d*e+
// Enter a value of a: 4
// Enter a value of b: 6
// Enter a value of c: 2
// Enter a value of d: 5
// Enter a value of e: 7
// Z is 46+2/5*7+
// Evaluation of postfix is :32
// Do you want to continue (1/0)
// 1
// Select operation to be perform :
// 1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix
// 4
// Enter a appropriate expression :-+a*bc+de
// Postfix Expression is : -+a*bc+de
// Enter a value of a: 7
// Enter a value of b: 4
// Enter a value of c: 5
// Enter a value of d: 2
// Enter a value of e: 0
// Z is -+7*45+20
// 25
// Do you want to continue (1/0)
// 1
// Select operation to be perform :
// 1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix
// 1
// Enter a appropriate expression :*a+b*c^d^e-f/g*h
// Postfix Expression is : Entered expression is INVALID
// Do you want to continue (1/0)
// 1
// Select operation to be perform :
// 1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix
// 2
// Enter a appropriate expression :a+b*c^d^e-f/(d*j
// Prefix Expression is : Entered expression is INVALID
// Do you want to continue (1/0)
// 1
// Select operation to be perform :
// 1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix
// 1
// Enter a appropriate expression :a+b*c^d^e-f/*h+k
// Postfix Expression is : Entered expression is INVALID
// Do you want to continue (1/0)
// 0
// PS C:\Users\dell\Desktop\C++ programs\C++ Files> 