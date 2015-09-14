// testPolynomial.cpp

#include <iostream>
#include "polynomial.h"

using namespace std;

void polynomialTestCase()
{
	item i1({1, 2});
	item i2({1, 3});
	item i3({2, 2});
	polynomial p({i1, i2, i3});

	cout << p << endl;
}

int main(int argc, char **argv)
{
	polynomialTestCase();

	return 0;
}