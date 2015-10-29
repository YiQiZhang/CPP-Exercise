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
using std::cout;
using std::endl;
using std::ostream;
using std::endl;
using std::string;

template <typename T>
class PriorityQueue
{
private:
	typedef size_t position;
	size_t nodeCount;
	vector<T> binaryHeap;

	inline position max(position p1, position p2)
	{
		return p1 > p2 ? p1 : p2;
	}

	void swap(position p1, position p2)
	{
		T tmp = binaryHeap[p1];
		binaryHeap[p1] = binaryHeap[p2];
		binaryHeap[p2] = tmp;
	}

	void swim(position p)
	{
		position t = max(p/2, 1);
		while(binaryHeap[t] < binaryHeap[p] && p > 1) {
			swap(p, t);
			p = t;
			t = max(p/2, 1);
		}
	}

	void sink(position p)
	{
		position t = p * 2;
		while(t <= nodeCount) {
			if (t < nodeCount && binaryHeap[t] < binaryHeap[t + 1]) ++t;
			if (binaryHeap[p] < binaryHeap[t]) break;
			swap(p, t);
			p = t;
			t = t * 2;
		}
	}
public:
	PriorityQueue()
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
		--nodeCount;
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
				os << binaryHeap[p] << separator;
				++p;
			}
			os << endl;
		}
	}
};


#endif