#ifndef _LIST_H_
#define _LIST_H_

#define ElementType int

struct Node;
typedef struct Node* Position;
struct Node
{
	ElementType data;
	Position next;
	Position before;
};

class List
{
private:
	Position head;
	Position last;
public:
	enum INSERT_TYPE {
		AFTER, 
		BEFORE
	};
	List(ElementType e);
	Position init(ElementType e);
	bool isEmpty();
	Position getHead();
	Position getLast();
	Position getNext(Position p);
	Position getBefore(Position p);
	Position insert(ElementType e, Position p, List::INSERT_TYPE type);
	Position find(ElementType e);
	bool deleteNode(ElementType e);
	bool deleteNode(Position p);
	void clear();
	void show();
	~List();
};
#endif