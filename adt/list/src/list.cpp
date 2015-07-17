#include <iostream>
#include "list.h"

using namespace std;

List::List(ElementType e)
{
	head = NULL;
	last = NULL;
	List::init(e);
}

List::Position List::init(ElementType e)
{
	if(head == NULL && last == NULL) {
		Node * newNode = new struct Node;
		newNode->data = e;
		newNode->next = NULL;
		newNode->before = NULL;
		head = newNode;
		last = newNode;
	}

	return head;
}

bool List::isEmpty()
{
	return (head == NULL);
}

List::Position List::getHead()
{
	return head;
}

List::Position List::getLast()
{
	return last;
}

List::Position List::getNext(List::Position p)
{
	return p->next;
}

List::Position List::getBefore(List::Position p)
{
	return p->before;
}

List::Position List::insert(ElementType e, List::Position p, List::INSERT_TYPE type)
{
	Node * newNode = new struct Node;
	newNode->data = e;
	newNode->next = NULL;
	newNode->before = NULL;

	if( type == BEFORE) {
		if (p->before == NULL) {
			head = newNode;
			newNode->next = p;
			p->before = newNode;
		} else{
			List::Position pBefore;

			pBefore = p->before;

			newNode->before = pBefore;
			newNode->next = p;

			p->before = newNode;

			pBefore->next = newNode;

		}
	} else if( type == AFTER) {
		if (p->next == NULL) {
			last = newNode;
			newNode->before = p;
			p->next = newNode;
		} else {
			List::Position pNext;

			pNext = p->next;

			newNode->before = p;
			newNode->next = pNext;

			p->next = newNode;

			pNext->before = newNode;
		}
	}

	return newNode;
}

List::Position List::find(ElementType e)
{
	List::Position p;
	p = head;

	while(p != NULL && p->data != e) {
		p = p->next;
	}

	return p;
}

bool List::deleteNode(ElementType e)
{
	List::Position p;
	p = find(e);
	return List::deleteNode(p);
}

bool List::deleteNode(Position p)
{
	if ( p != NULL ) {
		List::Position pBefore = p->before;
		List::Position pNext = p->next;
		
		if(pBefore != NULL) {
			pBefore->next = pNext;
		}
		if(pNext != NULL) {
			pNext->before = pBefore;
		}
		delete p;

		return true;
	} else {
		return false;
	}
}

void List::clear()
{
	List::Position p,tmp;
	p = head;
	while(p != NULL) {
		tmp = p->next;
		delete p;
		p = tmp;
	}
	head = NULL;
	last = NULL;
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
	List::clear();
}