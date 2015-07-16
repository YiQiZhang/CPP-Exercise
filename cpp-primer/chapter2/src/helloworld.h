#ifndef __HELLOWORLD_H_
#define __HELLOWORLD_H_

#include <iostream>
#include <string>

using namespace std;

class HelloWorld
{
private:
  string name;
public:
  HelloWorld();
  HelloWorld(const std::string &s);
  ~HelloWorld();
};
#endif