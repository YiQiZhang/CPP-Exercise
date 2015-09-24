// calculate.h
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <sstream>
#include "error.h"
#include "stack.h"

using std::string;
using std::vector;
using std::istringstream;
using std::map;
using std::istringstream;
using std::ostringstream;
using std::function;

bool isNumber(const string &s) {
	return s.find_first_of(".1234567890") != string::npos ? true : false;
}

double
suffixCalculate(const string &s) {
	Stack<double> stack(500);
	istringstream is(s);
	string op;

	map<string, function<double(double, double)>> binops = {
		{"+", [](double a, double b) { return a + b;}},
		{"-", [](double a, double b) { return a - b;}},
		{"*", [](double a, double b) { return a * b;}},
		{"/", [](double a, double b) { return a / b;}}
	};

	while (is >> op) {
		if (isNumber(op)) {
			stack.push(stod(op));
		} else if (op.size() == 1) {
			auto it = binops.find(op);
			if (it != binops.end()) {
				double a = stack.popAndTop();
				double b = stack.popAndTop();
				double res = binops[op](a, b);
				stack.push(res);
			} else {
				cout << "invalid parameter " << op << endl;
			}
		} else {
			cout << "invalid parameter " << op << endl;
		}
	}

	if (stack.isEmpty()) {
		error("stack empty");
	} else if (stack.size() > 1){
		error("more than 1 element in stack");
	} else {
		return stack.popAndTop();
	}

	return 0.0;
}

bool
isValidOperator(const string &sym)
{
	vector<string> validOpList = {
		"+", "-", "*", "/"
	};

	bool res = false;
	for (const string &op : validOpList) {
		if (op == sym) {
			res = true;
			break;
		}
	}
	return res;
}

// 0相等,1左边优先级高,-1右边优先级高,确保输入有效
int
compareOperator(const string &lhs, const string &rhs)
{
	map<string, int> opList = {
		{"+", 1},
		{"-", 1},
		{"*", 2},
		{"/", 2}
	};

	int lhsLevel = opList[lhs];
	int rhsLevel = opList[rhs];
	if (lhsLevel == rhsLevel) {
		return 0;
	} else {
		return lhsLevel < rhsLevel ? -1 : 1;
	}
}

string
nifixExpressionToSuffixExpression(const string &expression)
{
	ostringstream res;
	istringstream is(expression);
	string op;
	Stack<string> stack(500);

	while (is >> op) {
		if (isNumber(op)) {
			res << op << " ";
			continue;
		} else if (op.size() == 1) {
			if (op == "(") {
				stack.push(op);
			} else if (op == ")") {
				while (stack.top() != "(")
					res << stack.popAndTop() << " ";
				stack.pop();
			} else {
				if (!isValidOperator(op)) {
					cout << "invalid parameter: " << op << endl;
					continue;
				}
				
				if (!stack.isEmpty() && compareOperator(stack.top(), op) >= 0) {  // op in stack bigger or equal
					res << stack.popAndTop() << " ";
				}
				stack.push(op);
			}
		} else {
			cout << "invalid parameter: " << op << endl;
		}
	}

	while (!stack.isEmpty()) {
		res << stack.popAndTop() << " ";
	}

	return res.str();
}


















