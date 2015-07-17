#include <iostream>
#include "list.h"

using namespace std;

void testAssert(string msg)
{
	cout << "=========================== Test " << msg << " ==================================" << endl;
}

void findObjAssert(void* p, int searchInt) {
	if (p != NULL) {
		cout << "Found " << searchInt << " in list." << endl;
	}else {
		cout << "Can not found " << searchInt << " in list." << endl;
	}
}

int main()
{
	// Init
	testAssert("init 100");
	List mylist = List(100);
	List::Position p = mylist.getLast();
	mylist.show();

	// insert before
	testAssert("insert before");
	int i;
	for(i = 0; i < 10; i++) {
		p = mylist.insert(i, p, List::BEFORE);
	}
	mylist.show();

	// insert after
	testAssert("insert after");
	p = mylist.getLast();
	for(i = 0; i < 10; i++) {
		p = mylist.insert(i, p, List::AFTER);
	}
	mylist.show();

	// clear
	testAssert("clear");
	mylist.clear();
	mylist.show();

	// init
	testAssert("init 0~9");
	mylist.init(0);
	p = mylist.getLast();
	for(i = 1; i < 10; i++) {
		p = mylist.insert(i, p, List::AFTER);
	}
	mylist.show();

	// find
	testAssert("find()");
	mylist.show();
	findObjAssert(mylist.find(5), 5);
	findObjAssert(mylist.find(10), 10);

	// delete
	testAssert("deleteNode(1)");
	findObjAssert(mylist.find(1), 1);
	mylist.deleteNode(1);
	findObjAssert(mylist.find(1), 1);
	mylist.show();


	testAssert("deleteNode(p)");
	findObjAssert(mylist.find(7), 7);
	mylist.deleteNode(mylist.find(7));
	findObjAssert(mylist.find(7), 7);
	mylist.show();
	return 0;
}
