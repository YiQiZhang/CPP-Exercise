// eventQueue.h
#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include <string>
#include <vector>
#include <ctime>

using std::string;
using std::vector;

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
	int push(task t);
	void show();
private:
	vector<task> task_list;
};
#endif