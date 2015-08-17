// eventQueue.h
#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include <string>
#include <list>
#include <ctime>

using std::string;
using std::list;

struct task
{
	time_t push_datetime;
	time_t start_datetime;
	int task_type;
	string task_info;
};

typedef struct task task;

class EventQueue
{
public:
	EventQueue();
	bool isEmpty();
	int push(task t);
	const task& first();
	task& popFirst();
	void show();
private:
	list<task> task_list;
};
#endif