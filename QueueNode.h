/**
 * QueueNode.h
 *
 * Header file for nodes within a queue.
 * Each node contains an integer representing a router.
 */
#ifndef QUEUENODE_H
#define QUEUENODE_H

class QueueNode {
private:
	int data;
	QueueNode *nextPtr;
public:
	QueueNode(int);		// constructor, stores data in the new node
	~QueueNode();		// destructor
	void setData(int);	// set the data for the node
	int getData();		// returns the data from the node
};

#endif