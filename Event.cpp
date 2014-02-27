/* 
* @Author: ajthompson
* @Date:   2014-02-26 21:58:44
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-27 09:20:29
*/

#include <iostream>
#include "Event.h"
using namespace std;

/** Event Constructor */
Event::Event() {
	type = 0;
	senderPtr = NULL;
	mulePtr = NULL;
	receiverPtr = NULL;
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

/** Sets the pointer to a mule */
void Event::setMule(Mule *mPtr) {
	mulePtr = mPtr;
}

/** Sets the pointer to a receiver */
void Event::setReceiver(Receiver *rPtr) {
	receiverPtr = rPtr;
}

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

/** Gets the pointer to a mule */
Mule *Event::getMule() {
	return mulePtr;
}

/** Gets the pointer to a receiver */
Receiver *Event::getReceiver() {
	return receiverPtr;
}

/** Gets the pointer to a packet */
Packet *Event::getPacket() {
	return pktPtr;
}