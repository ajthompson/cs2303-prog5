/**
 * Packet.h
 *
 * Contains data being sent by the routers.
 */
#ifndef PACKET_H
#define PACKET_H

class Node;
class Sender;

class Packet {
	friend class Node;
	friend class Sender;
private:
	int source_id;		// ID of the source router
	int timestamp;		// time of creation at the source router
	int pkt_size;		// Size of the packet
	int delay;			// not used until arrival at receiver
	Node *headPtr;		// pointer to the head of the SR
	Node *tailPtr;		// pointer to the tail of the SR
	Packet *nextPtr;	// pointer to the next packet in the queue
public:
	Packet();
	Packet(int, int, int);			// constructor
	Packet(Sender, int);
	// setters and getters
	void setID(int);
	int getID();
	void setTimestamp(int);
	int getTimestamp();
	void setSize(int);
	int getSize();
	void setDelay(int);						// sets the delay
	int getDelay();							// get the delay
	Node *getHead();
	Node *getTail();
	Packet *getNext();
	void copyQueue(Packet);					// copies a queue from the argument packet to this packet
	void copyQueue(Sender);
	// queue operations
	void enqueue(int);						// enqueues another item in the SR
	int dequeue();							// dequeues the first item in the SR
	Node *dequeueNode();					// dequeues the entire node
	// metafunctions
	int nLength();
	void printPacket();
};

#endif