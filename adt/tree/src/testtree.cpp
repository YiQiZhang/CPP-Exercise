//
//  main.cpp
//  normaltree
//
//  Created by Jerry on 9/27/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "tree.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void putIn(const std::vector<string> l, Tree<string> tree, Tree<string>::position p)
{
    for (const auto name : l) {
        tree.insertAsChild(name, p);
    }
}

void testTree()
{
    Tree<string> fs("Jerry");
    
    vector<string> level1 = {"Document", "Picture", "Video", "Application"};
    putIn(level1, fs, fs.getRoot());
    cout << fs << endl;
    
    vector<string> level2forDocument = {"file1", "file2", "file3.txt"};
    putIn(level2forDocument, fs, fs.find("Document"));
    cout << fs << endl;
    
    vector<string> level3forFile3 = {"subfile1", "subfile2", "subfile3", "hehe.json"};
    putIn(level3forFile3, fs, fs.find("file3.txt"));
    cout << fs << endl;
}

int main(int argc , char **argv)
{
    testTree();
    
    return 0;
}