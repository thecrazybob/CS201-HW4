#include "AlgebraicExpression.h"
#include <iostream>

int main() {

    cout << infix2prefix("7 * ( ( 4 + 13 ) / 5 ) - 6") << endl; // - * 7 / + 4 13 5 6
    cout << infix2postfix("7 * ( ( 4 + 13 ) / 5 ) - 6") << endl; // 7 4 13 + 5 / * 6 -
    cout << evaluateInfix("7 * ( ( 4 + 13 ) / 5 ) - 6") << endl; // 17.8

    cout << prefix2infix("+ 46 / * 8 4 2") << endl; // ( 46 + ( ( 8 * 4 ) / 2 ) )
    cout << prefix2postfix("+ 46 / * 8 4 2") << endl; // 46 8 4 * 2 / +
    cout << evaluatePrefix("+ 46 / * 8 4 2") << endl; // 62

    cout << postfix2infix("2 1 4 2 1 + * 3 + + *") << endl; // ( 2 * ( 1 + ( ( 4 * ( 2 + 1 ) ) + 3 ) ) )
    cout << postfix2prefix("2 1 4 2 1 + * 3 + + *") << endl; // * 2 + 1 + * 4 + 2 1 3
    cout << evaluatePostfix("2 1 4 2 1 + * 3 + + *") << endl; // 32

    return 0;

}
