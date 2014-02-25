/** 
 * Packet.cpp
 *
 * Source file for packets
 */
#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "Packet.h"
// #include "Sender.h"
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
 */
Packet::Packet() {
	source_id = 0;
	timestamp = 0;
	pkt_size = 0;
	headPtr = NULL;
	tailPtr = NULL;
	nextPtr = NULL;
}
Packet::Packet(int id, int s_time, int size) {
	source_id = id;
	timestamp = s_time;
	pkt_size = size;
	headPtr = NULL;
	tailPtr = NULL;
	nextPtr = NULL;
}
// Packet::Packet(Sender original) {

// }

void Packet::setID(int nID) {
	source_id = nID;
}

int Packet::getID() {
	return source_id;
}

void Packet::setTimestamp(int t) {
	timestamp = t;
}

int Packet::getTimestamp() {
	return timestamp;
}

void Packet::setSize(int s) {
	pkt_size = s;
}

int Packet::getSize() {
	return pkt_size;
}

/**
 * Sets the delay (time of arrival at receiver - timestamp)
 * 
 * @param t time of arrival at receiver
 */
void Packet::setDelay(int t) {
	delay = t - timestamp;
}

int Packet::getDelay() {
	return delay;
}

Node *Packet::getHead() {
	return headPtr;
}

Node *Packet::getTail() {
    return tailPtr;
}

Packet *Packet::getNext() {
	return this->nextPtr;
}

void Packet::copyQueue(Packet original) {
	Node *currentPtr = original.getHead();

	while (currentPtr != NULL) {
		this->enqueue(currentPtr->getData());
		currentPtr = currentPtr->getNext();
	}
}

// void Packet::copyQueue(Sender original) {
// 	Node *currentPtr = original.getSRHead();

// 	while (currentPtr != NULL) {
// 		this->enqueue(currentPtr->getData());
// 		currentPtr = currentPtr->getNext();
// 	}
// }

/**
 * Enqueues the integer in the SR queue
 * 
 * @param sr_id ID of the router to be enqueued
 */
void Packet::enqueue(int sr_id) {
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
		cout << "Quitting the program." << endl;
		exit(1);
	}
}

Node *Packet::dequeueNode() {
	Node *tempPtr;

	tempPtr = headPtr;

	if (tempPtr != NULL) {
		// the queue is not empty
		headPtr = tempPtr->nextPtr;

		if (headPtr == NULL) {
			// the list is now empty
			tailPtr = headPtr;
		}
		return tempPtr;
	} else {
		cout << "List is empty.  No items dequeued." << endl;
		cout << "Quitting the program." << endl;
		exit(1);
	}
}

int Packet::nLength() {
	Node *currentPtr = headPtr;
	int length = 0;
	while (currentPtr != NULL) {
		++length;
		currentPtr = currentPtr->nextPtr;
	}

	return length;
}

void Packet::printPacket() {
	Node *currentPtr = headPtr;

	// print out the contents of the packet
	cout << "Source ID: " << source_id << endl;
	cout << "Timestamp: " << timestamp << endl;
	cout << "Packet Size: " << pkt_size << endl;
	cout << "Delay: " << delay << endl;
	cout << "Nodes: " << endl;
	while (currentPtr != NULL) {
		currentPtr->printNode();
		currentPtr = currentPtr->nextPtr;
	}
}