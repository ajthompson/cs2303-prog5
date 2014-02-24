/**
 * ListNode.h
 *
 * Header file for nodes within a linked list.
 * Each node contains date of some type NODETYPE.
 */
#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode {
private:
	int data;
	ListNode *nextPtr;
public:
	ListNode(int);		// constructor, stores data in the new node
	~ListNode();			// destructor
	void setData(int);	// set the data for the node
	int getData();		// returns the data from the node
};

#endif