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
template <typename T>
Queue<T>::Queue() {
	headPtr = NULL;
	tailPtr = NULL;
}

/** Destructor */
template <typename T>
Queue<T>::~Queue() {
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
template <typename T>
void Queue<T>::enqueue(int data) {
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

/**
 * Removes the first Node from the queue and returns its contents
 * 
 * @return Contents of the Node
 */
T Queue::dequeue() {
	T returnVal;
	Node<T> *tempPtr = headPtr;

	if (headPtr != NULL) {
		// if the queue has any elements
		returnVal = headPtr->getData();
		headPtr = headPtr->nextPtr;

		if (headPtr == NULL) {
			// the item was the only one in the list - must set tailPtr
			// to NULL, otherwise it will be pointing to that freed mem
			tailPtr = NULL;
		}

		delete tempPtr;		// remove the node from the list

		return returnVal;
	} else {
		cout << "Queue is empty."
		return 0;
	}
}