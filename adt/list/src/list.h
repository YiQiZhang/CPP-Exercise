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

public:
	List(ElementType e);
	bool isEmpty();
	Position getHead();
	Position insert(ElementType e, Position p);
	Position find(ElementType e);
	void show();
	~List();
};
#endif