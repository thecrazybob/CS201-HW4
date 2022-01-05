// Mohammed Sohail
// 22001513

#include "Stack.h"
#include <string>

using namespace std;

// It converts an infix expression exp to its equivalent prefix form.
string infix2prefix(const string exp);

// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix(const string exp);

// It converts a prefix expression exp to its equivalent infix form.
string prefix2infix(const string exp);

// It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix(const string exp);

// It converts a postfix expression exp to its equivalent infix form.
string postfix2infix(const string exp);

// It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix(const string exp);

// It evaluates an infix expression.
double evaluateInfix(const string exp);

// It evaluates a prefix expression.
double evaluatePrefix(const string exp);

// It evaluates a postfix expression.
double evaluatePostfix(const string exp);

// It evaluates the precedence of the input operator
int checkPrecedence(char operatorChar);

// It evaluates whether the input is an operator
bool isOperator(char operatorChar);

// It converts a char to string
string charToString(char charInput);

// It alternates the value
string alternate(const string str);

// It evaluates the value
string eval(string str1, string str2, char operatorChar);
