#pragma once
#include<iostream>
using namespace std;
template <class T>
class Queue;

template<class T>
Queue<T> unionQueues(const Queue<T>&first, const Queue<T>&second);

template<class T>
class Queue
{
private:
	int maxSize;
	T *queue;
	int start, end;
	int count;
public:
	Queue(int);
	Queue(const Queue&);
	~Queue() { delete[] queue; }
	void push(T);
	T pop();
	bool isEmpty();
	bool isFull();
	int size();
	//void print();
	friend Queue unionQueues<T>(const Queue<T>&first, const Queue<T>&second);
};

template<class T>
Queue<T>::Queue(int maxSize)
{
	this->maxSize = maxSize;
	this->queue = new T[maxSize];
	this->count = 0;
	this->start = 0;
	this->end = -1;
}

template<class T>
Queue<T>::Queue(const Queue& other)
{
	this->maxSize = other.maxSize;
	this->queue = new T[maxSize];
	copy(other.queue, other.queue + other.maxSize, this->queue);
	this->count = other.count;
	this->start = other.start;
	this->end= other.end;
}
//template<class T>
//void Queue<T>::print()
//{
//	for (int i = start; i <= end; i++) {
//		cout << queue[i] << "  ";
//	}
//}
template<class T>
int Queue<T>::size()
{
	return count;
}

template<class T>
bool Queue<T>::isEmpty()
{
	return (count == 0) ? true : false;
}

template<class T>
bool Queue<T>::isFull()
{
	return (count == maxSize) ? true : false;
}
template<class T>
void Queue<T>::push(T value)
{
	if (isFull()) throw "Queue is full!";
	else
	{
		end = (end + 1) % maxSize;
		queue[end] = value;
		++count;
	}
}

template<class T>
T Queue<T>::pop()
{
	if (isEmpty())
	{
		throw "Queue is empty!";
	}
	else
	{
		T temp = queue[start];
		--count;
		start = (start + 1) % maxSize;
		return temp;
	}
}

template<class T>
Queue<T> unionQueues(const Queue<T>& first, const Queue<T>& second)
{
	Queue<T> result(first.maxSize + second.maxSize);
	int resultCount = 0;
	int index = first.start;
	while (resultCount < first.count) 
	{
		result.push(first.queue[index]);
		++resultCount;
		index = (index + 1) % first.maxSize;
	}
	index = second.start;
	resultCount = 0;
	while (resultCount < second.count)
	{
		result.push(second.queue[index]);
		++resultCount;
		index = (index + 1) % second.maxSize;
	}
	return result;
}