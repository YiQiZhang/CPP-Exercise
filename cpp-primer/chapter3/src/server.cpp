// server.cpp
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "eventQueue.h"
#include "errorHandler.h"

using namespace std;

int main(int argc, char ** argv)
{
	EventQueue queue;
	time_t timer;

	for(int i = 0; i < 10; i++) {
		task t1;
		time(&timer);

		t1.push_datetime = timer + i;
		t1.start_datetime = timer + i * i;
		t1.task_type = 1;
		t1.task_info = string("i am task ") + to_string(i + 1);

		queue.push(t1);
	}

	queue.show();

	return 0;
}