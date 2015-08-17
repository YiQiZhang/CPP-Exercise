// server.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include "eventQueue.h"
#include "errorHandler.h"
#include "util.h"

using namespace std;

void init_queue(EventQueue &q, int count)
{
	time_t timer;
	srand(time(NULL));

	for(int i = 0; i < count; i++) {
		task t1;
		time(&timer);

		t1.push_datetime = timer + i;
		t1.start_datetime = timer + (rand() % 100) * i;
		t1.task_type = 1;
		t1.task_info = string("i am task ") + to_string(i + 1);

		int position = q.push(t1);
		cout << "Insert in " << position << endl;
	}
}

EventQueue queue; // 定义任务队列

int main(int argc, char ** argv)
{
	init_queue(queue, 10);
	queue.show();

	time_t timer;


	while(1){
		if(!queue.isEmpty()) {
			const task t = queue.first();
			time(&timer);
			if(timer >= t.start_datetime) {
				cout << put_time(localtime(&(timer)), "%Y-%m-%d %H:%M:%S") << " gt than "<< put_time(localtime(&(t.start_datetime)), "%Y-%m-%d %H:%M:%S") << ". Do it!!" <<endl;
				task pop_t = queue.popFirst();
				cout << "Task: " << t.task_info << " finished!"<< endl;
			}
		}
	}

	return 0;
}