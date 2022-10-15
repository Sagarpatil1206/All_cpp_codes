#include <bits/stdc++.h>

using namespace std;

template<class T>
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
    bool validations(string);
};

template<class T>
bool conversionInToPost<T>::validations(string str){
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
void conversionInToPost<T>::displayStack()
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
int conversionInToPost<T>::precedance(char c)
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
bool conversionInToPost<T>::associativity(char c)
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
string conversionInToPost<T>::infixToPostfix(string s)
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

    while (!st.empty())
    {
        ans += st.top();
        //cout<<"ans string is "<<ans<<endl;
        st.pop();
        cout << s[i] << "\t\t";
        displayStack();
        cout << "\t\t" << ans << endl;
    }
    // ans += st.top();
    // cout << s[i] << "\t\t";
    // displayStack();
    // cout << "\t\t" << ans << endl;

    return ans;
}

template<class T>
string conversionInToPost<T>::InfixToPrefix(string s)
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

template<class T>
int  conversionInToPost<T> :: postfixCalculation(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');

        }else{
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();

            switch (s[i])
            {
            case  '+':st.push(op1+op2);break;
            
            case '-':st.push(op1-op2);break;

            case '*':st.push(op1*op2);break;

            case '/':st.push(op1/op2);break;

            case '^':st.push(pow(op1,op2));break;

            }
        }
    }
    return st.top();
}

template<class T>
int conversionInToPost<T> :: prefixCalculation(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');

        }else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch (s[i])
            {
            case  '+':st.push(op1+op2);break;
            
            case '-':st.push(op1-op2);break;

            case '*':st.push(op1*op2);break;

            case '/':st.push(op1/op2);break;

            case '^':st.push(pow(op1,op2));break;

            }
        }
    }
    return st.top();
}

int main()
{
    int op,cont;string z;

    do{
        conversionInToPost<int> obj;
        cout<<"Select operation to be perform :\n1:Infix to Postfix  2:Infix to prefix  3:Evaluate postfix  4:Evaluate prefix"<<endl;
        cin>>op;
        cout << "Enter a appropriate expression :";
        cin >> obj.s;
        switch (op)
        {
            case 1:
            cout << "Postfix Expression is : " << obj.infixToPostfix(obj.s)<<endl;break;

            case 2:
            cout << "Prefix Expression is : " << obj.InfixToPrefix(obj.s)<<endl;break;

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