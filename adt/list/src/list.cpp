#include <iostream>
#include <stdlib.h>
#include "list.h"

using namespace std;

List::List(ElementType e)
{
	Node * newNode = new struct Node;
	newNode->data = e;
	newNode->next = NULL;
	head = newNode;
}

bool List::isEmpty()
{
	return (head == NULL);
}

Position List::getHead()
{
	return head;
}

Position List::insert(ElementType e, Position p)
{
	Node * newNode = new struct Node;
	newNode->data = e;

	if( p->next != NULL) {
		Position tmp;
		tmp = p->next;
		newNode->next = tmp;
	}else {
		newNode->next = NULL;
	}
	p->next = newNode;

	return newNode;
}

Position List::find(ElementType e)
{
	Position p;
	p = head;

	while(p != NULL && p->data != e) {
		p = p->next;
	}

	return p;
}

void List::show()
{
	if(isEmpty()){
		cout << "The List is empty" << endl;
	}else{
		Position p;
		p = head;
		while(p != NULL) {
			cout << p->data << endl;
			p = p->next;
		}
	}
}

List::~List()
{
	Position p,tmp;
	p = head;
	while(p != NULL) {
		tmp = p->next;
		delete p;
		p = tmp;
	}
}