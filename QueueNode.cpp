/**
 * QueueNode.cpp
 *
 * Source file for linked list nodes
 */
#include "QueueNode.h"

/** Constructor */
QueueNode::QueueNode(int newdata) {
	data = newData;
	nextPtr = NULL;
}

/** Destructor */
QueueNode::~QueueNode() {
	delete this;
}

/**
 * Sets the data to a new value
 * 
 * @param newData New data value
 */
void QueueNode::setData(int newData) {
	data = newData;
}

/**
 * Returns the node's stored data
 * 
 * @return stored data
 */
int QueueNode::getData() {
	return data;
}