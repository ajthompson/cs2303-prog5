/** 
 * Packet.cpp
 *
 * Source file for packets
 */
#include <iostream>
#include "Packet.h"
 using std::cout;
 using std::endl;
 using namespace std;

Packet::Packet(int id, int s_time, int size, Node *head, Node *tail) {
	source_id = id;
	timestamp = s_time;
	pkt_size = size;
	headPtr = head;
	tailPtr = tail;
	nextPtr = NULL;
}

void Packet::setDelay(int t) {
	delay = t;
}

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