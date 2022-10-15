#ifndef DSA_ASSI3_HEADER_H
#define dDSA_ASSI3_HEADER_H
#include<iostream>

template<class T>
class ExpressionConversion
{
    stack<T> st;

public:
    string s;
    int precedance(char);
    bool associativity(char);
    T infixToPostfix(T);
    void displayStack();
    T InfixToPrefix(T);
    int postfixCalculation(string);
    int prefixCalculation(string);
    bool validations(T);
};
#endif