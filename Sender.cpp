/* 
* @Author: ajthompson
* @Date:   2014-02-25 10:16:11
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-28 14:06:46
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
	setX();
	setY(l_op[num_senders].yPoint);
	setID(s_id);
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
Sender::Sender(int s_id, int t, int count, int size) {
	setX();
	setY(l_op[num_senders].yPoint);
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

////////////////////////
/// SETTER FUNCTIONS ///
////////////////////////

/**
 * Sets the x position to 0, because senders can only exist on the left side of the field
 */
void Sender::setX() {
	xPos = 0;
}

/**
 * Sets the y position to the input value.
 * 
 * @param y New y position
 */
void Sender::setY(int y) {
	yPos = y;
}

/**
 * Sets the node ID to the new ID value.
 * 
 * @param nID New ID
 */
void Sender::setID(int nID) {
	id = nID;
}

/**
 * Sets the arrival time to the input value.
 * 
 * @param t 
 */
void Sender::setArrivalTime(int t) {
	arrival_time = t;
}

/**
 * Sets the amount of packets to be sent by the Sender
 * 
 * @param c The number of packets to be sent by the node
 */
void Sender::setPktCount(int c) {
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
	return xPos;
}

/** Gets the Y position */
int Sender::getY() {
	return yPos;
}

/** Gets the ID of the sender */
int Sender::getID() {
	return id;
}

/** Gets the time of beginning transmission */
int Sender::getArrivalTime() {
	return arrival_time;
}

/** Gets the amount of packets that are remaining to be sent */
int Sender::getPktCount() {
	return pkt_count;
}

/** Gets the size of the packets being sent by the node */
int Sender::getPktSize() {
	return pkt_size;
}

/** Gets the head of the SR queue */
Node *Sender::getSRHead() {
	return srHeadPtr;
}

/** Gets the tail of the SR queue */
Node *Sender::getSRTail() {
	return srTailPtr;
}

/** Gets the head of the packet queue */
Packet *Sender::getPktHead() {
	return pktHeadPtr;
}

/** Gets the tail of the packet queue */
Packet *Sender::getPktTail() {
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
	if (srHeadPtr == NULL) {
		// the router list is empty
		srHeadPtr = new Node(nVal);

		if (srHeadPtr != NULL) {
			// the memory was successfully allocated
			srTailPtr = srHeadPtr;
		} else {
			cout << "Memory Allocation Failed. Router " << nVal;
			cout << " Not Added." << endl;
			cout << "Quitting the program." << endl;
			exit(1);
		}
	} else {
		// the router list is not empty
		srTailPtr->nextPtr = new Node(nVal);

		if (srTailPtr->nextPtr != NULL) {
			// memory successfully allocated
			srTailPtr = srTailPtr->nextPtr;
		} else {
			cout << "Memory Allocation Failed. Router " << nVal;
			cout << " Not Added." << endl;
			cout << "Quitting the program." << endl;
			exit(1);
		}
	}
}

/**
 * Dequeues the first node from the SR queue, returns the value, and deletes it
 * to free the memory
 * 
 * @return SR ID contained within first (now deleted) node
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
	if (pktHeadPtr == NULL) {
		// the queue is empty
		pktHeadPtr = new Packet(this, t);

		if (pktHeadPtr == NULL) {
			cout << "Memory Allocation Failed. Packet Not Added." << endl;
			cout << "Quitting the program." << endl;
			exit(1);
		}
	} else {
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
int Sender::num_senders = 0;
point *Sender::l_op = new point[1];

void Sender::init_sender(int tot_sndrs, int fld_lngth){
    total_senders = tot_sndrs;
    field_length = fld_lngth;
    delete(yVals);
    delete(l_op);
    l_op = new struct point[total_senders];
    yVals = new int[field_length];
    // Initalize the number of possible locations for the senders
    for (int i = 0; i < field_length; i++) {
        yVals[i] = i;
    }
    /*  Below function is a Fisher-Yates shuffel. Found it on the internet  */
    for (int i = field_length - 1; i > 0; --i)
    {
        std::swap(yVals[i], yVals[rand() % (i + 1)]);
    }
    /*  This algorythm is not mine, it is somebody elses    */
    
}

void Sender::fill_listOP(){
    int tempY;
    //Initalize the struct to all -2
    for (int i = 0; i < total_senders; i++){
        l_op[i].yPoint = -2;
        l_op[i].xPoint = 0;
    }
    getPoint(&tempY);
    /*See if it's in the list   */
    /* If it is then get a new one  */
    /* If it's not then store it in the list at the next point  */
    for (int j = 0; j < total_senders; j++){
        while(!not_used(tempY)){
            getPoint(&tempY);
        }
        for (int i = 0; i < total_senders; i++){
            if (l_op[i].yPoint == -2){
                l_op[i].yPoint = tempY;
                break;
            }
        }
    }
}

void Sender::getPoint(int *point2){
    if (field_length > num_senders){
        *point2 = yVals[rand() % (total_senders)];
    }else{
        *point2 = yVals[rand() % (total_senders)];
    }
}

int Sender::not_used(int ypt){
    int returnVal;
    for (int i = 0; i < total_senders; i++){
        if (ypt == l_op[i].yPoint){    /*Checks if the point has been used yet, if so return 0 */
            returnVal = 0;
            break;
        }
        else{
            returnVal = 1;
        }
    }
    return returnVal;
}

void Sender::print_SendLoc(){
    for (int i = 0; i < total_senders; i++){
        cout << "(" << l_op[i].xPoint << "," << l_op[i].yPoint << ")" << endl;
    }
}


// STATIC GETTER:
int Sender::getTotNumSend(){
    return total_senders;
    
}



