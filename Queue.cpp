/**
 * Queue.cpp
 *
 * Source code for queues
 */
#include "Queue.h"
#include "QueueNode.h"

/** Constructor */
Queue::Queue() {
	headPtr = NULL;
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

