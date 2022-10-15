#include <bits/stdc++.h>
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
    int postfixCalculation(string);
    int prefixCalculation(string);
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
            if (i == 0 || i == s.length() - 1)
            {
                return "Expression can't be start or end with operator ";
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

string conversionInToPost::InfixToPrefix(string s)
{
    stack<char> validb;
    int checkOPnt = 0;
    int checkOPtr = 0;
    int i;
    reverse(s.begin(), s.end());
    stack<char> st;
    string ans;
    // cout << "Symbol\t\t"
    //      << "Stack\t\t"
    //      << "Expression\t\t" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans += s[i];
            checkOPnt++;
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
            validb.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
                validb.pop();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (i == 0 || i == s.length() - 1)
            {
                return "Expression can't be start or end with operator ";
            }
            checkOPtr++;
            while (!st.empty() && ((precedance(st.top()) > precedance(s[i])) ||
                                   (precedance(st.top()) == precedance(s[i]) && associativity(st.top()) == 0 && associativity(s[i]) == 0)))
            {
                ans += st.top();

                st.pop();
            }
            st.push(s[i]);
            // }cout << s[i] << "\t\t";
            // displayStack();
            // cout << "\t\t" << ans << endl;
        }

        if (!st.empty())
        {
            ans += st.top();
            st.pop();
            // cout << s[i] << "\t\t";
            // displayStack();
            // cout << "\t\t" << ans << endl;
        }
        // ans += st.top();
        // cout << s[i] << "\t\t";
        // displayStack();
        // cout << "\t\t" << ans << endl;

        if (!validb.empty())
        {
            return "opening and closing brackets are notv same in number";
        }
        if (((checkOPnt - 1) != checkOPtr))
        {
            return "number of operators and operands are not balance ";
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    int conversionInToPost ::postfixCalculation(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                st.push(s[i] - '0');
            }
            else
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                switch (s[i])
                {
                case '+':
                    st.push(op1 + op2);
                    break;

                case '-':
                    st.push(op1 - op2);
                    break;

                case '*':
                    st.push(op1 * op2);
                    break;

                case '/':
                    st.push(op1 / op2);
                    break;

                case '^':
                    st.push(pow(op1, op2));
                    break;
                }
            }
        }
        return st.top();
    }

    int conversionInToPost ::prefixCalculation(string s)
    {
        stack<int> st;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                st.push(s[i] - '0');
            }
            else
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                switch (s[i])
                {
                case '+':
                    st.push(op1 + op2);
                    break;

                case '-':
                    st.push(op1 - op2);
                    break;

                case '*':
                    st.push(op1 * op2);
                    break;

                case '/':
                    st.push(op1 / op2);
                    break;

                case '^':
                    st.push(pow(op1, op2));
                    break;
                }
            }
        }
        return st.top();
    }

    int main()
    {
        int op, cont;

        do
        {
            conversionInToPost obj;
            cout << "Select operation to be perform :\n1:Infix to Postfix 2:Infix to prefix 3:Evaluate postfix 4:Evaluate prefix" << endl;
            cin >> op;
            cout << "Enter a appropriate expression :";
            cin >> obj.s;
            switch (op)
            {
            case 1:
                cout << "Postfix Expression is : " << obj.infixToPostfix(obj.s) << endl;
                break;

            case 2:
                cout << "Prefix Expression is : " << obj.InfixToPrefix(obj.s) << endl;
                break;

            case 3:
                cout << obj.postfixCalculation(obj.s) << endl;
                break;

            case 4:
                cout << obj.prefixCalculation(obj.s) << endl;
                break;
            }
            cout << "Do you want to continue (1/0) " << endl;
            cin >> cont;

        } while (cont);
        // cout<<obj.infixToPostfix("a+b*c^d^e-f/g*h");
        // cout<<obj.infixToPostfix("a^b^c");
        //46+2/5*7+
        //-+7*45+20
}