/**
 * EventList.h
 *
 * Header file for the event list.  This is the class that controls the
 * simulation, and where the bulk of the processing takes place
 */
#ifndef EVENTLIST_H_
#define EVENTLIST_H_

#ifndef DEBUG
 #define DEBUG 1
#endif

#include <vector>
#include "Field.h"
#include "Event.h"
#include "Packet.h"
#include "Mule.h"
#include "Sender.h"
#include "Receiver.h"
#include "Node.h"

// forward declarations of necessary classes
class Event;
class Sender;
class Mule;
class Receiver;

class EventList {
	friend class Event;
	friend class Sender;
	friend class Mule;
	friend class Receiver;
private:
	int t;	// simulation time
	int numSenders;
	int numMules;
	int numReceivers;
	std::vector<Sender *> senderList;
	std::vector<Mule *> muleList;
	std::vector<Receiver *> receiverList;
	Field *fieldPtr;	// pointer to the field
	Event *headPtr;		// pointer to the head of the event list
public:
	/** Constructor */
	EventList(int, int, int, int);
	/** Setters */
	void setTime(int);
	void incTime();
	/** Getters */
	int getTime();
	Sender *findSender(int);
	Mule *findMule(int);
	Receiver *findReceiver(int);
	/** List Operations */
	void insertEvent(EventType, Sender*, Mule*, Receiver*, Packet*, int);
	/** Processing */
	
	int calcPropagation(int, int, int, int);
	void processList();
	/** Process submethods */
	void senderInit(Event*);
	void tEndSender(Event*);
	void tEndMule(Event*);
	void pEndMule(Event*);
	void pEndReceiver(Event*);
	void eListMove();
	/** Checkers */
	bool checkSenderPos(int, int, int);
	bool checkMulePos(int, int, int);
	bool checkReceiverPos(int, int, int);
	bool sendersEmpty();
	bool onlyMove();
	bool checkNULLlessThanEqual(Event*, int);
	bool checkNULLlessThan(Event*, int);
	/** Printing */
	void printReceivers();
	void printEventList();
};

#endif