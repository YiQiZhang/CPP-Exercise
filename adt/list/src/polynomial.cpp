//
//  polynomial.cpp
//  polynomial
//
//  Created by Jerry on 9/14/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#include <cmath>
#include <list>
#include <string>
#include <initializer_list>
#include <algorithm>
#include "polynomial.h"

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::ostream;
using std::sort;

polynomial::polynomial(std::initializer_list<item> il)
{
    for(auto beg = il.begin(); beg != il.end(); ++beg) {
        
        data.push_back(*beg);
    }
    
    data.sort([](const item &lhs, const item &rhs){
        
        return lhs.exponent < rhs.exponent;
    });
}

polynomial::polynomial(const polynomial &p) :
x(p.x), data(p.data)
{
    // nomore
}

polynomial::polynomial(polynomial &&p) noexcept :
x(p.x)
{
    data = std::move(p.data);
}

polynomial &polynomial::operator=(const polynomial &p)
{
    x = p.x;
    data = p.data;
    return *this;
}

polynomial &polynomial::operator=(polynomial &&p) noexcept
{
    x = p.x;
    data = std::move(p.data);
    
    return *this;
}

polynomial::~polynomial()
{
    
}

list<item>::iterator polynomial::find(int exponent)
{
    auto it = data.begin();
    for(; it != data.end(); ++it) {
        if(it->exponent == exponent) {
            return it;
        }
    }
    
    return it;
}

void polynomial::push(const item &i)
{
    auto it = data.begin();
    
    for(; it != data.end(); ++it) {
        if (it->exponent == i.exponent) {
            it->coefficient += i.coefficient;
            break;
        } else if(it->exponent > i.exponent) {
            data.insert(it, i);
            break;
        }
    }

    if(it == data.end()) {
        data.insert(it, i);
    }
}

polynomial polynomial::operator+(const polynomial &rhs) const
{
    polynomial p(*this);
    for(const auto &i : rhs.data) {
        p.push(i);
    }
    
    return p;
}

polynomial polynomial::operator-(const polynomial &rhs) const
{
    polynomial p(*this);
    for (const auto &i : rhs.data) {
        item newItem(-i.coefficient, i.exponent);
        p.push(newItem);
    }
    
    return p;
}

polynomial polynomial::operator*(const polynomial &rhs) const
{
    polynomial p;
    for(const auto &i : this->data) {
        for(const auto &j : rhs.data) {
            int newCoefficient = i.coefficient * j.coefficient;
            int newExponent = i.exponent + j.exponent;
            
            item newItem(newCoefficient, newExponent);
            p.push(newItem);
        }
    }
    
    return p;
}

std::ostream &operator<<(std::ostream &os, const polynomial &p)
{
    bool isFirst = true;
    for(const auto &i : p.data) {
        if (i.coefficient == 0) {
            continue;
        }
        
        if(!isFirst) {
            if (i.coefficient > 0) {
                cout << "+ ";
            } else {
                cout << "- ";
            }
        }
        isFirst = false;
        
        int outCoefficient = abs(i.coefficient);
        if (outCoefficient != 1) {
            os << outCoefficient;
        }
        
        os << p.getVarName();
        
        if(i.exponent != 1) {
            os << "^" << i.exponent;
        }
        
        os << " ";
    }
    
    return os;
}