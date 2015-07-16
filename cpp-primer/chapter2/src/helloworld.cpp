#include "helloworld.h"

HelloWorld::HelloWorld()
{
	HelloWorld("");
}

HelloWorld::HelloWorld(const std::string &s)
{
	using namespace std;
	name = s;
	cout << "hello world " << name << endl;
}

HelloWorld::~HelloWorld()
{
	cout << "goodbye world" << endl;
}