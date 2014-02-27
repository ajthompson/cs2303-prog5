/* 
* @Author: ajthompson
* @Date:   2014-02-26 20:54:43
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-26 21:14:10
*/

#include <iostream>
#include <cstdlib>
#include "EventList.h"
using std::cout;
using std::endl;
using namespace std;

int main(int argc, char *argv[]) {
	char *sourceStr, *receiverStr, *muleStr, *dimStr;
	int senders, receivers, mules, dimension;
	EventList *EList;

	if (argc != 5) {
		cout << "Wrong input syntax. Correct syntax is:" << endl;
		cout << "./program5 sources receivers mules dimension" << endl;
		cout << endl;
		cout << "sources - number of source routers" << endl;
		cout << "receivers - number of receiver routers" << endl;
		cout << "mules - number of mobile mule routers" << endl;
		cout << "dimension - one side of the two-dimensional MANET field"
	} else {
		// retrieve the strings from argv
		sourceStr = argv[1];
		receiverStr = argv[2];
		muleStr = argv[3];
		dimStr = argv[4];
		// convert to integers
		senders = atoi(sourceStr);
		receivers = atoi(receiverStr);
		mules = atoi(muleStr);
		dimension = atoi(dimStr);

		// create the event list
		EList = new EventList(senders, mules, receivers, dimension);
		// initialize the event list
		EList->initEventList();
		// run the simulation
		EList->simulate();
	}

	return 0;
}