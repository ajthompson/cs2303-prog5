/**
 * Node.h
 *
 * Nodes are used as a container class for anything stored in a queue or event
 * list.  This could be anywhere from integers to events.
 */
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
private:
	T data;
	Node<T> *nextPtr;
public:
	Node(T);			// constructor
	void setData(T);	// set the data in the Node
	T getData();		// get the data from the Node
	void setNext(T&);	// set the next pointer
	T* getNext();		// gets the next pointer
	void printNode();	// prints the node
}