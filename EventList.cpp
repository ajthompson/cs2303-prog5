/* 
* @Author: ajthompson
* @Date:   2014-02-27 09:41:37
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-27 12:11:43
*/

#include <iostream>
#include <vector>
#include <sstream>	// operations for removing items from input lines
#include <cstdlib>	// for srand and rand
#include <ctime>	// for time(NULL) for srand
#include <string>
#include "EventList.h"
using namespace std;

/**
 * Constructor for the event list class.  Creates and initializes the object
 * 
 * @param s Amount of senders
 * @param m Amount of mules
 * @param r Amount of receivers
 * @param d Dimension of square MANET field
 */
EventList::EventList(int s, int m, int r, int d) {
	int counter = 1;
	int numLine = s + m + r;
	string line;	// store input strings
	// store values to put into routers
	int x, y, s_id, a_time, packets, pkt_size, sr_size, sr_val;
	Sender *updatePtr;	// stores the packet found with a given ID
	// set program time to 0
	t = 0;
	// resize vectors for the proper amount of routers
	senderList.resize(s);
	muleList.resize(m);
	receveiverList.resize(r);
	// create the field
	fieldPtr = new Field(d, numLine);
	// initialize the event list to empty
	headPtr = NULL;

	// iterate through the vector creating the senders
	for (int i = 0; i < s; ++i) {
		x = 0;
		y = rand() % d;
		if (checkSenderPos(x, y, i)) {
			senderList[i] = new Sender();
			senderList[i]->setX();
			senderList[i]->setY(y);
			senderList[i]->setID(counter);
			++counter;	// increment counter
		} else {
			--i;	// decrement i to retry this value with a different position
		}
	}

	// iterate through the vector creating the mules
	for (int i = 0; i < m; ++i) {
		x = 1 + rand() % d;
		y = rand() % d;
		if (checkMulePos(x, y, i)) {
			muleList[i] = new Mule();
			muleList[i]->setX(x);
			muleList[i]->setY(y);
			muleList[i]->setID(counter);
			muleList[i]->setDir(muleList[i]->randDir());
			++counter;	// increment counter
		} else {
			--i;	// decrement i to retry this sender with a different position
		}
	}

	// // iterate through the vector creating the receivers
	// for (int i = 0; i < r; ++i) {
	// 	x = d - 1;
	// 	y = rand() % d;
	// 	if (checkReceiverPos(x, y, i)) {
	// 		receiverList[i] = new Receiver();
	// 		receiverList[i]->setX();
	// 		receiverList[i]->setY(y);
	// 		receiverList[i]->setID(counter);
	// 		++counter;	// increment counter
	// 	} else {
	// 		--i;	// decrement i to retry this value with a different position
	// 	}
	// }
	
	cout << "Enter source data in the form:" << endl;
	cout << "SourceID arrival_time packets pkt_size SR_size SR" << endl;
	cout << "SourceID - ID of source router this applys to" << endl;
	cout << "arrival_time - Time the source router arrives and begins transmitting" << endl;
	cout << "packets - number of packets to be sent" << endl;
	cout << "pkt_size - size of packets to be sent" << endl;
	cout << "SR_size - number of routers the packet must be sent through, including this one" << endl;
	cout << "SR - route the packets must take - includes the source router" << endl;
	// read in input file and assign data to senders - based on
	// @author Pete Becker
	// 	http://stackoverflow.com/questions/15092172/c-reading-fixed-number-of-lines-of-integers-with-unknown-number-of-integers-in
	// 	Feb 26, 2013
	while(getline(cin, line)) {
		istringstream in(line);
		in >> s_id;
		in >> a_time;
		in >> packets;
		in >> pkt_size;
		in >> sr_size;

		// find the necessary sender and set values
		updatePtr = findSender(s_id, s);
		updatePtr->setArrivalTime(a_time);
		updatePtr->setPktCount(packets);
		updatePtr->setPktSize(pkt_size);
		for (int i = 0; i < sr_size; ++i) {
			in >> sr_val;
			updatePtr->srEnqueue(sr_val);
			insertEvent(SENDER_INIT, updatePtr, NULL, NULL, NULL, arrival_time);
		}
	}
}

////////////////////////
/// GETTER FUNCTIONS ///
////////////////////////

/** Gets the pointer to the sender with the given ID */
Sender *EventList::findSender(int id, int numSender) {

}

//////////////////
/// PROCESSING ///
//////////////////

bool EventList::checkSenderPos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (x == (senderList[i]->getX()) && y == (senderList[i]->getY())) {
			returnVal &= false;
		}
	}
	return isSame;
}

bool EventList::checkMulePos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (x == (muleList[i]->getX()) && y == (muleList[i]->getY())) {
			returnVal &= false;
		}
	}
	return isSame;
}

bool EventList::checkReceiverPos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (x == (receiverList[i]->getX()) && y == (receiverList[i]->getY())) {
			returnVal &= false;
		}
	}
	return isSame;
}