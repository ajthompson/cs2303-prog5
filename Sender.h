/**
 * Sender.h
 * 
 * Header file for sender routers,
 */
#ifndef SENDER_H
#define SENDER_H

class Packet, Node;

class Sender {
	friend class Packet;
	friend class Node;
private:
	int xPos;			// x position of sender, initializes to 0
	int yPos;			// y position of sender
	int id;				// ID number of sender
	int arrival_time;	// time to begin transmitting
	int pkt_count;		// number of packets remaining to transmit
	int pkt_size;		// size of packets to send - 1,2,3
	Node *srHeadPtr;	// pointer to the head of the SR queue
	Node *srTailPtr;	// pointer to the tail of the SR queue
	Packet *pktHeadPtr;	// pointer to the head of the packet queue
						// there should only ever be one packet in a senders queue
						// completion of transmission triggers the addition of another
						// therefore no tailPtr is needed
public:
	Sender(int, int, int, int, int);	// constructor
	~Sender();				// deconstructor
	void srEnqueue(int);	// enqueues an int to the SR
	int srDequeue();		// dequeues an int from the SR
	void pktEnqueue(int);	// enqueues a packet
	Packet* pktDequeue();	// dequeues a packet and returns a pointer to the packet
}