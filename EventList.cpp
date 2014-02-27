/* 
* @Author: ajthompson
* @Date:   2014-02-27 09:41:37
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-27 11:09:36
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

	// // iterate through the vector creating the senders
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
	cout << "SourceID"
	// read in input file and assign data to senders
	// @author Pete Becker
	// 	http://stackoverflow.com/questions/15092172/c-reading-fixed-number-of-lines-of-integers-with-unknown-number-of-integers-in
	// 	Feb 26, 2013
	while(getline(cin, line)) {
		istringstream in(line);
		in >> s_id;
		in >> a_time;
	}
}

//////////////////
/// PROCESSING ///
//////////////////

bool checkSenderPos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (x == (senderList[i]->getX()) && y == (senderList[i]->getY())) {
			returnVal &= false;
		}
	}
	return isSame;
}

bool checkMulePos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (x == (muleList[i]->getX()) && y == (muleList[i]->getY())) {
			returnVal &= false;
		}
	}
	return isSame;
}

bool checkReceiverPos(int x, int y, int num) {
	bool isSame = true;
	for (int i = 0; i < num; ++i) {
		if (x == (receiverList[i]->getX()) && y == (receiverList[i]->getY())) {
			returnVal &= false;
		}
	}
	return isSame;
}