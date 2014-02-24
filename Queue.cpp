/**
 * Queue.cpp
 *
 * Source code for queues
 */
#include <iostream>
#include "Queue.h"
#include "QueueNode.h"
 using cout;
 using endl;
 using namespace std;

/** Constructor */
Queue::Queue() {
	headPtr = NULL;
	tailPtr = NULL;
}

/** Destructor */
Queue::~Queue() {
	QueueNode *a, *b;

	a = headPtr;
	// iterate through the list deleting nodes
	while (a != NULL) {
		b = a->nextPtr;
		delete a;
		a = b;
	}

	// once the list is deleted, delete this instance of the class
	delete this;
}

/**
 * Enqueue a new piece of data at the end of the queue
 * 
 * @param data Router ID that the packet must track through.
 */
void Queue::enqueue(int data) {
	if (headPtr == NULL) {
		// there is nothing in the queue
		headPtr = new QueueNode(data);	// add the node to the empty list
		tailPtr = headPtr;				// point the tail at the node
	} else {
		// there is something in the queue
		tailPtr->nextPtr = new QueueNode(data);	// add the node to the end of the list
		tailPtr = tailPtr->nextPtr;				// point at the new tail.
	}
}

int Queue::dequeue() {

}