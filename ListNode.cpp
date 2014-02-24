/**
 * ListNode.cpp
 *
 * Source file for linked list nodes
 */
#include "ListNode.h"

/**
 * Constructor
 */
ListNode::ListNode(int newdata) {
	data = newData;
	nextPtr = NULL;
}

/**
 * Destructor
 */
ListNode::~ListNode() {

}

/**
 * Sets the data to a new value
 * 
 * @param newData New data value
 */
void ListNode::setData(int newData) {
	data = newData;
}

/**
 * Returns the node's stored data
 * 
 * @return stored data
 */
int ListNode::getData() {
	return data;
}