/**
 * Packet.h
 *
 * Contains data being sent by the routers.
 */
#ifndef PACKET_H
#define PACKET_H

// forward declaration of Queues and Nodes
class Node;

class Packet {
private:
	int source_id;		// ID of the source router
	int timestamp;		// time of creation at the source router
	int pkt_size;		// Size of the packet
	int delay;			// not used until arrival at receiver
	Node *headPtr;		// pointer to the head of the SR
	Node *tailPtr;		// pointer to the tail of the SR
	Packet *nextPtr;	// pointer to the next packet in the queue
public:
	Packet(int, int, int, Node*, Node*);	// constructor
	~Packet();						// destructor
	void setDelay(int);				// sets the delay
	void enqueue(int);				// enqueues another item in the SR
	int dequeue();					// dequeues the first item in the SR
};

#endif