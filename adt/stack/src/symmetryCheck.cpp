//
//  symmetryCheck.cpp
//  stack-symmetry-check
//
//  Created by Jerry on 9/23/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#include <string>
#include <map>
#include <utility>
#include "stack.h"

using std::string;
using std::map;
using std::pair;
using std::cout;
using std::endl;

// 对称性检查函数
pair<bool, string>
check(const string &s) {
    map<string, string> clist = {
        {"(", ")"}, {"{", "}"}, {"[", "]"}, {"<", ">"}
    };
    
    Stack<string> stack(500);
    for(size_t i = 0; i < s.size(); ++i) {
        string c(s, i, 1);
        for (const auto &it : clist) {
            if (it.first == c) {
                stack.push(c);
                break;
            } else if (it.second == c) {
                if (stack.isEmpty()) {
                    string msg("except ");
                    msg += it.first;
                    return {false, msg};
                }
                string sym = stack.popAndTop();
                if (sym != it.first) {
                    string msg("except ");
                    msg += it.first;
                    msg += " but not ";
                    msg += sym;
                    return {false, msg};
                }
                break;
            }
        }
    }
    
    if (stack.isEmpty()) {
        return {true, ""};
    } else {
        return {false, "stack is not empty"};
    }
}

void resulrHandler(const pair<bool, string> &res)
{
    if (res.first){
        cout << "right" << endl;
    } else {
        cout << res.second << endl;
    }
}

int main(int argc, char **argv)
{
    pair<bool, string> res;
    res = check("[a]");
    resulrHandler(res);
    
    res = check("[(aOO])");
    resulrHandler(res);
    
    return 0;
}