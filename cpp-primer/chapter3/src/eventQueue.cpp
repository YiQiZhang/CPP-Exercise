// eventQueue.cpp
#include <string>
#include <iostream>
#include "eventQueue.h"
#include "util.h"

using namespace std;

EventQueue::EventQueue()
{

}

bool EventQueue::isEmpty()
{
	return task_list.cbegin() == task_list.cend();
}

int EventQueue::push(task t)
{
	bool is_inserted = false;
	int position = 0;
	auto p_now = task_list.cbegin();

	if (p_now == task_list.cend()) {
		task_list.push_back(t);
	} else {
		while(p_now != task_list.cend() && !is_inserted) {
			position++;
			if (p_now->start_datetime >= t.start_datetime) {
				task_list.insert(p_now, t);
				is_inserted = true;
			}
			p_now++;
		}
		if (!is_inserted) {
			task_list.push_back(t);
		}
	}

	return position;
}

const task& EventQueue::first()
{
	auto beg = task_list.cbegin();

	return (*beg);
}

task& EventQueue::popFirst()
{
	auto beg = task_list.begin();
	task_list.pop_front();

	return *beg;
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