/* 
* @Author: ajthompson
* @Date:   2014-02-27 09:41:37
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-27 09:51:06
*/

#include <iostream>
#include <vector>
#include <sstream>	// operations for removing items from input lines
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

	// iterate through the senders, creating them based on input
	
}