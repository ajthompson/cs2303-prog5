/**
 * Event.h
 *
 * Events are the nodes of an event list.  Contains all necessary members
 * an event might need, but not all are used.
 */
#ifndef EVENT_H_
#define EVENT_H_

class EventList;
class Sender;
class Mule;
class Receiver;
class Packet;

typedef enum {SENDER_INIT, T_END_FROM_S, T_END_FROM_M, P_END_TO_M, P_END_TO_R,
				MOVE} EventType;

class Event {
	friend class EventList;
private:
	EventType type;			// type of event
	Sender *senderPtr;		// pointer to a sender
	Mule *mulePtr;			// pointer to a mule
	Receiver *receiverPtr;	// pointer to a receiver
	Packet *pktPtr;			// pointer to a packet
	int timeLeft;			// time remaining until the event occurs
	Event *nextPtr;			// pointer to next event in list
public:
	/** Constructor */
	Event();
	/** Setter Functions */
	void setType(EventType);
	void setSender(Sender*);
	void setMule(Mule*);
	void setReceiver(Receiver*);
	void setPacket(Packet*);
	void setTime(int);
	void setNext(Event*);
	/** Getter Functions */
	EventType getType();
	Sender *getSender();
	Mule *getMule();
	Receiver *getReceiver();
	Packet *getPacket();
	int getTime();
	Event *getNext();
	/** Processing */
	void printEvent();
};

#endif