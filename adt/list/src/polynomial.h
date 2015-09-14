// polynomial.h
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

class polynomial;
ostream &operator<<(ostream &, const polynomial &);

class polynomial
{
friend ostream &operator<<(ostream &, const polynomial &);
private:
	char x = 'x';  // 未知数表示符号
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
	list<item>::iterator find(int coefficient);
	void push(const item &i);

	// 操作符
	polynomial operator+(const polynomial &rhs) const;
	polynomial operator-(const polynomial &rhs) const;
	polynomial operator*(const polynomial &rhs) const;

	char getVarName() const {
		return x;
	}
};

