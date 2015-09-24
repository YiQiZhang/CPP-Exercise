// suffixCalculator.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "error.h"
#include "stack.h"

using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::function;

double
suffixCalculate(const string &s) {
	Stack<double> stack(500);
	istringstream is(s);
	string op;

	map<string, function<double, double>> binops = {
		{"+", [](double a, double b) { return a + b;}},
		{"-", [](double a, double b) { return a - b;}},
		{"*", [](double a, double b) { return a * b;}},
		{"/", [](double a, double b) { return a / b;}}
	};

	while (is >> op) {
		if (op.isdigit()) {
			stack.push(stod(op));
		} else if (op.size() == 1) {
			auto it = binops.find(op);
			if (it != binops.end()) {
				double a = stack.popAndTop();
				double b = stack.popAndTop();
				double res = binops[op](a, b);
				stack.push(res);
			} else {
				cout << "invalid parameter" << op << endl;
			}
		} else {
			cout << "invalid parameter" << op << endl;
		}
	}

	if (stack.isEmpty()) {
		error("stack empty");
	} else if (stack.size() > 1){
		error("more than 1 element in stack");
	} else {
		return stack.popAndTop();
	}

	return 0;
}

int main(int argc, char **argv)
{
	return 0;
}