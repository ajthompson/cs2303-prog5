/* 
* @Author: ajthompson
* @Date:   2014-02-25 14:29:26
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-02-25 16:50:27
*/
#include <iostream>
#include "Packet.h"
#include "Node.h"
using namespace std;

int main() {
	int numbers[]  = {19, 17, 14, 51, 52, 19, 18};
	Node nodeArr[7];
	int s_id = 1;
	int timestamp = 10;
	int pkt_size = 3;
	int t = 100;

	Packet *testFillNum = new Packet();
	Packet *testFillInit;
	Node *rmNode;

	// set up test nodes
	for (int i = 0; i < 7; i++) {
		nodeArr[i].setData(numbers[i]);
	}

	cout << "Packet Class Testing." << endl;
	cout << "Initialized Empty Packet." << endl;
	cout << "testFillNum:" << endl;
	testFillNum->printPacket();
	cout << "testFillNode:" << endl;
	cout << "Setting Packet Contents." << endl;
	testFillNum->setID(s_id);
	testFillNum->setTimestamp(timestamp);
	testFillNum->setSize(pkt_size);
	testFillNum->setDelay(t);
	cout << "Filled Packets with Nodes." << endl;
	cout << "testFillNum: " << endl;
	testFillNum->printPacket();

	cout << "Adding Nodes via Data." << endl;
	for (int i = 0; i < 7; ++i) {
		testFillNum->enqueue(numbers[i]);
		cout << "Node " << i << " Added." << endl;
		testFillNum->printPacket();
	}
	cout << "Adding Nodes via Data Complete." << endl;

	cout << "Initializing Packet with All Data." << endl;
	testFillInit = new Packet(s_id, timestamp, pkt_size);
	testFillInit->copyQueue(*testFillNum);
	testFillInit->setDelay(t);
	cout << "Packet Created: testFillInit" << endl;
	testFillInit->printPacket();

	cout << "Removing node data." << endl;
	for (int i = 0; i < 7; ++i) {
		cout << "Removing Node " << i << " - " << testFillNum->dequeue() << endl;
	}
	cout << "Printing testFillNum" << endl;
	testFillNum->printPacket();
	for (int i = 0; i < 7; ++i) {
		cout << "Removing Node " << i << endl;
		rmNode = testFillInit->dequeueNode();
		rmNode->printNode();
	}
	testFillInit->printPacket();
	cout << "Testing Complete" << endl;
    return 0;
}