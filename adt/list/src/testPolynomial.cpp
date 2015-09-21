//
//  testPolynomial.cpp
//  polynomial
//
//  Created by Jerry on 9/14/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#include <iostream>
#include "polynomial.h"

using std::cout;
using std::endl;

void polynomialTestCase()
{
    item i1({1, 1});
    item i2({1, 3});
    polynomial p1({i1, i2});
    polynomial p2({{1,1}});
    polynomial p3(p1);
    
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    
    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 - p1 = " << p2 - p1 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;
    cout << "p1 * p3 = " << p1 * p3 << endl;
    
}

int main(int argc, const char * argv[]) {
    polynomialTestCase();
    
    return 0;
}
