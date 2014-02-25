/**
 * Node.h
 *
 * Nodes are used as a container class for anything stored in a queue or event
 * list.  This could be anywhere from integers to events.
 */
#ifndef NODE_H_
#define NODE_H_

class Node {
	friend class Packet;
	friend class Sender;
private:
	int data;
	Node *nextPtr;
public:
	Node();				// constructor
	Node(int);			// constructor
	Node(int, Node **);	// constructor
	void setData(int);	// set the data in the Node
	int getData();		// get the data from the Node
	void printNode();	// prints the node
};

#endif