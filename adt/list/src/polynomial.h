//
//  polynomial.h
//  polynomial
//
//  Created by Jerry on 9/14/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#ifndef __polynomial__polynomial__
#define __polynomial__polynomial__

#include <iostream>
#include <list>
#include <string>
#include <initializer_list>

using std::string;
using std::list;
using std::ostream;

struct item
{
private:
    item();
public:
    int coefficient;  // 系数
    int exponent;  // 指数
    item(int c, int e) : coefficient(c), exponent(e) {
        // no more
    }
};

class polynomial
{
    friend ostream &operator<<(ostream &, const polynomial &);
private:
    char x = 'X';  // 未知数表示符号
    list<item> data;
public:
    polynomial() = default;
    polynomial(std::initializer_list<item> il);
    // 拷贝控制成员
    polynomial(const polynomial &);
    polynomial(polynomial &&) noexcept;
    polynomial &operator=(const polynomial &);
    polynomial &operator=(polynomial &&) noexcept;
    ~polynomial();
    
    // util
    // find item by exponent
    list<item>::iterator find(int exponent);
    void push(const item &i);
    
    // 操作符
    polynomial operator+(const polynomial &rhs) const;
    polynomial operator-(const polynomial &rhs) const;
    polynomial operator*(const polynomial &rhs) const;
    
    char getVarName() const {
        return x;
    }
};

#endif /* defined(__polynomial__polynomial__) */
