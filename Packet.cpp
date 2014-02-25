/** 
 * Packet.cpp
 *
 * Source file for packets
 */
#include <iostream>
#include "Node.h"
#include "Packet.h"
 using std::cout;
 using std::endl;
 using namespace std;

/**
 * Packet Constructor
 * 
 * @param id     ID of the source router
 * @param s_time packet timestamp
 * @param size   packet size
 * @param head   pointer to the head of the SR list
 * @param tail   pointer to the tail of the SR list
 */
Packet::Packet(int id, int s_time, int size, Node *head, Node *tail) {
	source_id = id;
	timestamp = s_time;
	pkt_size = size;
	headPtr = head;
	tailPtr = tail;
	nextPtr = NULL;
}

/**
 * Sets the delay (time of arrival at receiver - timestamp)
 * 
 * @param t time of arrival at receiver
 */
void Packet::setDelay(int t) {
	delay = t - this->timestamp;
}

/**
 * Enqueues the integer in the SR queue
 * 
 * @param sr_id ID of the router to be enqueued
 */
void enqueue(int sr_id) {
	if (headPtr == NULL) {
		// the router list is empty
		headPtr = new Node(sr_id);

		if (headPtr != NULL) {
			// the memory was successfully allocated
			tailPtr = headPtr;
		} else {
			cout << "Memory Allocatio Failed. Router " << sr_id;
			cout << " Not Added." << endl;
		}
	} else {
		// the router list is not empty
		tailPtr->nextPtr = new Node(sr_id);

		if (tailPtr->nextPtr != NULL) {
			// memory successfully allocated
			tailPtr = tailPtr->nextPtr;
		} else {
			cout << "Memory Allocatio Failed. Router " << sr_id;
			cout << " Not Added." << endl;
		}
	}
}

/**
 * Dequeues the first router ID in the queue and returns it.
 * 
 * @return Router ID
 */
int Packet::dequeue() {
	Node *tempPtr;
	int returnVal;

	tempPtr = headPtr;

	if (tempPtr != NULL) {
		// the queue is not empty
		returnVal = tempPtr->data;
		headPtr = tempPtr->nextPtr;

		if (headPtr == NULL) {
			// the list is now empty
			tailPtr = headPtr;
		}

		// deallocate the memory
		delete tempPtr;
		return returnVal;
	} else {
		cout << "List is empty.  No items dequeued." << endl;
		return 0;
	}
}