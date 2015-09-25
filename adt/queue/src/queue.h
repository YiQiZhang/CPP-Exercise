#include <memory>
#include "error.h"

using std::unique_ptr;

#define MIN_QUEUE_SIZE (5)

template <typename T>
class queue{
private:
	size_t maxSize;
	size_t size;
	size_t front;
	size_t rear;
	unique_ptr<T[]> datas;
	// 下标回环
	size_t circle(size_t index)
	{
		if (++index > maxSize) {
			index = 0;
		}

		return index;
	}
public:
	queue(size_t s = MIN_QUEUE_SIZE) : 
		maxSize(s),
		size(0),
		front(1),
		rear(0) 
	{
		if(maxSize < MIN_QUEUE_SIZE) {
			error("queue too small");
		}
		datas.reset(new T[maxSize]);
	}
	void enqueue(const T &ele)
	{
		if (isFull()) {
			error("queue is full, fail to enqueue");
		}
		rear = circle(rear);
		++size;
		datas[rear] = ele;
	}
	T dequeue()
	{
		if (isEmpty())
			error("queue is empty, fail to dequeue");
		T res = datas[front];
		--size;
		front = circle(front);

		return res;
	}
	bool isEmpty() const
	{
		return size <= 0 ? true : false;
	}
	bool isFull() const
	{
		return size >= maxSize ? true : false;
	}
	~queue() {
		datas.release();
	}
};