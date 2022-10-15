#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class conversionInToPost
{
    stack<char> st;

public:
    string s;
    int precedance(char);
    bool associativity(char);
    string infixToPostfix(string);
    void displayStack();
    string InfixToPrefix(string);
};

void conversionInToPost::displayStack()
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

int conversionInToPost::precedance(char c)
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

bool conversionInToPost::associativity(char c)
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

string conversionInToPost::infixToPostfix(string s)
{
    stack<char> validb;
    string ans;
    int checkOPnt = 0;
    int checkOPtr = 0;
    cout << "Symbol\t\t"
         << "Stack\t\t"
         << "Expression\t\t" << endl;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            checkOPnt++;
            ans += s[i];
            //cout<<"ans string is "<<ans<<endl;
        }
        else if (s[i] == '(')
        {
            validb.push(s[i]);
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                //cout<<"ans string is "<<ans<<endl;
                validb.pop();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (i == 0 || i == s.length())
            {
                return "Expression cant be start with operator ";
            }
            checkOPtr++;
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

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        cout << s[i] << "\t\t";
        displayStack();
        cout << "\t\t" << ans << endl;
    }
    ans += st.top();
    cout << s[i] << "\t\t";
    displayStack();
    cout << "\t\t" << ans << endl;
    if (!validb.empty())
    {
        return "opening and closing brackets are notv same in number";
    }
    if (((checkOPnt - 1) != checkOPtr))
    {
        return "number of operators and operands are not balance ";
    }
    return ans;
}

int main()
{
    conversionInToPost obj;
    cout << "Enter a Infix expression :";
    cin >> obj.s;
    cout << "Postfix Expression is : " << obj.infixToPostfix(obj.s);
    // cout<<obj.infixToPostfix("a+b*c^d^e-f/g*h");
    // cout<<obj.infixToPostfix("a^b^c");
}