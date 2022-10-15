#include "mock_header.h"

template <class T>
bool ExpressionConversion<T>::validations(T str)//validations for infix expression
{
    int checkOprand = 0;//for operands 
    int checkOptr = 0;//for operators
    int checkopeB = 0;//for open beackets
    int checkclosB = 0;//for close brackets

    for (int i = 0; i < str.length(); i++)//checking the number of operators ,operands and alphabets in a string
    {

        if (isalpha(str[i]))//
        {
            checkOprand++;
        }
        else if (str[i] != '(' && str[i] != ')')
        {
            checkOptr++;
            if (i == 0 || i == (str.length() - 1))
            {
                return 1;
            }
        }
        else if (str[i] == '(')
        {
            checkopeB++;
        }
        else if (str[i] == ')')
        {
            checkclosB++;
        }
    }
    //if number of operators and (operands-1) are not same and close brackets and opern brackets are not same in number
    if (((checkOprand - 1) != checkOptr) || (checkclosB != checkopeB))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class T>
void ExpressionConversion<T>::displayStack()//display stack
{

    if (st.empty())
    {
        return;
    }

    int topElement = st.top();//
    st.pop();

    displayStack();

    cout << char(topElement) << " ";

    st.push(topElement);
}

template <class T>
int ExpressionConversion<T>::precedance(char c)//checking a precedance of operators
{
    if (c == '^')//setting the precedance
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

template <class T>
bool ExpressionConversion<T>::associativity(char c)//checking associativity 
{
    if (c == '^')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

template <class T>
T ExpressionConversion<T>::infixToPostfix(T s)// for converting infix to postfix
{
    if (validations(s))
    {
        return "Entered expression is INVALID";
    }
    string ans;
    cout << "Symbol\t\t"
         << "Stack\t\t"
         << "Expression\t\t" << endl;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans += s[i];
            //cout<<"ans string is "<<ans<<endl;
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                //cout<<"ans string is "<<ans<<endl;
                st.pop();
            }
            st.pop();
        }
        else
        {

            while (!st.empty() && ((precedance(st.top()) > precedance(s[i])) ||
                                   (precedance(st.top()) == precedance(s[i]) && associativity(st.top()) && associativity(s[i]))))
            {
                ans += st.top();
                //cout<<"ans string is "<<ans<<endl;
                st.pop();
            }
            st.push(s[i]);
        }
        cout << s[i] << "\t\t";
        displayStack();
        cout << "\t\t" << ans << endl;
    }

    if (!st.empty())
    {
        ans += st.top();
        //cout<<"ans string is "<<ans<<endl;
        st.pop();
        cout << s[i] << "\t\t";
        displayStack();
        cout << "\t\t" << ans << endl;
    }
    ans += st.top();
    cout << s[i] << "\t\t";
    displayStack();
    cout << "\t\t" << ans << endl;

    return ans;
}