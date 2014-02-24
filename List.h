/**
 * List.h
 *
 * Header file for a linked list
 */
#ifndef LIST_H
#define LIST_H

class ListNode;

class List {
	friend class ListNode;

private:
	ListNode *headPtr;	// pointer to the head of the list
public:
	List();				// constructor
	~List();			// destructor
	void enqueue(int);	// add a node to the queue
}