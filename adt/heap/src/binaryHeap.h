//
//  binaryHeap.h
//
//  Created by Jerry on 10/23/15.
//  Copyright (c) 2015 Jerry. All rights reserved.
//

#ifndef _BINARY_HEAP_H
#define _BINARY_HEAP_H

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::ostream;
using std::endl;
using std::string;

template <typename T>
class PriorrityQueue
{
private:
	typedef size_t position;
	size_t nodeCount;
	vector<T> binaryHeap;

	void swap(position p1, position p2)
	{
		T tmp = binaryHeap[p1];
		binaryHeap[p1] = binaryHeap[p2];
		binaryHeap[p2] = tmp;
	}

	void swim(position p)
	{

	}

	void sink(position p)
	{

	}
public:
	PriorrityQueue()
	{
		T tmp;
		binaryHeap.push_back(tmp);
		nodeCount = 0;
	}

	void enqueue(const T &ele)
	{
		binaryHeap.push_back(ele);
		++nodeCount;
		swim(nodeCount);
	}

	void dequeue()
	{
		swap(1, nodeCount);
		binaryHeap.pop_back();
		sink(1);
	}

	T top() const
	{
		return binaryHeap[1];
	}

	size_t count() const
	{
		return nodeCount;
	}

	bool isEmpty() const
	{
		return nodeCount <= 0;
	}

	void show(ostream &os, const string &separator = " ") const
	{
		if (isEmpty()) {
			os << "queue is empty" << endl;
		} else {
			position p = 1;
			while(p <= nodeCount) {
				os << p << separator;
				++p;
			}
			os << endl;
		}
	}
};


#endif