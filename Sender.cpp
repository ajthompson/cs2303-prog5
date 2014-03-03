/* 
* @Author: Troy Hughes
* @Date:   2014-02-25 10:16:11
* @Last Modified by:   thhughes
* @Last Modified time: 2014-03-02 20:46:22
*/

#include <iostream>
#include <cstdlib>
#include "Sender.h"
#include "Packet.h"
#include "Node.h"
using std::cout;
using std::endl;
using std::exit;
using namespace std;

/**
 * Constructs an empty sender
 */
Sender::Sender(int s_id) {
    /*  Author: Troy Hughes */
	setX();
	setY(yVals[num_senders]);
	setID(s_id);
	setArrivalTime(0);
	setPktCount(0);
	setPktSize(1);
	srHeadPtr = NULL;
	srTailPtr = NULL;
	pktHeadPtr = NULL;
	pktTailPtr = NULL;
    num_senders++;
    
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
Sender::Sender(int s_id, int t, int count, int size) {
    /*  Author: Troy Hughes */
	setX();
	setY(yVals[num_senders]);
	setID(s_id);
	setArrivalTime(t);
	setPktCount(count);
	setPktSize(size);
	srHeadPtr = NULL;
	srTailPtr = NULL;
	pktHeadPtr = NULL;
	pktTailPtr = NULL;
    num_senders++;
}

/** Destructor */
Sender::~Sender() {
    /*  Author: Troy Hughes */
	Node *a, *b;
	Packet *c, *d;

	// deconstruct the node list
	a = srHeadPtr;
	while (a != NULL) {
		b = a->nextPtr;
		delete a;
		a = b;
	}

	// deconstruct the packet list
	c = pktHeadPtr;
	while (c != NULL) {
		d  = c->nextPtr;
		delete c;
		c = d;
	}
}

////////////////////////
/// SETTER FUNCTIONS ///
////////////////////////

/**
 * Sets the x position to 0, because senders can only exist on the left side of the field
 */
void Sender::setX() {
    /*  Author: Troy Hughes */
	xPos = 0;
}

/**
 * Sets the y position to the input value.
 * 
 * @param y New y position
 */
void Sender::setY(int y) {
    /*  Author: Troy Hughes */
	yPos = y;
}

/**
 * Sets the node ID to the new ID value.
 * 
 * @param nID New ID
 */
void Sender::setID(int nID) {
    /*  Author: Troy Hughes */
	id = nID;
}

/**
 * Sets the arrival time to the input value.
 * 
 * @param t 
 */
void Sender::setArrivalTime(int t) {
    /*  Author: Troy Hughes */
	arrival_time = t;
}

/**
 * Sets the amount of packets to be sent by the Sender
 * 
 * @param c The number of packets to be sent by the node
 */
void Sender::setPktCount(int c) {
    /*  Author: Troy Hughes */
	pkt_count = c;
}

/**
 * Sets the packet size to be sent by the router.  This is a value from
 * 1 to 3 inclusive.  If the input value is outside of this range, it defaults
 * to 1.
 * 
 * @param s The new value for packet size
 */
void Sender::setPktSize(int s) {
    /*  Author: Troy Hughes */
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
int Sender::getX() {
    /*  Author: Troy Hughes */
	return xPos;
}

/** Gets the Y position */
int Sender::getY() {
    /*  Author: Troy Hughes */
	return yPos;
}

/** Gets the ID of the sender */
int Sender::getID() {
    /*  Author: Troy Hughes */
	return id;
}

/** Gets the time of beginning transmission */
int Sender::getArrivalTime() {
    /*  Author: Troy Hughes */
	return arrival_time;
}

/** Gets the amount of packets that are remaining to be sent */
int Sender::getPktCount() {
    /*  Author: Troy Hughes */
	return pkt_count;
}

/** Gets the size of the packets being sent by the node */
int Sender::getPktSize() {
    /*  Author: Troy Hughes */
	return pkt_size;
}

/** Gets the head of the SR queue */
Node *Sender::getSRHead() {
    /*  Author: Troy Hughes */
	return srHeadPtr;
}

/** Gets the tail of the SR queue */
Node *Sender::getSRTail() {
    /*  Author: Troy Hughes */
	return srTailPtr;
}

/** Gets the head of the packet queue */
Packet *Sender::getPktHead() {
    /*  Author: Troy Hughes */
	return pktHeadPtr;
}

/** Gets the tail of the packet queue */
Packet *Sender::getPktTail() {
    /*  Author: Troy Hughes */
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
void Sender::srEnqueue(int nVal) {
    /*  Author: Troy Hughes */
	if (srHeadPtr == NULL) {
		// the router list is empty
		srHeadPtr = new Node(nVal);
	} else if (srTailPtr == NULL) {
		srHeadPtr->nextPtr = new Node(nVal);
		srTailPtr = srHeadPtr->nextPtr;
	} else {
		// the router list is not empty
		srTailPtr->nextPtr = new Node(nVal);
		srTailPtr = srTailPtr->nextPtr;
	}
}

/**
 * Dequeues the first node from the SR queue, returns the value, and deletes it
 * to free the memory
 * 
 * @return SR ID contained within first (now deleted) node
 */
int Sender::srDequeue() {
    /*  Author: Troy Hughes */
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

/**
 * Enqueues a new packet on the sender, basing it off of the sender stats.
 * 
 * @param t System time, time of packet creation
 */
void Sender::pktEnqueue(int t) {
    /*  Author: Troy Hughes */
	#if DEBUG
		cout << "Enqueuing new packet" << endl;
	#endif

	if (pktHeadPtr == NULL) {

		#if DEBUG
			cout << "Packet Queue Empty" << endl;
		#endif

		// the queue is empty
		pktHeadPtr = new Packet(this, t);

		#if DEBUG
			cout << "New packet created" << endl;
		#endif

		if (pktHeadPtr == NULL) {
			cout << "Memory Allocation Failed. Packet Not Added." << endl;
			cout << "Quitting the program." << endl;
			exit(1);
		}
	} else if (pktTailPtr == NULL) {

		#if DEBUG
			cout << "Packet Queue has one packet" << endl;
		#endif

		pktHeadPtr->nextPtr = new Packet(this, t);
		pktTailPtr = pktHeadPtr->nextPtr;
	} else {

		#if DEBUG
			cout << "Packet Queue has multiple packets" << endl;
		#endif
			
		// the queue is not empty
		pktTailPtr->nextPtr = new Packet(this, t);

		if (pktTailPtr->nextPtr != NULL) {
			// memory allocation succeeded
			pktTailPtr = pktTailPtr->nextPtr;
		} else {
			cout << "Memory Allocation Failed. Packet Not Added." << endl;
			cout << "Quitting the program." << endl;
			exit(1);
		}
	}
}

/**
 * Dequeues the first packet in the queue and returns.
 * 
 * @return A pointer to the first packet in the queue.
 */
Packet *Sender::pktDequeue() {
    /*  Author: Troy Hughes */
	Packet *tempPtr;

	tempPtr = pktHeadPtr;

	if (tempPtr != NULL) {
		// the queue is not empty
		pktHeadPtr = tempPtr->nextPtr;

		if (pktHeadPtr == NULL) {
			// the list is now empty
			pktTailPtr = pktHeadPtr;
		}
		return tempPtr;
	} else {
		cout << "List is empty.  No items dequeued." << endl;
		cout << "Quitting the program." << endl;
		exit(1);
	}
}

/**
 * Counts the number of SR nodes in the queue
 * 
 * @return Number of nodes in the queue
 */
int Sender::nCount() {
    /*  Author: Troy Hughes */
	Node *currentPtr = srHeadPtr;
	int length = 0;
	while (currentPtr != NULL) {
		++length;
		currentPtr = currentPtr->nextPtr;
	}

	return length;
}

/**
 * Counts the number of packets in the queue
 * 
 * @return Number of packets in the queue
 */
int Sender::pCount() {
    /*  Author: Troy Hughes */
	Packet *currentPtr = pktHeadPtr;
	int length = 0;
	while (currentPtr != NULL) {
		++length;
		currentPtr = currentPtr->nextPtr;
	}

	return length;
}

/** Prints out the queue of SR nodes */
void Sender::printNodes() {
    /*  Author: Troy Hughes */
	Node *currentPtr = srHeadPtr;

	cout << "Beginning of SR queue." << endl;
	while (currentPtr != NULL) {
		currentPtr->printNode();
		currentPtr = currentPtr->nextPtr;
	}
	cout << "End of SR queue." << endl;
}

/** Prints out the queue of packets */
void Sender::printPackets() {
    /*  Author: Troy Hughes */
	Packet *currentPtr = pktHeadPtr;

	cout << "Beginning of Packet queue." << endl;
	while (currentPtr != NULL) {
		currentPtr->printPacket();
		currentPtr = currentPtr->nextPtr;
	}
	cout << "End of Packet queue." << endl;
}

/** Prints out the Sender */
void Sender::printSender() {
    /*  Author: Troy Hughes */
	cout << "Printing Sender " << getID() << endl;
	cout << "X: " << getX() << endl;
	cout << "Y: " << getY() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Arrival Time: " << getArrivalTime() << endl;
	cout << "Packet Count Remaining: " << getPktCount() << endl;
	cout << "Packet Size: " << getPktSize() << endl;
	cout << "SR HeadPtr: " << getSRHead() << endl;
	cout << "SR TailPtr: " << getSRTail() << endl;
	cout << "Packet HeadPtr: " << getPktHead() << endl;
	cout << "Packet TailPtr: " << getPktTail() << endl;
	printNodes();
	printPackets();
	cout << "Finished Printing Sender " << getID() << endl;
}

/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
// Author: Troy Hughes
int Sender::total_senders = -1;
int Sender::field_length  = -1;
int *Sender::yVals = new int[1];
int *Sender::xVals = new int[1];
int Sender::num_senders = 0;

void Sender::init_sender(int tot_sndrs, int fld_lngth){
    /*  Author: Troy Hughes */
    total_senders = tot_sndrs;
    field_length = fld_lngth;
    delete(yVals);
    delete(xVals);
    yVals = new int[field_length];
    xVals = new int[field_length];
    // Initalize the number of possible locations for the senders
    for (int i = 0; i < field_length; i++) {
        xVals[i] = 0;
        yVals[i] = i;
    }
    /*  Below function is a Fisher-Yates shuffel. Found it on the internet  */
    for (int i = field_length - 1; i > 0; --i)
    {
        std::swap(yVals[i], yVals[rand() % (i + 1)]);
    }
    /*  This algorythm is not mine, it is somebody elses    */
    
}
void Sender::print_SendLoc(){
    /*  Author: Troy Hughes */
    cout << "These are the x values"    << endl;
    for (int i = 0; i < field_length; i++){
        cout << i << ": "<< xVals[i] << endl;
    }
    cout << "These are the y values"    << endl;
    for (int i = 0; i < field_length; i++){
        cout << i << ": "<< yVals[i] << endl;
    }
}


// STATIC GETTER:
int Sender::getTotNumSend(){
    /*  Author: Troy Hughes */
    return total_senders;
    
}
