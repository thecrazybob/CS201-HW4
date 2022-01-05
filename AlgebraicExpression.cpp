// Mohammed Sohail
// 22001513

#include "AlgebraicExpression.h"
#include <iostream>
#include <sstream>

// It converts an infix expression exp to its equivalent prefix form.
string infix2prefix(const string exp) {

    // String to be returned
    string result;

    // Convert input parameter to postfix by alternating it first
    result = infix2postfix(alternate(exp));

    // Return the prefix by alternating postFixStr again
    return alternate(result);

}

// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix(const string exp) {

    // Temporary variables
    string tmp1;
    string tmp2;

    // Result string
    string postfixStr;

    // Stack
    Stack stack;

    // Length of input
    int length = exp.length();

    // 1. Loop through each character in exp
    for (int i = 0; i < length; i++) {

        // 1.1 If operator
        if (isOperator(exp[i])) {

            // 1.1.1 While stack is not empty and operator has higher preceder -> postfixStr += + Stack.top()
            // 1.1.2 Stack.push(character)

            while (stack.getTop(tmp1) && (tmp1 != "(") && (checkPrecedence(tmp1[0]) >= checkPrecedence(exp[i]))) {

                postfixStr += tmp1;
                postfixStr = postfixStr + ' ';
                stack.pop();

            }

            stack.push(charToString(exp[i]));

        }

        // 1.2 Else If open parenthesis -> Stack.push(character)
        else if (exp[i] == '(') {
            stack.push("(");
        }

        // 1.3 Else If close parenthesis
        else if (exp[i] == ')') {

            // 1.3.1 While Stack.top() != '('
            while (stack.getTop(tmp1) && tmp1 != "(") {
                // 1.3.1.1 postfixStr += character + ' '
                // 1.3.1.2 Stack.pop()
                postfixStr += tmp1;
                postfixStr = postfixStr + ' ';
                stack.pop();
            }

            // 1.3.2 Stack.pop()
            stack.pop();

        }

        else if (exp[i] == ' ') {
            continue;
        }

        // 1.4 Else
        else {
            // 1.4.1 While != ' '
            while (exp[i] != ' ' && i < length)
            {
                // 1.4.1.1 If number, add it to postfixStr + ' '
                tmp2 += exp[i];
                i++;
            }
            postfixStr += tmp2 + " ";
            tmp2 = "";
        }

    }

    while (stack.getTop(tmp1))
    {
        postfixStr += tmp1;
        postfixStr = postfixStr + ' ';
        stack.pop();
    }

    return postfixStr;

}

// It converts a prefix expression exp to its equivalent infix form.
string prefix2infix(const string exp) {

    string infixStr;

    infixStr = postfix2infix(alternate(exp));
    return alternate(infixStr);

}

// It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix(const string exp) {

    // Converted from prefixStr
    string infixStr;

    // String to be returned
    string postfixStr;

    infixStr = prefix2infix(exp);
    postfixStr = infix2postfix(infixStr);

    return postfixStr;

}

// It converts a postfix expression exp to its equivalent infix form.
string postfix2infix(const string exp) {

    // Temporary variables
    string tmp1;
    string tmp2;

    // Stack
    Stack stack;

    // Resulting string
    string result;

    for (int i = 0; i < exp.length(); i++) {

        if (isOperator(exp[i])) {

            stack.getTop(tmp1);
            stack.pop();

            stack.getTop(tmp2);
            stack.pop();

            stack.push("( " + tmp2 + " " + exp[i] + " " + tmp1 + " )");

        }

        else {

            while (exp[i] != ' ') {

                result += exp[i];
                i++;

            }

            if (result != "") {
                stack.push(result);
            }

            result = "";

        }

    }

    while (stack.getTop(tmp1))
    {
        result += tmp1;
        stack.pop();
    }

    return result;

}

// It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix(const string exp) {

    string infixStr;
    string prefixStr;

    infixStr = postfix2infix(exp);

    prefixStr = infix2prefix(infixStr);

    return prefixStr;

}

// It evaluates an infix expression.
double evaluateInfix(const string exp) {

    string prefixStr;

    prefixStr = infix2prefix(exp);

    return evaluatePrefix(prefixStr);

}

// It evaluates a prefix expression.
double evaluatePrefix(const string exp) {

    // Stack
    Stack stack;

    // Result / response variables
    string resultStr;
    double resultDouble;

    // Temporary variables
    string tmp1;
    string tmp2;
    string tmp3;

    for (int i = exp.length() - 1; i >= 0; i--) {

        if (isOperator(exp[i])) {

            stack.getTop(tmp1);
            stack.pop();

            stack.getTop(tmp2);
            stack.pop();

            stack.push(eval(tmp1, tmp2, exp[i]));

        }

        else if (exp[i] == ' ') {

            continue;

        }

        else {

            while (exp[i] != ' ') {

                tmp3 += exp[i];
                i--;

            }

            stack.push(alternate(tmp3));
            tmp3 = "";

        }
    }

    stack.getTop(resultStr);

    stringstream sstream(resultStr);
    sstream >> resultDouble;

    return resultDouble;
}

// It evaluates a postfix expression.
double evaluatePostfix(const string exp) {

    string prefixStr;

    prefixStr = postfix2prefix(exp);

    return evaluatePrefix(prefixStr);

}

int checkPrecedence(char operatorChar) {

    switch (operatorChar) {
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;
    }

}

bool isOperator(char operatorChar) {
    return (operatorChar == '/' || operatorChar == '*' || operatorChar == '+' || operatorChar == '-') ? true : false;
}

string charToString(char charInput) {

    // Init result
    string result = "";

    // Add char to result
    result += charInput;

    // Return result
    return result;

}

string alternate(const string str) {

    // Init result
    string result = "";

    // Reverses the string
    for (int i = str.length() - 1; i >= 0; i--) {

        switch (str[i]) {
            case '(':
                result += ')';
                break;
            case ')':
                result += '(';
                break;
            default:
                result += str[i];
                break;
        }

    }

    // Returns the reversed string
    return result;

}

string eval(string str1, string str2, char operatorChar) {

    // Double result
    double result;

    // Double values
    double valueOne;
    double valueTwo;

    stringstream sstream(str1);
    stringstream sstream2(str2);

    // Input values into sstream
    sstream >> valueOne;
    sstream2 >> valueTwo;

    // Calculate based on input operator
    switch (operatorChar) {

        case '*':
            result = valueOne * valueTwo;
            break;

        case '/':
            result = valueOne / valueTwo;
            break;

        case '+':
            result = valueOne + valueTwo;
            break;

        case '-':
            result = valueOne - valueTwo;
            break;

        default:
            result = 0;
            break;

    }

    // Return string
    ostringstream sstream3;
    sstream3 << result;
    return sstream3.str();

}
