#include<bits/stdc++.h>
#include "dsa_assi3_header.h"

using namespace std;

template<class T>
bool ExpressionConversion<T>::validations(T str){
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

template<class T>
void ExpressionConversion<T>::displayStack()
{

    if (st.empty())
    {
        return;
    }

    int topElement = st.top();
    st.pop();

    displayStack();

    cout << char(topElement) << " ";

    st.push(topElement);
}

template<class T>
int ExpressionConversion<T>::precedance(char c)
{
    if (c == '^')
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

template<class T>
bool ExpressionConversion<T>::associativity(char c)
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

template<class T>
T ExpressionConversion<T>::infixToPostfix(T s)
{
    if(validations(s)){return "Entered expression is INVALID";}
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

template<class T>
T ExpressionConversion<T>::InfixToPrefix(T s)
{
    if(validations(s)){return "Entered expression is INVALID";}
    int i;
    reverse(s.begin(), s.end());
    stack<char> st;
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            
            while (!st.empty() && ((precedance(st.top()) > precedance(s[i])) ||
                                   (precedance(st.top()) == precedance(s[i]) && associativity(st.top()) == 0 && associativity(s[i]) == 0)))
            {
                ans += st.top();
                
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}