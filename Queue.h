/**
 * Queue.h
 *
 * Header file for a queue of integers
 */
#ifndef QUEUE_H
#define QUEUE_H

class Node;

class Queue {
	friend class Node;

private:
	Node *headPtr;	// pointer to the head of the Queue
	Node *tailPtr;	// pointer to the tail of the queue
public:
	Queue<T>();				// constructor
	~Queue<T>();			// destructor
	void enqueue(int);		// add a node to end of the queue
	int dequeue();			// deque the node
	void printQueue();		// print the queue
};

#endif