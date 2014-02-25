/**
 * Queue.h
 *
 * Header file for a queue of integers
 */
#ifndef QUEUE_H
#define QUEUE_H


template<typename T> class Node;

template <typename T>
class Queue {
	friend class Node<T>;

private:
	Node<T> *headPtr;	// pointer to the head of the Queue
	Node<T> *tailPtr;	// pointer to the tail of the queue
public:
	Queue<T>();				// constructor
	~Queue<T>();			// destructor
	void enqueue(T);		// add a node to end of the queue
	T dequeue();			// deque the node
	void printQueue();		// print the queue
};

// prevents compiler errors from function templates
#include "Queue.cpp"

#endif