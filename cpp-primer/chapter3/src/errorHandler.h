// eventQueue.h
#ifndef ERRORHANDLER_H_
#define ERRORHANDLER_H_
#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;
using std::endl;
using std::cout;

void e(string s)
{
	cout << "Error: " << s << endl;
	exit(EXIT_FAILURE);
}

#endif