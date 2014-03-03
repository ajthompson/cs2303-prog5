/* 
* @Author: ajthompson
* @Date:   2014-02-26 20:54:43
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-03-03 16:23:17
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
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
		cout << "dimension - one side of the two-dimensional MANET field" << endl;
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

		srand(time(NULL));

		// TROY PUT RANDOMIZATION STUFF HERE
        Sender::init_sender(senders, dimension);
        Receiver::make_FieldVals(receivers, dimension);
        Mule::make_FieldVals(mules, dimension);
        Mule::fill_listOP();

		// create the event list
		EList = new EventList(senders, mules, receivers, dimension);
		// run the simulation
		EList->processList();
	}

	return 0;
}
