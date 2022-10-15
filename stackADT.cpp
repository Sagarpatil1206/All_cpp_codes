#include<iostream>
#include "stack_header.h"
using namespace std;

template<class T>
void stack<T>::push(){
        if(top==n-1){cout<<"\nStack overflow !!!";return;}
        T x;
        cout<<"Enter number to be push :";
        cin>>x;
        top++;
        arr[top]=x;
        cout<<'\n'<<x<<" is added at position "<<top<<endl;
    }

template<class T>
void stack<T>::pop(){
        if(top==-1){cout<<"\nStack is underflow";return;}
        cout<<"Element "<<arr[top]<<" is removed"<<endl;
        top--;
    }

template<class T>
void stack<T>:: peek(){
        if(top==-1){
            cout<<"\nstack is empty ,so no element at top "<<endl;
        }
        cout<<"\nElement at top is "<<arr[top];
    }


template<class T>
void stack<T>:: display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }

template<class T>
bool stack<T>:: empty(){
        if(top==-1){
            return 1;
        }else{return 0;}
    }
    using namespace std;
class Convert
{
public:
    bool isOperator(char);
    string toPostfix(string);
    string toPrefix(string);
    double evaluate_postfix(string);
    double evaluate_prefix(string);
    double evaluate(double, double, char);
    int precedence(char);
    bool validations(string);
};

bool Convert::validations(string str){
    int checkOprand=0;int checkOptr=0;
    int checkopeB=0;int checkclosB=0;
    for(int i=0;i<str.length();i++){

        if(isalpha(str[i])){checkOprand++;}
        else if(str[i]!='(' && str[i]!=')'){
            checkOptr++;
            if(i==0 || i==(str.length()-1)){return 1;}
        }else if(str[i]=='('){
            checkopeB++;
        }else if(str[i]==')'){
            checkclosB++;
        }
    }
    if(((checkOprand-1)!=checkOptr) || (checkclosB!=checkopeB)){return 1;}else{return 0;}
}

//-----------------------------definition of isOperator method---------------------------
bool Convert::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}
//----------------------------------definition to check precedence of operator----------------
int Convert::precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}
//--------------------------------------definition of method to convert expression into postfix-------------------
string Convert::toPostfix(string infix)
{
    if(validations(infix)){return "Entered expression is INVALID";}
    StackAdt<char> s;
    string postfix = "";
    int len = infix.length();
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "\tConversion:" << endl
         << "Scan"
         << "\t"
         << "Stack"
         << "\t"
         << "Expression" << endl;
    for (int i = 0; i < len; i++)
    {
        //-----------1.If it is operand----------------------
        if (isalpha(infix[i]))
            postfix += infix[i];
        //---------2.If it is (---------------------------
        else if (infix[i] == '(')
            s.push(infix[i]);
        //--------3.If it is )------------------------------
        else if (infix[i] == ')')
        {
            while ((s.peep() != '(') && (!s.isEmpty()))
            {
                postfix += s.pop();
            }
            if (s.peep() == '(')
                s.pop();
        }
        //-----------4.If it is operator
        else if (isOperator(infix[i]))
        {
            //----4.1.If stack is empty or contains ( at top---
            if ((s.isEmpty()) || (s.peep() == '('))
                s.push(infix[i]);
            //---4.2.If precedence of operator in expression is greater than that of operator in stack---
            else if (precedence(infix[i]) > precedence(s.peep()))
                s.push(infix[i]);
            //---4.3. If the precedence of operator in expression is smaller than that of operator in stack---
            else
            {
                while ((!s.isEmpty()) && (precedence(infix[i]) <= precedence(s.peep())))
                {
                    postfix += s.pop();
                }
                s.push(infix[i]);
            }
        }
        //------------else the expression is invalid------------------------
        /*else{
cout<<"\t***Invalid expression***"<<endl;
}*/
        //-----------------display symbol scanned, current status of stack and expression------------------------
        cout << infix[i] << "\t";
        s.display();
        cout << "\t" << postfix << endl;
    }
    while (!s.isEmpty())
        postfix += s.pop();
    cout << "------------------------------------------------------------------------------------------------" << endl;
    return postfix;
}
//-------------------------------------------------definition of method to convert into prefix------------------------------
string Convert::toPrefix(string infix)
{
    if(validations(infix)){return "Entered expression is INVALID";}
    StackAdt<char> s;
    string reverse = "";
    string prefix = "";
    int len = infix.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
        reverse += infix[i];
    }
    reverse = toPostfix(reverse);
    for (int i = reverse.length() - 1; i >= 0; i--)
        prefix += reverse[i];
    return prefix;
}
//-----------------------------------------------definition of evaluate method--------------------------------------------------
double Convert::evaluate(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return (a + b);
        break;
    case '-':
        return (a - b);
        break;
    case '*':
        return (a * b);
        break;
    case '/':
        return (a / b);
        break;
    case '^':
        return (pow(a, b));
        break;
    default:
        cout << "****Invalid values***";
        return 0;
    }
}
//-----------------------------------------------definition of postfix expression evaluation----------------------------------------------
double Convert::evaluate_postfix(string exp)
{
    double result;
    StackAdt<double> s;
    double op1, op2, val;
    int len = exp.length();
    for (int i = 0; i < len; i++)
    {
        if (isalpha(exp[i]))
        {
            cout << "Enter value of " << exp[i] << ":";
            cin >> val;
            s.push(val);
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();
            result = evaluate(op1, op2, exp[i]);
            s.push(result);
        }
    }
    return result;
}
//-----------------------------definition of prefix expression evaluation----------------------------------------------------------
double Convert::evaluate_prefix(string exp)
{
    double result;
    StackAdt<double> s;
    double op1, op2, val;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (isalpha(exp[i]))
        {
            cout << "Enter value of " << exp[i] << ":";
            cin >> val;
            s.push(val);
        }
        else
        {
            op1 = s.pop();
            op2 = s.pop();
            result = evaluate(op1, op2, exp[i]);
            s.push(result);
        }
    }
    return result;
}
