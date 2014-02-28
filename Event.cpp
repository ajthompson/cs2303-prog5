/* 
* @Author: ajthompson
* @Date:   2014-02-26 21:58:44
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-27 21:50:07
*/

#include <iostream>
#include "Event.h"
#include "Sender.h"
#include "Packet.h"
#include "Node.h"
using namespace std;

/** Event Constructor */
Event::Event() {
	type = MOVE;
	senderPtr = NULL;
	// mulePtr = NULL;
	// receiverPtr = NULL;
	pktPtr = NULL;
	timeLeft = 0;
	nextPtr = NULL;
}

////////////////////////
/// SETTER FUNCTIONS ///
////////////////////////

/** Sets the type of the event */
void Event::setType(EventType eType) {
	type = eType;
}

/** Sets the pointer to a sender */
void Event::setSender(Sender *sPtr) {
	senderPtr = sPtr;
}

// /** Sets the pointer to a mule */
// void Event::setMule(Mule *mPtr) {
// 	mulePtr = mPtr;
// }

// /** Sets the pointer to a receiver */
// void Event::setReceiver(Receiver *rPtr) {
// 	receiverPtr = rPtr;
// }

/** Sets the pointer to a packet */
void Event::setPacket(Packet *pPtr) {
	pktPtr = pPtr;
}

/** Sets the time remaining */
void Event::setTime(int t) {
	timeLeft = t;
}

/** Sets the next event */
void Event::setNext(Event *ePtr) {
	nextPtr = ePtr;
}

////////////////////////
/// GETTER FUNCTIONS ///
////////////////////////

/** Gets the event type */
EventType Event::getType() {
	return type;
}

/** Gets the pointer to a sender */
Sender *Event::getSender() {
	return senderPtr;
}

// /** Gets the pointer to a mule */
// Mule *Event::getMule() {
// 	return mulePtr;
// }

// /** Gets the pointer to a receiver */
// Receiver *Event::getReceiver() {
// 	return receiverPtr;
// }

/** Gets the pointer to a packet */
Packet *Event::getPacket() {
	return pktPtr;
}

/** Gets the time remaining */
int Event::getTime() {
	return timeLeft;
}

/** Gets the pointer to the next event in the event list */
Event *Event::getNext() {
	return nextPtr;
}

//////////////////
/// PROCESSING ///
//////////////////

/** Prints the event */
void Event::printEvent() {
	cout << "--------------------------------------------------------" << endl;
	cout << "Event Type: ";
	switch (getType()) {
		case SENDER_INIT:
			cout << "Initializing Sender" << endl;
			break;
		case T_END_FROM_S:
			cout << "Sender Transmission Complete" << endl;
			break;
		case T_END_FROM_M:
			cout << "Mule Transmission Complete" << endl;
			break;
		case P_END_TO_M:
			cout << "Propagation to Mule Complete" << endl;
			break;
		case P_END_TO_R:
			cout << "Propagation to Receiver Complete" << endl;
			break;
		case MOVE:
			cout << "Moving Mules" << endl;
			break;
		default:
			cout << "NO TYPE" << endl;
			break;
	}
	cout << "Sender Pointer: " << getSender() << endl;
	if (getSender() != NULL) 
		getSender()->printSender();
	// cout << "Mule Pointer: " << getMule() << endl;
	// if (getMule() != NULL)	
	// 	getMule()->printMule();
	// cout << "Receiver Pointer: " << getReceiver() << endl;
	// if (getReceiver() != NULL)
	// 	getReceiver()->printReceiver();
	cout << "Packet Pointer: " << getPacket() << endl;
	if (getPacket() != NULL)
		getPacket()->printPacket();
	cout << "Time Remaining: " << getTime() << endl;
	cout << "Next Event Pointer: " << getNext() << endl; 
	cout << "--------------------------------------------------------" << endl;
}