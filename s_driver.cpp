/* 
* @Author: ajthompson
* @Date:   2014-02-25 17:13:17
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-25 22:50:36
*
* Tests for Senders
*/

#include <iostream>
#include "Sender.h"
#include "Packet.h"
#include "Node.h"
using namespace std;

int main(){
	int numbers[]  = {19, 17, 14, 51, 52, 19, 18};
	int y = 5;
	int source_id = 20;
	int t_arrive = 3;
	int pkt_count = 300;
	int pkt_size = 2;
	int t = 100;

	cout << "CREATING SENDERS" << endl;
    Sender *emptySender = new Sender();
    Sender *fillSender = new Sender(y, source_id, t_arrive, pkt_count, pkt_size);
    cout << "SENDERS CREATED" << endl;

    cout << "PRINTING EMPTYSENDER" << endl;
    emptySender->printSender();

    cout << "PRINTING FILLSENDER" << endl;
    fillSender->printSender();

    cout << "SETTING VALUES FOR EMPTYSENDER" << endl;
    cout << "	SETTING X" << endl;
    emptySender->setX();
    cout << "	SETTING Y" << endl;
    emptySender->setY(y);
    cout << "	SETTING SOURCE ID" << endl;
    emptySender->setID(source_id);
    cout << "	SETTING ARRIVAL TIME" << endl;
    emptySender->setArrivalTime(t_arrive);
    cout << "	SETTING PACKET COUNT" << endl;
    emptySender->setPktCount(pkt_count);
    cout << "	SETTING PACKET SIZE" << endl;
    emptySender->setPktSize(pkt_size);
    cout << "PRINTING EMPTYSENDER" << endl;
    emptySender->printSender();

    cout << "GETTING VALUES FOR FILLSENDER" << endl;
    cout << "	GETTING X" << endl;
    cout << fillSender->getX() << endl;
    cout << "	GETTING Y" << endl;
    cout << fillSender->setY(y) << endl;
    cout << "	GETTING SOURCE ID" << endl;
    cout << fillSender->setID(source_id) << endl;
    cout << "	GETTING ARRIVAL TIME" << endl;
    cout << fillSender->setArrivalTime(t_arrive) << endl;
    cout << "	GETTING PACKET COUNT" << endl;
    cout << fillSender->setPktCount(pkt_count) << endl;
    cout << "	GETTING PACKET SIZE" << endl;
    cout << fillSender->setPktSize(pkt_size) << endl;
    cout << "	GETTING SRHEAD" << endl;
    cout << fillSender->getSRHead() << endl;
    cout << "	GETTING SRTAIL" << endl;
    cout << fillSender->getSRTail() << endl;
    cout << "	GETTING PKTHEAD" << endl;
    cout << fillSender->getPktHead() << endl;
    cout << "	GETTING PKTTAIL" << endl;
    cout << fillSender->getPktTail() << endl;
    cout << "PRINTING EMPTYSENDER" << endl;
    fillSender->printSender();

    cout << "ADDING NODES TO FILLSENDER" << endl;

    return 0;
}