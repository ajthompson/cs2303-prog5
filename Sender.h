/**
 * Sender.h
 * 
 * Header file for sender routers,
 */
#ifndef SENDER_H
#define SENDER_H

#ifndef DEBUG
 #define DEBUG 0
#endif

class Packet;
class Node;

#include "Shared.h"

class Sender {
    friend class Event;
	friend class Packet;
	friend class Node;
    friend class Receiver;
private:
    // Static Figures
    static int total_senders;    /*  Total number of senders */
    static int field_length;     /*  Total height of the field   */
    static int *yVals;           /* A static field of all the possible y positions of the senders  */
    static int *xVals;           /* A static field of all the possible x positions of the senders  */
    
    // Statics done
	int xPos;			// x position of sender, initializes to 0
	int yPos;			// y position of sender
	int id;				// ID number of sender
	int arrival_time;	// time to begin transmitting
	int pkt_count;		// number of packets remaining to transmit
	int pkt_size;		// size of packets to send - 1,2,3
	Node *srHeadPtr;	// pointer to the head of the SR queue
	Node *srTailPtr;	// pointer to the tail of the SR queue
	Packet *pktHeadPtr;	// pointer to the head of the packet queue
	Packet *pktTailPtr;	// pointer to the tail of the packet queue
public:

    Sender(int);				// constructor
	Sender(int, int, int, int);	// constructor
	~Sender();					// destructor
	/** Setter functions */
	void setX();
	void setY(int);
	void setID(int);
	void setArrivalTime(int);
	void setPktCount(int);
	void setPktSize(int);
	/** Getter functions */
	int getX();
	int getY();
	int getID();
	int getArrivalTime();
	int getPktCount();
	int getPktSize();
	Node *getSRHead();
	Node *getSRTail();
	Packet *getPktHead();
	Packet *getPktTail();
	/** Queue operations */
	void srEnqueue(int);	// enqueues an int to the SR
	int srDequeue();		// dequeues an int from the SR
	void pktEnqueue(int);		// enqueues a packet
	Packet *pktDequeue();	// dequeues a packet and returns a pointer to the packet
	/** Miscellaneous Operations */
	int nCount();
	int pCount();
	void printNodes();
	void printPackets();
	void printSender();
    
    
    /*  Static Members  */
    // Variables
    static struct point *l_op;
    static int num_senders;
    
    // Functions
    static void init_sender(int, int);
    static int getTotNumSend();
    static void print_SendLoc();
};

#endif
