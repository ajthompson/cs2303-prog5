/**
 * @Author: Alec Thompson
 *
 * Packet.h
 *
 * Contains data being sent by the routers.
 */
#ifndef PACKET_H
#define PACKET_H

#ifndef DEBUG
 #define DEBUG 0
#endif

class Node;
class Sender;

class Packet {
	friend class Event;
	friend class Node;
	friend class Sender;
    friend class Mule;
private:
	int source_id;		// ID of the source router
	int timestamp;		// time of creation at the source router
	int pkt_size;		// Size of the packet
	int delay;			// used before arrival at receiver to hold propagation time
						// used after for time of completion
	Node *headPtr;		// pointer to the head of the SR
	Node *tailPtr;		// pointer to the tail of the SR
	Packet *nextPtr;	// pointer to the next packet in the queue
public:
	// constructors
	Packet();
	Packet(int, int, int);	
	Packet(Sender*, int);
	// destructor
	~Packet();
	// setters and getters
	void setID(int);
	int getID();
	void setTimestamp(int);
	int getTimestamp();
	void setSize(int);
	int getSize();
	void setProp(int);
	void setDelay(int);						// sets the delay
	int getDelay();							// get the delay
	Node *getHead();
	Node *getTail();
	Packet *getNext();
	void copyQueue(Packet);					// copies a queue from the argument packet to this packet
	void copyQueue(Sender *);
	// queue operations
	void enqueue(int);						// enqueues another item in the SR
	int dequeue();							// dequeues the first item in the SR
	Node *dequeueNode();					// dequeues the entire node
	// metafunctions
	int nLength();
	void printPacket();
};

#endif
