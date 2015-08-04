// eventQueue.cpp
#include <string>
#include <iostream>
#include "eventQueue.h"

using namespace std;

EventQueue::EventQueue()
{

}

int EventQueue::push(task t)
{
	task_list.push_back(t);
	return 1;
}

void EventQueue::show()
{
	for(auto task : task_list) {
		cout << "task: " << task.task_info << endl;
	}
}