// nifixExpression.cpp

#include <iostream>
#include <string>
#include "calculate.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	string expression;

	cout << "please enter expression or q to quit: ";
	while(getline(cin, expression)) {
		if (expression == "q") break;

		string newExpression = nifixExpressionToSuffixExpression(expression);
		cout << expression << " transform to " << newExpression << " = " << suffixCalculate(newExpression) << endl;

		cout << "please enter expression or q to quit: ";
	}
	cout << "done!" << endl;

	return 0;
}