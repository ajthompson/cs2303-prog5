/* 
* @Author: ajthompson
* @Date:   2014-02-27 09:41:37
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-03-03 16:16:05
*/

#include <iostream>
#include <vector>
#include <sstream>	// operations for removing items from input lines
#include <cstdlib>	// for srand and rand
#include <ctime>	// for time(NULL) for srand
#include <string>
#include <cmath>
#include "EventList.h"
using namespace std;

/**
 * Constructor for the event list class.  Creates and initializes the object
 * 
 * @param s Amount of senders
 * @param m Amount of mules
 * @param r Amount of receivers
 * @param d Dimension of square MANET field
 */
EventList::EventList(int s, int m, int r, int d) {
	int counter = 1;
	string line;	// store input strings
	// store values to put into routers
	int x, y, s_id, a_time, packets, pkt_size, sr_size, sr_val;
	Sender *updatePtr;	// stores the packet found with a given ID
	// set program time to 0
	t = 0;
	// set the amount of routers
	numSenders = s;
	numMules = m;
	numReceivers = r;
	// resize vectors for the proper amount of routers
	senderList.resize(s);
	muleList.resize(m);
	receiverList.resize(r);
	// create the field
	fieldPtr = new Field(d, s+m+r);
	// initialize the event list to empty
	headPtr = NULL;

	// iterate through the vector creating the senders
	for (int i = 0; i < s; ++i) {
		senderList[i] = new Sender(counter);
		fieldPtr->setPos(senderList[i]->getX(), senderList[i]->getY(), 
						 senderList[i]->getID());
		++counter;	// increment counter
	}

	// iterate through the vector creating the mules
	for (int i = 0; i < m; ++i) {
		muleList[i] = new Mule(counter);
		fieldPtr->setPos(muleList[i]->m_getX(), muleList[i]->m_getY(), 
						 muleList[i]->m_getID());
		++counter;	// increment counter
	}

	// iterate through the vector creating the receivers
	for (int i = 0; i < r; ++i) {
		receiverList[i] = new Receiver(counter, s);
		fieldPtr->setPos(receiverList[i]->getX(), receiverList[i]->getY(), 
						 receiverList[i]->getID());
		++counter;	// increment counter
	}
	
	cout << "Enter source data in the form:" << endl;
	cout << "SourceID arrival_time packets pkt_size SR_size SR" << endl;
	cout << "SourceID - ID of source router this applys to" << endl;
	cout << "arrival_time - Time the source router arrives and begins transmitting" << endl;
	cout << "packets - number of packets to be sent" << endl;
	cout << "pkt_size - size of packets to be sent" << endl;
	cout << "SR_size - number of routers the packet must be sent through, including this one" << endl;
	cout << "SR - route the packets must take - includes the source router" << endl;
	// read in input file and assign data to senders - created by:
	// @author Pete Becker
	// 	http://stackoverflow.com/questions/15092172/c-reading-fixed-number-of-lines-of-integers-with-unknown-number-of-integers-in
	// 	Feb 26, 2013
	// 	
	// 	Modified by Alec Thompson, Feb 27th, 2014
	// 		- changed while loop to a for loop
	while(getline(cin, line)) {
		istringstream in(line);
		in >> s_id;
		in >> a_time;
		in >> packets;
		in >> pkt_size;
		in >> sr_size;

		// find the necessary sender and set values
		updatePtr = findSender(s_id);
		updatePtr->setArrivalTime(a_time);
		updatePtr->setPktCount(packets);
		updatePtr->setPktSize(pkt_size);
		for (int i = 0; i < sr_size; ++i) {
			in >> sr_val;
			updatePtr->srEnqueue(sr_val);
		}
		insertEvent(SENDER_INIT, updatePtr, NULL, NULL, NULL, a_time);
	}

	// set the first move event
	insertEvent(MOVE, NULL, NULL, NULL, NULL, 10);
	// print the field
	fieldPtr->printField();
}

////////////////////////
/// SETTER FUNCTIONS ///
////////////////////////

/** Sets the time to the given value */
void EventList::setTime(int nTime) {
	t = nTime;
}

/** Increments the time by 1 */
void EventList::incTime() {
	++t;
}

////////////////////////
/// GETTER FUNCTIONS ///
////////////////////////

/** Gets the simulation time */
int EventList::getTime() {
	#if DEBUG
		cout << "Returning time" << endl;
	#endif
	return t;
}

/** Gets the pointer to the sender with the given ID */
Sender *EventList::findSender(int id) {
	Sender *returnPtr = NULL;
	for (int i = 0; i < numSenders; ++i) {
		if (id == senderList[i]->getID()) {
			returnPtr = senderList[i];
		}
	}
	if (returnPtr == NULL) {
		cout << "Sender with that ID not found.  Returning NULL" << endl;
	}

	return returnPtr;
}

/** Gets the pointer to the mule with the given ID */
Mule *EventList::findMule(int id) {
	Mule *returnPtr = NULL;
	for (int i = 0; i < numMules; ++i) {
		if (id == muleList[i]->m_getID()) {
			returnPtr = muleList[i];
		}
	}
	if (returnPtr == NULL) {
		cout << "Mule with that ID not found.  Returning NULL" << endl;
	}
	return returnPtr;
}

/** Gets the pointer to the receiver with the given ID */
Receiver *EventList::findReceiver(int id) {
	Receiver *returnPtr = NULL;
	for (int i = 0; i < numReceivers; ++i) {
		if (id == receiverList[i]->getID()) {
			returnPtr = receiverList[i];
		}
	}
	if (returnPtr == NULL) {
		cout << "Receiver with that ID not found.  Returning NULL" << endl;
	}
	return returnPtr;
}

///////////////////////
/// LIST OPERATIONS ///
///////////////////////

/**
 * Creates an event and adds it to the list.  No event needs all data fields.
 * The fields to use for each event type are below:
 *
 * 				Sender initialization		Sender Transmission End
 * @param eT   	SENDER_INIT					T_END_FROM_S
 * @param sPtr 	Pointer to target sender 	Pointer to Transmitting Sender
 * @param mPtr 	NULL						NULL
 * @param rPtr 	NULL						NULL
 * @param pPtr 	NULL						NULL
 * @param tL   	Sender Time of Arrival		Sender.pkt_size
 *
 *  			Mule Transmission End		Propagation to Mule End
 * @param eT   	T_END_FROM_M				P_END_TO_M
 * @param sPtr 	NULL						NULL
 * @param mPtr 	Pointer to target mule		Pointer to target mule
 * @param rPtr 	NULL						NULL
 * @param pPtr 	NULL						Pointer to target packet
 * @param tL   	Packet Size 				Propagation Time
 *
 *  			Propagation to Receiver End	Move Mules
 * @param eT   	P_END_TO R					P_END_TO_M
 * @param sPtr 	NULL						NULL
 * @param mPtr 	NULL						NULL
 * @param rPtr 	Pointer to target receiver	NULL
 * @param pPtr 	Pointer to targer packet	NULL
 * @param tL   	Propagation time			10
 */
void EventList::insertEvent(EventType eT, Sender *sPtr, Mule *mPtr, Receiver *rPtr, Packet *pPtr, int tL) {
	Event *currentPtr = this->headPtr;
	Event *previousPtr = NULL;

	if (currentPtr == NULL) {

		#if DEBUG
			cout << "HeadPtr: " << headPtr << endl;
		#endif
		// if the list is empty
		this->headPtr = new Event();

		#if DEBUG
			cout << "New event created" << endl;
			cout << "HeadPtr: " << headPtr << endl;
		#endif

		if (headPtr != NULL) {
			#if DEBUG
				cout << "Memory successfully allocated" << endl;
			#endif
			// memory was successfully allocated
			// set the event's fields
			headPtr->setType(eT);
			#if DEBUG
				cout << "Type Set to " << headPtr->getType() << endl;
			#endif
			headPtr->setSender(sPtr);
			#if DEBUG
				cout << "SenderPtr set to " << headPtr->getSender() << endl;
			#endif
			headPtr->setMule(mPtr);
			#if DEBUG
				cout << "MulePtr set to " << headPtr->getMule() << endl;
			#endif
			headPtr->setReceiver(rPtr);
			#if DEBUG
				cout << "ReceiverPtr set to " << headPtr->getReceiver() << endl;
			#endif
			headPtr->setPacket(pPtr);
			#if DEBUG
				cout << "PacketPtr set to " << headPtr->getPacket() << endl;
			#endif
			headPtr->setTime(tL);
			#if DEBUG
				cout << "Time left set to " << headPtr->getTime() << endl;
			#endif
			headPtr->setNext(NULL);
			#if DEBUG
				cout << "NextPtr set to " << headPtr->getNext() << endl;
			#endif
		} else {
			cout << "Memory allocation failed - event not created" << endl;
		}
	} else {
		#if DEBUG
			cout << "The list is not empty" << endl;
		#endif
		// the list is not empty
		if (eT == MOVE) {
			#if DEBUG
				cout << "Event is a MOVE" << endl;
			#endif
			// iterator for MOVE events
			// places events after all events with the same time left
			while (checkNULLlessThanEqual(currentPtr, tL)) {
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
			}
		} else {
			#if DEBUG
				cout << "Event is not a MOVE" << endl;
			#endif
			// iterator for non-move events, 
			// places them before all events with the same time left
			while (checkNULLlessThan(currentPtr, tL)) {
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
			}
		}

		if (previousPtr == NULL) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		#if DEBUG
			cout << "Target location reached" << endl;
			cout << "currentPtr = " << currentPtr << endl;
			cout << "previousPtr = " << previousPtr << endl;
		#endif
		// create the new event
		previousPtr->nextPtr = new Event();
		if (previousPtr->nextPtr != NULL) {
			// memory allocation was successful
			previousPtr->nextPtr->setType(eT);
			previousPtr->nextPtr->setSender(sPtr);
			previousPtr->nextPtr->setMule(mPtr);
			previousPtr->nextPtr->setReceiver(rPtr);
			previousPtr->nextPtr->setPacket(pPtr);
			previousPtr->nextPtr->setTime(tL);
			previousPtr->nextPtr->setNext(currentPtr);

			#if DEBUG
				cout << "Event added" << endl;
				previousPtr->nextPtr->printEvent();
			#endif
		} else {
			cout << "Memory allocation failed - event not created" << endl;
		}
	}
}

//////////////////
/// PROCESSING ///
//////////////////



/**
 * Calculates the propagation time of the packet using the formula:
 *
 * 		pTime = ceil (log2(sqrt((x2-x1)^2 + (y2-y1)^2))));
 * 
 * @param  x1 X position of sending router
 * @param  y1 Y position of sending router
 * @param  x2 X position of receiving router
 * @param  y2 Y position of receiving router
 * @return    Propagation time of packet
 */
int EventList::calcPropagation(int x1, int y1, int x2, int y2) {
	return ceil(log2(sqrt(pow((double)x2-x1, (double)2) + pow((double)y2-y1, (double)2))));
}

/** Processes the event list */
void EventList::processList() {
	Event *currentPtr = headPtr;

	while ((!sendersEmpty()) || (!onlyMove())) {

		#if DEBUG
			cout << "Event List at time " << t << endl;
			cout << "Before event processing" << endl;
			printEventList();
			cout << "Time: " << t << endl;
		#endif

		// iterate through the list
		while (currentPtr != NULL) {
			if (currentPtr->getTime() == 0){
			// if the event's timer is complete
				switch (currentPtr->getType()) {
					case SENDER_INIT:

						#if DEBUG
							cout << "Sender Initialization Event at time " << t << endl;
						#endif

						senderInit(currentPtr);
						break;
					case T_END_FROM_S:

						#if DEBUG
							cout << "Sender Transmission End at time " << t << endl;
						#endif

						tEndSender(currentPtr);
						break;
					case T_END_FROM_M:

						#if DEBUG
							cout << "Mule Transmission End at time " << t << endl;
						#endif

						tEndMule(currentPtr);
						break;
					case P_END_TO_M:

						#if DEBUG
							cout << "Propagation To Mule End at time " << t << endl;
						#endif

						pEndMule(currentPtr);
						break;
					case P_END_TO_R:

						#if DEBUG
							cout << "Propagation To Receiver End at time " << t << endl;
						#endif

						pEndReceiver(currentPtr);
						break;
					case MOVE:

						#if DEBUG
							cout << "Moving mules at time " << t << endl;
						#endif

						eListMove();
						break;
					default:
						break;
				}
			// change the head pointer
				headPtr = currentPtr->nextPtr;
				// delete currentPtr;
				currentPtr = headPtr;
			} else {
			// the event's timer is still going
				currentPtr->setTime(currentPtr->getTime() - 1);
				currentPtr = currentPtr->nextPtr;
			}
		}

		#if DEBUG
			cout << "Event List at time " << t << endl;
			cout << "After event processing" << endl;
			printEventList();
		#endif

		++t;
		currentPtr = headPtr;
	}
	printReceivers();
	fieldPtr->printField();
}

/** Initializes the sender with a packet and sets up a transmission finish event */
void EventList::senderInit(Event *ePtr) {
	Sender *sPtr = ePtr->getSender();
	Mule *mPtr;		// store target mule
	int Sx, Sy, Mx, My;	// to store x and y values of the sender and goal mule
	sPtr->pktEnqueue(t);	// create a new packet with timestamp t
	sPtr->getPktHead()->dequeue();	// remove source id from packet SR queue
	// get sender location
	Sx = sPtr->getX();
	Sy = sPtr->getY();
	// get target location
	mPtr = findMule(sPtr->getPktHead()->getHead()->getData());
	Mx = mPtr->m_getX();
	My = mPtr->m_getY();
	// insert propagation time into packet delay fieldPtr
	sPtr->getPktHead()->setProp(calcPropagation(Sx, Sy, Mx, My));
	// insert a "Sender Transmission End" event into the list
	insertEvent(T_END_FROM_S, sPtr, NULL, NULL, NULL, sPtr->getPktSize());
}

/**
 * Dequeues the packet from the sender, and inserts it into a propagation event
 * Decrements the senders remaining packet count.
 * Then, if the sender still has to send more packets, then another packet and 
 * transmission event are created.  Otherwise the sender's location in the 
 * senderList vector is set to NULL, it is cleared from the fieldPtr, and the
 * sender is deleted
 * 
 * @param ePtr Pointer to sender transmission end event
 */
void EventList::tEndSender(Event *ePtr) {

	#if DEBUG
		cout << "Entered tEndSender" << endl;
	#endif

	// set up object pointers
	Sender *sPtr = ePtr->getSender();
	Packet *pPtr = sPtr->pktDequeue();
	int Sx, Sy, Mx, My;	// to store x and y values of the sender and goal mule
	Mule *mPtr = findMule(pPtr->dequeue());	// removes the first SR value from the list

	#if DEBUG
		cout << "Set up object pointers" << endl;
		cout << "sPtr = " << sPtr << endl;
		cout << "pPtr = " << pPtr << endl;
		cout << "mPtr = " << mPtr << endl;
		cout << "Sender's packet count = " << sPtr->getPktCount() << endl;
	#endif

	// decrement sender's packet counter
	sPtr->setPktCount(sPtr->getPktCount() - 1);

	#if DEBUG
		cout << "Decremented Packet Count" << endl;
		cout << "pktCount = " << sPtr->getPktCount() << endl;
		cout << "Creating a new propagation event" << endl;
	#endif

	// create a new propagation event
	insertEvent(P_END_TO_M, NULL, mPtr, NULL, pPtr, pPtr->getDelay());

	#if DEBUG
		cout << "Created a new propagation event" << endl;
	#endif

	// determine what the sender does next
	if (sPtr->getPktCount() > 0) {
		// sender still has more packets to send, create a new packet

		#if DEBUG
			cout << "Sender has " << sPtr->getPktCount() << " packets remaining" << endl;
			cout << "Enqueuing new packet" << endl;
		#endif

		sPtr->pktEnqueue(t);
		// dequeue first node of the packet's SR queue
		
		#if DEBUG
			cout << "New Packet enqueued" << endl;
			cout << "First SR node (sender ID) dequeuing" << endl;
		#endif
		
		sPtr->getPktHead()->dequeue();
		
		#if DEBUG
			cout << "First SR Node dequeued" << endl;
			cout << "Getting Sender Coordinates" << endl;
		#endif
		
		// get sender coordinates
		Sx = sPtr->getX();
		Sy = sPtr->getY();
		
		#if DEBUG
			cout << "(Sx, Sy) = (" << Sx <<  ", " << Sy << ")" << endl;
			cout << "Getting Mule Coordinates" << endl;
		#endif
		
		// get new target mule and find its position
		mPtr = findMule(sPtr->getPktHead()->getHead()->getData());
		Mx = mPtr->m_getX();
		My = mPtr->m_getY();
		
		#if DEBUG
			cout << "(Mx, My) = (" << Mx <<  ", " << My << ")" << endl;
			cout << "Inserting Propagation Delay" << endl;
		#endif
		
		// insert propagation time into packet delay fieldPtr
		sPtr->getPktHead()->setProp(calcPropagation(Sx, Sy, Mx, My));
		
		#if DEBUG
			cout << "Propagation delay inserted" << endl;
			cout << "Inserting transmission complete event" << endl;
		#endif
		
		// insert a transmission complete event
		insertEvent(T_END_FROM_S, sPtr, NULL, NULL, NULL, sPtr->getPktSize());
		
		#if DEBUG
			cout << "Transmission complete event inserted" << endl;
		#endif
	} else {
		// set the sender's position in the fieldPtr to 0
		fieldPtr->setPos(sPtr->getX(), sPtr->getY());
		// set the pointer in the array to NULL
		senderList[sPtr->getID() - 1] = NULL;
		// delete the sender
		delete sPtr;
	}
}

/**
 * Determines whether the target router of the packet in the event is a
 * reveiver or mule, and then inserts the appropriate propagation event
 * 
 * @param ePtr Pointer to mule transmission end event.
 */
void EventList::tEndMule(Event *ePtr) {
	// set up object pointers
	Mule *mPtr1 = ePtr->getMule();		// transmitting mule
	Packet *pPtr = mPtr1->pktDequeue();	// transmitted packet
	Mule *mPtr2;
	Receiver *rPtr;
	int t_id = pPtr->dequeue();	// set target router id

	// determine whether the target router is a receiver or mule
	if (t_id > numSenders + numMules) {	// target is a receiver
		// find the address of target receiver
		rPtr = findReceiver(t_id);
		// create a new propagation to receiver event
		insertEvent(P_END_TO_R, NULL, NULL, rPtr, pPtr, pPtr->getDelay());
	} else {	// target is a mule
		// find the address of target mule
		mPtr2 = findMule(t_id);
		// create a new propagation to mule event
		insertEvent(P_END_TO_M, NULL, mPtr2, NULL, pPtr, pPtr->getDelay());
	}
}

/**
 * Calculates the propagation time to the next target router, sets the delay
 * as that and enqueues it in the mule.  It then creates a transmission from
 * mule end event.
 * 
 * @param ePtr Pointer to the propagation to mule event
 */
void EventList::pEndMule(Event *ePtr) {
	// set up location variables
	int Mx, My, Tx, Ty;
	// set up object pointers
	Mule *mPtr = ePtr->getMule();
	Packet *pPtr = ePtr->getPacket();
	Mule *tPtr;
	Receiver *rPtr;
	// set transmitting mule location values
	Mx = mPtr->m_getX();
	My = mPtr->m_getY();
	// get next packet target node to calculate new propagation delay
	int t_id = pPtr->getHead()->getData();
	// determine whether new target is a mule or receiver
	if (t_id > numSenders + numMules) {	// target is a receiver
		rPtr = findReceiver(t_id);
		Tx = rPtr->getX();
		Ty = rPtr->getY();
	} else {	// target is a mule
		tPtr = findMule(t_id);
		Tx = tPtr->m_getX();
		Ty = tPtr->m_getY();
	}
	// set propagation delay
	pPtr->setProp(calcPropagation(Mx, My, Tx, Ty));
	// enqueue packet in mule
	mPtr->pktEnqueue(pPtr);
	// insert a mule transmission end event
	insertEvent(T_END_FROM_M, NULL, mPtr, NULL, NULL, pPtr->getSize());
}

/** Passes the packet to the target redeiver that then processes it */
void EventList::pEndReceiver(Event *ePtr) {
	ePtr->getReceiver()->pPacketDelay(ePtr->getPacket(), t);
}

/**
 * Iterate through all the mules and move them in the appropriate direction.
 * If the new position is a wall, they bounce off in the other direction, if
 * it is a mule, they "hop" over it to the spot on the other size.
 */
void EventList::eListMove() {
	for (int i = 0; i < numMules; ++i) {
		// clear the current position of the mule in the fieldPtr map
		fieldPtr->setPos(muleList[i]->m_getX(), muleList[i]->m_getY());
		// move the mule
		muleList[i]->moveMule();
		// set new position in the map
		fieldPtr->setPos(muleList[i]->m_getX(), muleList[i]->m_getY(), muleList[i]->m_getID());
	}
	cout << "---------------------------------------" << endl;
	cout << "                 TIME " << t << endl;
	cout << "---------------------------------------" << endl;
	// print the fieldPtr
	fieldPtr->printField();

	// create new movement event
	insertEvent(MOVE, NULL, NULL, NULL, NULL, 10);
}

/////////////////////////
/// CHECKER FUNCTIONS ///
/////////////////////////

/** Checks if the current position is held by a sender */
bool EventList::checkSenderPos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (senderList[i] != NULL) {
			if ((x == (senderList[i]->getX())) && y == ((senderList[i]->getY()))) {
				isSame &= false;
			}
		}
	}
	return isSame;
}

/** Checks if the current position is held by a mule */
bool EventList::checkMulePos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (muleList[i] != NULL) {
			if ((x == (muleList[i]->m_getX())) && y == ((muleList[i]->m_getY()))) {
				isSame &= false;
			}
		}
	}
	return isSame;
}

/** Checks if the current position is held by a receiver */
bool EventList::checkReceiverPos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (receiverList[i] != NULL) {
			if ((x == (receiverList[i]->getX())) && (y == (receiverList[i]->getY()))) {
				isSame &= false;
			}
		}
	}
	return isSame;
}

/**
 * Checks if the sender list only has pointers to NULL.
 * 
 * @return True if all values NULL, otherwise false
 */
bool EventList::sendersEmpty() {
	bool val = true;
	for (int i = 0; i < numSenders; ++i) {
		if (senderList[i] != NULL) {
			val = false;
			
		}
	}

	if (val) {
		#if DEBUG
			cout << "All Senders Complete" << endl;
		#endif
	}
	return val;
}

/**
 * Checks if the event list only contains move events.  If so, there are no packets
 * currently propagating, and the program is finished if all senders are also gone.
 * 
 * @return Return true if only move events, otherwise false.
 */
bool EventList::onlyMove() {
	Event *currentPtr = headPtr;
	bool val = true;

	while (currentPtr != NULL) {
		if (currentPtr->type == MOVE) {
			// do nothing
		} else {
			val = false;
		}
		currentPtr = currentPtr->nextPtr;
	}
	if (val) {
		#if DEBUG
			cout << "Only Movement Events remain" << endl;
		#endif
	}
	return val;
}

bool EventList::checkNULLlessThanEqual(Event *ePtr, int t) {
	bool val = true;
	if (ePtr == NULL) {
		val = false;
	} else if (ePtr->getTime() > t) {
		val = false;
	}
	return val;
}

bool EventList::checkNULLlessThan(Event *ePtr, int t) {
	bool val = true;
	if (ePtr == NULL) {
		val = false;
	} else if (ePtr->getTime() >= t) {
		val = false;
	}
	return val;
}

///////////////////////
/// PRINT FUNCTIONS ///
///////////////////////

void EventList::printReceivers() {
	double TADweighted = 0;
	long totalNumPackets = 0;
	double totalAvg;

	// iterate through the receiver list
	for (int i = 0; i < numReceivers; ++i) {
		TADweighted += receiverList[i]->getTAD() * receiverList[i]->getTNP();
		totalNumPackets += receiverList[i]->getTNP();
		receiverList[i]->print_R_Data();
	}

	// calculate total average delay
	totalAvg = TADweighted / totalNumPackets;

	cout << "Total Number of Packets Printed: " << totalNumPackets << endl;
	cout << "Overall Average Delay: " << totalAvg << endl;
}

void EventList::printEventList() {
	Event *currentPtr = headPtr;

	while (currentPtr != NULL) {
		currentPtr->printEvent();
		currentPtr = currentPtr->nextPtr;
	}
}
