/* 
* @Author: ajthompson
* @Date:   2014-02-25 17:13:17
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-26 10:17:02
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
    Sender *fillSender = new Sender(source_id, t_arrive, pkt_count, pkt_size);
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
    cout << fillSender->getY() << endl;
    cout << "	GETTING SOURCE ID" << endl;
    cout << fillSender->getID() << endl;
    cout << "	GETTING ARRIVAL TIME" << endl;
    cout << fillSender->getArrivalTime() << endl;
    cout << "	GETTING PACKET COUNT" << endl;
    cout << fillSender->getPktCount() << endl;
    cout << "	GETTING PACKET SIZE" << endl;
    cout << fillSender->getPktSize() << endl;
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
    for (int i = 0; i < 7; ++i) {
    	fillSender->srEnqueue(numbers[i]);
    	cout << "Node " << i << " containing " << numbers[i] << " added" << endl;
    	cout << fillSender->nCount() << " nodes in queue" << endl;
    	fillSender->printNodes();
    }
    cout << "FINISHED ADDING NODES TO FILLSENDER" << endl;

    cout << "ADDING PACKET TO FILLSENDER" << endl;
    fillSender->pktEnqueue(t);
    cout << "PACKET ADDED TO FILLSENDER AT TIME " << t << endl;
    cout << "THERE ARE NOW " << fillSender->pCount() << " PACKETS IN FILLSENDER" << endl;

    cout << "PRINTING PACKET" << endl;
    fillSender->printPackets();

    cout << "PRINTING FILLSENDER" << endl;
    fillSender->printSender();

    cout << "DEQUEUING AND PRINTING PACKET" << endl;
    fillSender->pktDequeue()->printPacket();

    cout << "PRINTING FILLSENDER" << endl;
    fillSender->printSender();

    cout << "DEQUEUING AND PRINTING NODE" << endl;
    cout << "Dequeued node contains " << fillSender->srDequeue() << endl;

    cout << "PRINTING FILLSENDER" << endl;

    cout << "ADDING PACKET TO FILLSENDER" << endl;
    fillSender->pktEnqueue(t);
    cout << "PACKET ADDED TO FILLSENDER AT TIME " << t << endl;
    cout << "THERE ARE NOW " << fillSender->pCount() << " PACKETS IN FILLSENDER" << endl;

    cout << "PRINTING PACKET" << endl;
    fillSender->printPackets();

    cout << "PRINTING FILLSENDER" << endl;
    fillSender->printSender();

    cout << "DEQUEUING AND PRINTING PACKET" << endl;
    fillSender->pktDequeue()->printPacket();

    cout << "PRINTING FILLSENDER" << endl;
    fillSender->printSender();
    
    cout << "Testing Static Placement of all the Senders" << endl;
    Sender::init_sender(10, 10);
    Sender::fill_listOP();
    Sender::print_SendLoc();
    
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "TESTING COMPLETE" << endl;

    return 0;
}