/**
 * Queue.h
 *
 * Header file for a queue of integers
 */
#ifndef QUEUE_H
#define QUEUE_H

class QueueNode;

class Queue {
	friend class QueueNode;

private:
	QueueNode *headPtr;	// pointer to the head of the Queue
	QueueNode *tailPtr;	// pointer to the tail of the queue
public:
	Queue();				// constructor
	~Queue();			// destructor
	void enqueue(int);	// add a node to end of the queue
	int dequeue();		// deque the node
};

#endif