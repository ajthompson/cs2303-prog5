/**
 * Packet.h
 *
 * Contains data being sent by the routers.
 */
#ifndef PACKET_H
#define PACKET_H

#include "Queue.h"
// forward declaration of Queues and Nodes
class Queue<int>;

class Packet : Queue<int> {
private:
	int source_id;	// ID of the source router
	int timestamp;	// time of creation at the source router
	int pkt_size;	// Size of the packer
	int delay;		// not used until arrival at receiver
public:
	Packet();
	~Packet();
	
};

#endif