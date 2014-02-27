/**
 * EventList.h
 *
 * Header file for the event list.  This is the class that controls the
 * simulation, and where the bulk of the processing takes place
 */
#ifndef DEBUG
 #define DEBUG 0
#endif

#ifndef EVENTLIST_H_
#define EVENTLIST_H_

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
	static std::vector<Sender> senderList;
	static std::vector<Mule> muleList;
	static std::vector<Receiver> receiverList;
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
	/** List Operations */
	void insertEvent(EventType, Sender*, Mule*, Receiver*, Packet*, int);
	/** Processing */
	bool checkSenderPos(int, int, int);
	bool checkMulePos(int, int, int);
	bool checkReceiverPos(int, int, int);
	int calcPropagation(int, int, int, int);
}