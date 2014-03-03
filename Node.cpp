/**
 * Node.cpp
 */
#include <iostream>
#include "Node.h"
 using std::cout;
 using std::endl;
 using namespace std;

/** Constructors */
Node::Node() {
	data = 0;
	nextPtr = NULL;
}
Node::Node(int nData) {
	data = nData;
	nextPtr = NULL;
}
Node::Node(int nData, Node **toPtr) {
	this->setData(nData);
	nextPtr = *toPtr;
}	

/**
 * Stores an int in the node.
 *
 * @param data Object that is stored in the node.
 */
void Node::setData(int nData) {
	data = nData;
}

/**
 * Returns the data of type int from the node.
 *
 * @return data of type int
 */
int Node::getData() {
	return data;
}

Node *Node::getNext() {
	return nextPtr;
}

/**
 * Prints out the node.
 */
void Node::printNode() {
	cout << "Data: " << data << endl;
	cout << "Next Node: " << nextPtr << endl;
}