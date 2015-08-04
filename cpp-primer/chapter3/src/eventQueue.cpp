// eventQueue.cpp
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
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
		cout << "Task info: " << task.task_info << endl;
		cout << "Push_datetime: " << put_time(localtime(&(task.push_datetime)), "%Y-%m-%d %H:%M:%S") << endl;
		cout << "Start_datetime: " << put_time(localtime(&(task.start_datetime)), "%Y-%m-%d %H:%M:%S") << endl;
		cout << "-----------------------------" << endl;
	}
}