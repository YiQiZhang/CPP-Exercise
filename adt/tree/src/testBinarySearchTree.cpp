//
//  testBinarySearchTree.h
//
//  Created by Jerry on 10/1/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#include <iostream>
#include "binarySearchTree.h"

using std::cout;
using std::endl;

void testBinarySearchTree()
{
	cout << "Test build tree: " << endl;
	BinarySearchTree<int> tree(6);
	tree.insert(2);
	tree.insert(8);
	tree.insert(1);
	tree.insert(5);
	tree.insert(3);
	tree.insert(4);
	cout << tree << endl;

	cout << "Test find: " << endl;
	BinarySearchTree<int>::position p;
	BinarySearchTree<int>::valueType ele(6);
	p = tree.find(ele);
	cout << "element: " << p->element << "; count: "<< p->count << endl;
	ele = 7;
	p = tree.find(ele);
	if (p == NULL) {
		cout << "found no " << ele << endl;
	} else {
		cout << "element: " << p->element << "; count: "<< p->count << endl;
	}

	cout << "Test soft delete: " << endl;
	ele = 1;
	tree.softDelete(ele);
	p = tree.find(ele);
	if (p == NULL) {
		cout << "found no " << ele << endl;
	} else {
		cout << "element: " << p->element << "; count: "<< p->count << endl;
	}
	cout << tree << endl;
	cout << "Test hard delete: " << endl;
	ele = 2;
	tree.hardDelete(ele);
	cout << tree << endl;
}

int main(int argc, char **argv)
{
	testBinarySearchTree();
	return 0;
}