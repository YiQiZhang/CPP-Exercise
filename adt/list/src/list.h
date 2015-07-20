#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
using namespace std;

template <class ElementType>
class List
{
public:
	struct Node;
	typedef struct Node* Position;
	struct Node
	{
		ElementType data;
		List<ElementType>::Position next;
		List<ElementType>::Position before;
	};
	enum INSERT_TYPE {
		AFTER, 
		BEFORE
	};
	List(ElementType e);
	List<ElementType>::Position init(ElementType e);
	bool isEmpty();
	List<ElementType>::Position getHead();
	List<ElementType>::Position getLast();
	List<ElementType>::Position getNext(List<ElementType>::Position p);
	List<ElementType>::Position getBefore(List<ElementType>::Position p);
	List<ElementType>::Position insert(ElementType e, List<ElementType>::Position p, List<ElementType>::INSERT_TYPE type);
	List<ElementType>::Position find(ElementType e);
	bool deleteNode(ElementType e);
	bool deleteNode(List<ElementType>::Position p);
	void clear();
	void show();
	~List();
private:
	List<ElementType>::Position head;
	List<ElementType>::Position last;
};


// Here is the implement

template <class ElementType>
List<ElementType>::List(ElementType e)
{
	head = NULL;
	last = NULL;
	List<ElementType>::init(e);
}

template <class ElementType>
typename List<ElementType>::Position List<ElementType>::init(ElementType e)
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

template <class ElementType>
bool List<ElementType>::isEmpty()
{
	return (head == NULL);
}

template <class ElementType>
typename List<ElementType>::Position List<ElementType>::getHead()
{
	return head;
}

template <class ElementType>
typename List<ElementType>::Position List<ElementType>::getLast()
{
	return last;
}

template <class ElementType>
typename List<ElementType>::Position List<ElementType>::getNext(typename List<ElementType>::Position p)
{
	return p->next;
}

template <class ElementType>
typename List<ElementType>::Position List<ElementType>::getBefore(List<ElementType>::Position p)
{
	return p->before;
}

template <class ElementType>
typename List<ElementType>::Position List<ElementType>::insert(ElementType e, typename List<ElementType>::Position p, typename List<ElementType>::INSERT_TYPE type)
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
			typename List<ElementType>::Position pBefore;

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
			typename List<ElementType>::Position pNext;

			pNext = p->next;

			newNode->before = p;
			newNode->next = pNext;

			p->next = newNode;

			pNext->before = newNode;
		}
	}

	return newNode;
}

template <class ElementType>
typename List<ElementType>::Position List<ElementType>::find(ElementType e)
{
	typename List<ElementType>::Position p;
	p = head;

	while(p != NULL && p->data != e) {
		p = p->next;
	}

	return p;
}

template <class ElementType>
bool List<ElementType>::deleteNode(ElementType e)
{
	typename List<ElementType>::Position p;
	p = find(e);
	return List<ElementType>::deleteNode(p);
}

template <class ElementType>
bool List<ElementType>::deleteNode(typename List<ElementType>::Position p)
{
	if ( p != NULL ) {
		typename List<ElementType>::Position pBefore = p->before;
		typename List<ElementType>::Position pNext = p->next;
		
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

template <class ElementType>
void List<ElementType>::clear()
{
	typename List<ElementType>::Position p,tmp;
	p = head;
	while(p != NULL) {
		tmp = p->next;
		delete p;
		p = tmp;
	}
	head = NULL;
	last = NULL;
}

template <class ElementType>
void List<ElementType>::show()
{
	if(isEmpty()){
		cout << "The List is empty" << endl;
	}else{
		typename List<ElementType>::Position p;
		p = head;
		while(p != NULL) {
			cout << p->data << endl;
			p = p->next;
		}
	}
}

template <class ElementType>
List<ElementType>::~List()
{
	List<ElementType>::clear();
}
#endif