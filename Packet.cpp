/** 
 * @Author: Alec Thompson
 *
 * Packet.cpp
 *
 * Source file for packets
 */
#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "Packet.h"
#include "Sender.h"
using std::cout;
using std::endl;
using std::exit;
using namespace std;

/**
 * @Author: Alec Thompson
 *
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
Packet::Packet(Sender *original, int t) {
	#if DEBUG
		cout << "Creating new packet based off of Sender " << original << endl;
		original->printSender();
	#endif
	source_id = original->getID();
	timestamp = t;
	pkt_size = original->getPktSize();
	headPtr = NULL;
	tailPtr = NULL;
	nextPtr = NULL;
	#if DEBUG
		cout << "Packet without SR queue" << endl;
		printPacket();
		cout << "Copying queue now" << endl;
	#endif
	// copy the Sender's SR queue to the packet
	this->copyQueue(original);
	#if DEBUG
		cout << "Packet with SR queue" << endl;
		printPacket();
	#endif
}

/**
 * @Author: Alec Thompson
 * 
 * Destructor
 */
Packet::~Packet() {
	Node *a, *b;

	// destruct the list of nodes
	a = headPtr;
	while (a != NULL) {
		b = a->nextPtr;
		delete a;
		a = b;
	}
}

/**
 * @Author: Alec Thompson
 * 
 * Sets the packets ID
 */
void Packet::setID(int nID) {
	source_id = nID;
}

/** 
 * @Author: Alec Thompson
 *
 * Gets the packets ID
 */
int Packet::getID() {
	return source_id;
}

/** @Author: Alec Thompson */
/** Sets the packets timestamp */
void Packet::setTimestamp(int t) {
	timestamp = t;
}

/** @Author: Alec Thompson */
/** Gets the packets timestamp */
int Packet::getTimestamp() {
	return timestamp;
}

/** @Author: Alec Thompson */
/** Sets the packets size */
void Packet::setSize(int s) {
	pkt_size = s;
}

/** @Author: Alec Thompson */
/** Gets the packets size */
int Packet::getSize() {
	return pkt_size;
}

/** @Author: Alec Thompson */
/** Sets the packets propagation time (calculated in EventList) */
void Packet::setProp(int pTime) {
	delay = pTime;
}

/**
 * @Author: Alec Thompson
 *
 * Sets the delay (time of arrival at receiver - timestamp)
 * 
 * @param t time of arrival at receiver
 */
void Packet::setDelay(int t) {
	delay = t - timestamp;
}

/** @Author: Alec Thompson */
/** Gets the delay */
int Packet::getDelay() {
	return delay;
}

/** @Author: Alec Thompson */
/** Gets the pointer to the head of the SR queue */
Node *Packet::getHead() {
	return headPtr;
}

/** @Author: Alec Thompson */
/** Gets the pointer to the tail of the SR queue */
Node *Packet::getTail() {
    return tailPtr;
}

/** @Author: Alec Thompson */
/** Gets the pointer to the next  */
Packet *Packet::getNext() {
	return this->nextPtr;
}

/** @Author: Alec Thompson */
/** Copies the node queue from a template packet */
void Packet::copyQueue(Packet original) {
	Node *currentPtr = original.getHead();

	while (currentPtr != NULL) {
		this->enqueue(currentPtr->getData());
		currentPtr = currentPtr->getNext();
	}
}

/** @Author: Alec Thompson */
/** Copies the node queue from a template sender */
void Packet::copyQueue(Sender *original) {
	Node *currentPtr = original->getSRHead();

	while (currentPtr != NULL) {
		
		#if DEBUG
			cout << "---------------------------------------------" << endl;
			original->printNodes();
			cout << "---------------------------------------------" << endl;
			cout << "Enqueuing " << currentPtr->getData() << endl;
			currentPtr->printNode();
		#endif
		
		this->enqueue(currentPtr->getData());
		
		#if DEBUG
			cout << currentPtr->getData() << " enqueued" << endl;
			currentPtr->printNode();
		#endif
		
		currentPtr = currentPtr->getNext();
		
		#if DEBUG
			cout << "---------------------------------------------" << endl;
			original->printNodes();
			cout << "---------------------------------------------" << endl;
		#endif
	}
}

/**
 * @Author: Alec Thompson
 *
 * Enqueues the integer in the SR queue
 * 
 * @param sr_id ID of the router to be enqueued
 */
void Packet::enqueue(int sr_id) {
	
	#if DEBUG
		cout << "Enquing SR ID " << sr_id << endl;
		cout << "HeadPtr: " << headPtr << endl;
		cout << "TailPtr: " << tailPtr << endl;
	#endif
	
	if (headPtr == NULL) {
		
		#if DEBUG
			cout << "SR List is empty" << endl;
		#endif
		
		// the router list is empty
		headPtr = new Node(sr_id);
		
		#if DEBUG
			cout << "New HeadPtr: " << headPtr << endl;
		#endif
		
		// the memory was successfully allocated
		
		#if DEBUG
			cout << "New TailPtr: " << tailPtr << endl;
		#endif

	} else if (tailPtr == NULL) {
		headPtr->nextPtr = new Node(sr_id);
		tailPtr = headPtr->nextPtr;
		
		#if DEBUG
			cout << "New TailPtr: " << tailPtr << endl;
		#endif

	} else {
		
		#if DEBUG
			cout << "SR List is not empty" << endl;
		#endif

		// the router list is not empty
		tailPtr->nextPtr = new Node(sr_id);
		
		#if DEBUG
			cout << "New TailPtr: " << tailPtr << endl;
		#endif

		if (tailPtr->nextPtr != NULL) {
			// memory successfully allocated
			tailPtr = tailPtr->nextPtr;
		} else {
			cout << "Memory Allocation Failed. Router " << sr_id;
			cout << " Not Added." << endl;
		}
	}
}

/**
 * @Author: Alec Thompson
 *
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

/**
 * @Author: Alec Thompson
 *
 * Dequeues the first node in the queue and returns a pointer  to it
 * 
 * @return Pointer to the just dequeued node
 */
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

/** @Author: Alec Thompson */
/** Finds the length of the node queue */
int Packet::nLength() {
	Node *currentPtr = headPtr;
	int length = 0;
	while (currentPtr != NULL) {
		++length;
		currentPtr = currentPtr->nextPtr;
	}

	return length;
}

/** @Author: Alec Thompson */
/** Prints the packet queue */
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
