//
//  testAvlTree.h
//
//  Created by Jerry on 10/6/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#include <iostream>
#include "avlTree.h"

using std::cout;
using std::endl;

template<typename T>
void treeInsert(AvlTree<T> &tree, T a, T b)
{
	cout << "from: " << a << " to " << b << endl;
	if (a < b) {
		for (T i = a; i <= b; ++i) {
			cout << "inserting: " << i << endl;
			tree.insert(i);
			cout << tree << endl;
		}
	} else if (a > b) {
		for (T i = a; i >= b; --i) {
			cout << "inserting: " << i << endl;
			tree.insert(i);
			cout << tree << endl;
		}
	}
	
}

void testAvlTree()
{
	AvlTree<int> tree(3);
	treeInsert(tree, 2, 1);
	treeInsert(tree, 4, 7);
	treeInsert(tree, 16, 10);
	treeInsert(tree, 8, 9);
}

int main(int argc, char **argv)
{
	testAvlTree();

	return 0;
}