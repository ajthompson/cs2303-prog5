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
	static int t;	// simulation time
	static std::vector<Sender> senderList;
	static std::vector<Mule> muleList;
	static std::vector<Receiver> muleList;
	Field *fieldPtr;	// pointer to the field
	Event *headPtr;		// pointer to the head of the event list
public:
	/** Constructor */
	Field(int, int, int, int);
	/** Setters */
	void setTime(int);
	void incTime(int);

	/** Getters */

	/** List Operations */
	void insertSorted();
	void push()
}