// eventQueue.h
#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include <string>
#include <vector>

using std::string;
using std::vector;

struct task
{
	int push_datetime;
	int start_datetime;
	int task_type;
	string task_info;
};

typedef struct task task;

class EventQueue
{
public:
	EventQueue();
	int push(task t);
	void show();
private:
	vector<task> task_list;
};
#endif