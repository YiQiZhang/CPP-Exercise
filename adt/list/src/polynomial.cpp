// polynomial.cpp

#include <list>
#include <string>
#include <initializer_list>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::ostream;
using std::sort;

polynomial::polynomial(std::initializer_list<item> il)
{
	sort(il.begin(), il.end(), [](const item &a, const item &b){
		return a.coefficient < b.coefficient;
	});

	for(auto beg = il.begin(); beg != il.end(); ++beg) {

		data.push_back(*item);
	}
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

polynomial &polynomial::operator=(const polynomial &p) :
	x(p.x), data(p.data)
{
	return *this;
}

polynomial &polynomial::operator=(polynomial &&p) : 
	x(p.x)
{
	data = std::move(p.data);

	return *this;
}

polynomial::~polynomial()
{
	cout << *this;
	cout << "Destory!";
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
	bool isInserted = false;
	auto it = data.begin();

	if(it == data.end()) {
		data.insert(it, i);

	} else {
		for(; it != data.end(); ++it) {
			if (it->exponent == i.exponent) {
				it->coefficient += i.coefficient;
				break;
			} else if(it->exponent > i.exponent) {
				data.insert(it, i);
				break;
			}
		}
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
	return operator+(rhs);
}

polynomial polynomial::operator*(const polynomial &rhs) const
{
	polynomial p;
	for(const auto &i : this->data) {
		for(const auto &j : rhs.data) {
			int newCoefficient = i->coefficient * j->coefficient;
			int newExponent = i->exponent + j->exponent;

			item newItem(newCoefficient, newExponent);
			push(newItem);
		}
	}

	return p;
}

std::ostream &operator<<(std::ostream &os, const polynomial &p)
{
	for(const auto &i : p.data) {
		os << i->coefficient << p.getVarName();
		if(i->exponent != 1) {
			os << "^" << i->exponent;
		}

		os << " ";
	}

	return os;
}