#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List mylist = List(1);
	Position p;

	if( mylist.isEmpty() ) {
		cout << "List is Empty" << endl;
	}

	p = mylist.getHead();
	p = mylist.insert(2, p);
	p = mylist.insert(4, p);
	p = mylist.insert(6, p);
	
	int searchObj = 3;

	if (!mylist.find(searchObj)) {
		cout << "List is not include " << searchObj << endl;
	}

	searchObj = 4;
	p = mylist.find(searchObj);
	if ( p != NULL) {
		cout << searchObj << " was found, the next is ";
		if (p->next != NULL) {
			cout << p->next->data << endl;
		} else {
			cout << "nothing" << endl;
		}
	}

	int i = 0;
	p = mylist.getHead();
	for(i = 0; i < 10 ; i++) {
		p = mylist.insert(i, p);
	}

	mylist.show();
	return 0;
}