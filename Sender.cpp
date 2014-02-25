/**
 * Sender.cpp
 *
 * Source file for sender routers.
 */
#include <iostream>
#include "Packet.h"
#include "Sender.h"
 using std::cout;
 using std::endl;
 using namespace std;

/**
 * Constructor for Sender object
 * 
 * @param y     Y position of
 * @param s_id  [description]
 * @param t     [description]
 * @param count [description]
 * @param size  [description]
 */
Sender::Sender(int y, int s_id, int t, int count, int size) {
	xPos = 0;
	yPos = y;
	id = s_id;
	arrival_time = t;
	pkt_count = count;
	pkt_size = size;
	srHeadPtr = NULL;
	srTailPtr = NULL;
	pktHeadPtr = NULL;
}

void Sender::srEnqueue(int) {
	if (srHeadPtr == NULL) {
		// the router list is empty
		srHeadPtr = new Node(sr_id);

		if (srHeadPtr != NULL) {
			// the memory was successfully allocated
			srTailPtr = srHeadPtr;
		} else {
			cout << "Memory Allocatio Failed. Router " << sr_id;
			cout << " Not Added." << endl;
		}
	} else {
		// the router list is not empty
		srTailPtr->nextPtr = new Node(sr_id);

		if (srTailPtr->nextPtr != NULL) {
			// memory successfully allocated
			srTailPtr = srTailPtr->nextPtr;
		} else {
			cout << "Memory Allocatio Failed. Router " << sr_id;
			cout << " Not Added." << endl;
		}
	}
}

/**
 * Dequeues the first value from the queue of routes.
 * 
 * @return the first value in the SR queue.
 */
int Sender::srDequeue() {
	Node *tempPtr;
	int returnVal;

	tempPtr = srHeadPtr;

	if (tempPtr != NULL) {
		// the queue is not empty
		returnVal = tempPtr->data;
		srHeadPtr = tempPtr->nextPtr;

		if (srHeadPtr == NULL) {
			// the list is now empty
			srTailPtr = srHeadPtr;
		}

		// deallocate the memory
		delete tempPtr;
		return returnVal;
	} else {
		cout << "List is empty.  No items dequeued." << endl;
		return 0;
	}
}

/**
 * Enqueues a packet on the sender.  Packets enqueuing will be triggered by
 * the completion of a transmission event, so there will only ever be packets
 * added to the node when 
 * 
 * @param t [description]
 */
void Sender::pktEnqueue(int t) {
	if (pktHeadPtr == NULL) {
		// the packet queue is empty
		pktHeadPtr = new Packet(this->is, t, this->pkt_size, srHeadPtr, srTailPtr);

		if (pktHeadPtr == NULL) {
			// memory allocation failed
			cout << "Memory Allocation Failed. Packet Not Created." << endl;
		}
	} else {
		cout << "Packet already exists here. Wait for transmission to complete." << endl;
	}
}

/**
 * Dequeues a packet and returns a pointer to the packet. This allows easy
 * transfer of the packet to future nodes or events, such as a propagation
 * event. It is more efficient to simply transfer the packet as opposed to
 * deleting and rebuilding it when transferring it to a node.
 * 
 * @return A pointer to the dequeued packet
 */
Packet *Sender::pktDequeue() {
	Packet *returnPktPtr;

	if (pktHeadPtr != NULL) {
		// the queue contains a packet
		returnPktPtr = pktHeadPtr;
		pktHeadPtr = pktHeadPtr->nextPtr;

		return returnPktPtr;
	} else {
		// the queue is empty.
		cout << "The packet queue is empty. Returning NULL." << endl;
		return NULL;
	}
}