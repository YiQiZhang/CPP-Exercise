#include <iostream>
#include <vector>
#include "binaryHeap.h"

using std::vector;
using std::cout;
using std::endl;

void testBinaryHeap()
{
	PriorityQueue<int> queue;
	vector<int> inputs = {1,2,3,1,85,92,47,15};
	for(auto ele : inputs) {
		queue.enqueue(ele);
	}
	queue.show(cout);
	for(auto ele : inputs) {
		cout << queue.top() << endl;
		queue.dequeue();
	}
	cout << endl;
	queue.show(cout);
}

int main(int argc, char **argv)
{
	testBinaryHeap();
	return 0;
}