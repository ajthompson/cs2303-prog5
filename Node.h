/**
 * Node.h
 *
 * Container class for sources, mule, and receiver nodes.
 */

#ifndef DEBUG
 #define DEBUG 1
#endif

#ifndef NODE_H
 #define NODE_H

#include <iostream>
#include "SRList.h"
 using cout;
 using endl;
 using namespace std;

class Node {
	friend class SRList;
private:
	typedef struct packet {
		int 
	} Packet;

	typedef struct Packet *PacketPtr;

	int sourceID;
	int arrival_time;
	int packets;
	int pkt_size;
	List SR;
	PacketPtr headPtr;
}