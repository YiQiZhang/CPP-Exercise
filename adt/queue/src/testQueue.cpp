// testQueue.cpp
#include <iostream>
#include <string>
#include "queue.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

struct task{
	string name;
	task() : name("undefine") {}
	task(const string &n) : name(n) {}
};

ostream &operator<<(ostream &os, const task &t) {
	os << "do task: " << t.name;

	return os;
}

void testQueue()
{
	queue<task> q(500);
	task t1("do 1");
	task t2("do 2");

	q.enqueue(t1);
	cout << q.dequeue() << endl;
	q.enqueue(t2);
	q.enqueue(t1);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
}

int main(int argc, char **argv)
{
	testQueue();

	return 0;
}