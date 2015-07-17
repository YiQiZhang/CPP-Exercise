#ifndef _LIST_H_
#define _LIST_H_

#define ElementType int

class List
{
public:
	struct Node;
	typedef struct Node* Position;
	struct Node
	{
		ElementType data;
		List::Position next;
		List::Position before;
	};
	enum INSERT_TYPE {
		AFTER, 
		BEFORE
	};
	List(ElementType e);
	List::Position init(ElementType e);
	bool isEmpty();
	List::Position getHead();
	List::Position getLast();
	List::Position getNext(List::Position p);
	List::Position getBefore(List::Position p);
	List::Position insert(ElementType e, List::Position p, List::INSERT_TYPE type);
	List::Position find(ElementType e);
	bool deleteNode(ElementType e);
	bool deleteNode(List::Position p);
	void clear();
	void show();
	~List();
private:
	List::Position head;
	List::Position last;
};
#endif