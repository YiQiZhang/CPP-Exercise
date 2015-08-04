// server.cpp
#include <iostream>
#include <string>
#include "eventQueue.h"
#include "errorHandler.h"
#include <cctype>

using std::string;

int main(int argc, char ** argv)
{
	EventQueue queue;

	for(int i = 0; i < 100; i++) {
		task t1;
		t1.push_datetime = 1;
		t1.start_datetime = 2;
		t1.task_type = 1;
		t1.task_info = "i am task ";
		t1.task_info = t1.task_info + string(i);

		queue.push(t1);
	}

	queue.show();

	return 0;
}