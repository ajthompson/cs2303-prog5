/* 
* @Author: ajthompson
* @Date:   2014-02-27 09:41:37
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-27 10:35:44
*/

#include <iostream>
#include <vector>
#include <sstream>	// operations for removing items from input lines
#include <cstdlib>	// for srand and rand
#include <ctime>	// for time(NULL) for srand
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
	// store values to put into routers
	int x, y, 
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
	for (int i = 0; i < s; ++i) {
		x = 1 + rand() % d;
		y = rand() % d;
		if (checkMulePos(x, y, i)) {
			muleList[i] = new Sender();
			muleList[i]->setX();
			muleList[i]->setY(y);
			muleList[i]->setID(direction(rand() % ));
			muleList[i]->setDir()
			++counter;	// increment counter
		} else {
			--i;	// decrement i to retry this value with a different position
		}
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