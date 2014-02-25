/**
 * Node.cpp
 */
#include <iostream>
#include "Node.h"
 using std::cout;
 using std::endl;
 using namespace std;

/** Constructor */
Node::Node(int data) {
	this->data = data;
	this->nextPtr = NULL;
}

/**
 * Stores an int in the node.
 *
 * @param data Object that is stored in the node.
 */
void Node::setData(int data) {
	this->data = data;
}

/**
 * Returns the data of type int from the node.
 *
 * @return data of type int
 */
int Node::getData() {
	return this->data;
}

/**
 * Prints out the node.
 */
void Node::printNode() {
	cout << data << endl;
}