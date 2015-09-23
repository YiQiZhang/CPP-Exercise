// symmetryCheck.cpp

#include <string>
#include <map>
#include <utility>
#include "stack.h"

using std::string;
using std::map;
using std::pair;

// 对称性检查函数
pair<bool, string>
check(const string &s) {
  map<string, string> clist = {
  	{"(", ")"}, {"{", "}"}, {"[", "]"}, {"<", ">"}
  };
  
  Stack<string> stack(500);
  for(const auto c : s) {
    for (auto it : clist) {
      if (it->first == c) {
        stack.push(c);
        break;
      } else if (it->second == c) {
        if (stack.isEmpty()) {
          string msg("except ");
          msg += it->first;
          return {false, msg};
        }
        string sym = stack.popAndTop();
        if (sym != it->first) {
          string msg("except ");
          msg += it->first;
          msg += " but not ";
          msg += sym;
          return {false, msg};
        }
        break;
      }
    }
  }
}

int main(int argc, char **argv)
{

	return 0;
}  