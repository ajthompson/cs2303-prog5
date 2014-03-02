/* 
* @Author: ajthompson
* @Date:   2014-02-27 20:34:19
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-27 21:26:13
*/

#include <iostream>
#include "Event.h"
#include "Packet.h"
#include "Sender.h"
#include "Node.h"
using namespace std;

int main(){
	int numbers[7] = {19, 15, 14, 35, 65, 89, 14};
	Sender *sPtr = new Sender(15);
	sPtr->setX();
	sPtr->setY(15);
	sPtr->setArrivalTime(42);
	sPtr->setPktCount(500);
	sPtr->setPktSize(3);
	for (int i = 0; i < 7; ++i) {
		sPtr->srEnqueue(numbers[i]);
	}
	Packet *pPtr = new Packet(sPtr, 42);
	cout << "BEGINNING EVENT TESTING" << endl;
	cout << "CREATING EVENT" << endl;
	Event *ePtr = new Event();
	cout << "EVENT CREATED - PRINTING EVENT" << endl;
	ePtr->printEvent();
	cout << "TESTING TYPES" << endl;
	cout << "SETTING TYPE TO SENDER_INIT" << endl;
	ePtr->setType(SENDER_INIT);
	cout << "PRINTING EVENT" << endl;
	ePtr->printEvent();
	cout << "SETTING TYPE TO T_END_FROM_S" << endl;
	ePtr->setType(T_END_FROM_S);
	cout << "PRINTING EVENT" << endl;
	ePtr->printEvent();
	cout << "TYPE TESTING COMPLETE" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "ADDING SENDER" << endl;
    ePtr->setSender(sPtr);
    cout << "PRINTING EVENT" << endl;
    ePtr->printEvent();
    cout << "CHANGE SENDER DATA" << endl;
    ePtr->getSender()->setPktCount(30);
    ePtr->getSender()->setArrivalTime(1000);
    ePtr->getSender()->srDequeue();
    cout << "PRINTING SENDER VIA EPTR" << endl;
    ePtr->getSender()->printSender();
    cout << "PRINTING SENDER VIA SPTR" << endl;
    sPtr->printSender();
    cout << "PRINTING EVENT" << endl;
    ePtr->printEvent();
    cout << "SENDER TESTING COMPLETE" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "ADDING PACKET" << endl;
    ePtr->setPacket(pPtr);
    cout << "PRINTING EVENT" << endl;
    ePtr->printEvent();
    cout << "TESTING FINISHED" << endl;
    return 0;
}