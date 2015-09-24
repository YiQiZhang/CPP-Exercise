// suffixCalculator.cpp

#include <iostream>
#include <string>
#include "calculate.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	string s;

	cout << "please give a expression or q to quit: ";
	while(getline(cin, s)) {
		if (s == "q") break;

		cout << s << " = "<< suffixCalculate(s) << endl;
		cout << "please give a expression or q to quit: ";
	}
	cout << "done!" << endl;

	return 0;
}