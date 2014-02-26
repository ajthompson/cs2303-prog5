/* 
* @Author: ajthompson
* @Date:   2014-02-25 10:16:11
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-25 21:31:25
*/

#include <iostream>
#include <cstdlib>
#include "Sender.h"
#include "Packet.h"
#include "Node.h"
using namespace std;

/**
 * Constructs an empty sender
 */
Sender::Sender() {
	setX();
	setY(0);
	setID(0);
	setArrivalTime(0);
	setPktCount(0);
	setPktSize(1);
	srHeadPtr = NULL;
	srTailPtr = NULL;
	pktHeadPtr = NULL;
	pktTailPtr = NULL;
}

/**
 * Constructs a sender with no SR and no packets enqueued and the given data fields
 * 
 * @param y     Y position sender
 * @param s_id  ID of sender
 * @param t     Time the sender begins transmitting
 * @param count Packets remaining to be transmitted
 * @param size  Size of the packets to be sent
 */
Sender::Sender(int y, int s_id, int t, int count, int size) {
	setX();
	setY(y);
	setID(s_id);
	setArrivalTime(t);
	setPktCount(count);
	setPktSize(size);
	srHeadPtr = NULL;
	srTailPtr = NULL;
	pktHeadPtr = NULL;
	pktTailPtr = NULL;
}

////////////////////////
/// SETTER FUNCTIONS ///
////////////////////////

/**
 * Sets the x position to 0, because senders can only exist on the left side of the field
 */
void setX() {
	xPos = 0;
}

/**
 * Sets the y position to the input value.
 * 
 * @param y New y position
 */
void setY(int y) {
	yPos = y;
}

/**
 * Sets the node ID to the new ID value.
 * 
 * @param nID New ID
 */
void setID(int nID) {
	id = nID;
}

/**
 * Sets the arrival time to the input value.
 * 
 * @param t 
 */
void setArrivalTime(int t) {
	arrival_time = t;
}

/**
 * Sets the amount of packets to be sent by the Sender
 * 
 * @param c The number of packets to be sent by the node
 */
void setPktCount(int c) {
	pkt_count = c;
}

/**
 * Sets the packet size to be sent by the router.  This is a value from
 * 1 to 3 inclusive.  If the input value is outside of this range, it defaults
 * to 1.
 * 
 * @param s The new value for packet size
 */
void setPktSize(int s) {
	if (s > 0 && s <= 3) {
		pkt_size = s;
	} else {
		pkt_size = 1;
	}
}

////////////////////////
/// GETTER FUNCTIONS ///
////////////////////////

/** Gets the x position */
int getX() {
	return xPos;
}

/** Gets the Y position */
int getY() {
	return yPos;
}

/** Gets the ID of the sender */
int getID() {
	return id;
}

/** Gets the time of beginning transmission */
int getArrivalTime() {
	return arrival_time;
}

/** Gets the amount of packets that are remaining to be sent */
int getPktCount() {
	return pkt_count;
}

/** Gets the size of the packets being sent by the node */
int getPktSize() {
	return pkt_size;
}

/** Gets the head of the SR queue */
Node *getSRHead() {
	return srHeadPtr;
}

/** Gets the tail of the SR queue */
Node *getSRTail() {
	return srTailPtr;
}

/** Gets the head of the packet queue */
Node *getPktHead() {
	return pktHeadPtr;
}

/** Gets the tail of the packet queue */
Node *getPktTail() {
	return pktTailPtr;
}

////////////////////////
/// QUEUE OPERATIONS ///
////////////////////////

/**
 * Enqueus a SR ID at the end of the SR queue
 * 
 * @param nVal new SR ID to be added
 */
void srEnqueue(int nVal) {
	if (srHeadPtr == NULL) {
		// the router list is empty
		srHeadPtr = new Node(nVal);

		if (srHeadPtr != NULL) {
			// the memory was successfully allocated
			srTailPtr = srHeadPtr;
		} else {
			cout << "Memory Allocation Failed. Router " << sr_id;
			cout << " Not Added." << endl;
		}
	} else {
		// the router list is not empty
		srTailPtr->nextPtr = new Node(nVal);

		if (srTailPtr->nextPtr != NULL) {
			// memory successfully allocated
			srTailPtr = srTailPtr->nextPtr;
		} else {
			cout << "Memory Allocation Failed. Router " << sr_id;
			cout << " Not Added." << endl;
		}
	}
}

/**
 * Dequeues the first node from the SR queue, returns the value, and deletes it
 * to free the memory
 * 
 * @return SR ID contained within first (now deleted) node
 */
int srDequeue() {
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
		cout << "Quitting the program." << endl;
		exit(1);
	}
}

void pktEnqueue() {
	if (pktHeadPtr == NULL) {
		// the queue is empty
		pktHeadPtr = new Packet(*this);

		if ()
	}
}