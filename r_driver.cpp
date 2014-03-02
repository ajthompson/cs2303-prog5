/*
 * @Author: ajthompson
 * @Date:   2014-02-25 17:13:17
 * @Last Modified by:   ajthompson
 * @Last Modified time: 2014-02-26 10:17:02
 *
 * Tests for Senders
 */

#include <iostream>
#include "Receiver.h"
#include "Packet.h"
#include "Node.h"
using namespace std;

class Sender;
class Packet;
class Node;


int main(){
    /*  Receiver Things */
    Receiver::make_FieldVals(14, 14);
    Receiver::print_FieldVals();
    cout << "Initialize the receivers" << endl;
    Receiver listOfR[9];
    Receiver testD1(10, 3);
    Receiver testD2(15, 30);
    Receiver testD3(2, 10);
    /* Packet Data  */
    int numbers[]  = {19, 17, 14, 51, 52, 19, 18};
	Node nodeArr[7];
	int s_id = 1;
	int timestamp = 10;
	int pkt_size = 3;
	int t = 100;
    
    Packet *testFillNum = new Packet();
    Packet *test1 = new Packet();
    Packet *test2 = new Packet();
    Packet *test3 = new Packet();
    Packet *test4 = new Packet();
	Packet *testFillInit;
	Node *rmNode;
    /*  end data    */
    
    cout << "-------------------------------------------------------------------------" << endl;

    cout << "Testing the location of the Receivers and their instantiation" << endl;
    cout << "Print the receivers after they were instantiated" << endl;
    for(int i = 0; i < 9; i++){
        listOfR[i].print_Receiver();
    }
    cout << "-------------------------------------------------------------------------" << endl;
    for(int i = 0; i < 9; i++){
        listOfR[i].setID(i);
    }
    cout << "Print the current receivers" << endl;
    for(int i = 0; i < 9; i++){
        listOfR[i].print_Receiver();
    }
    
    cout << "-------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 7; i++) {
		nodeArr[i].setData(numbers[i]);
	}
    
	cout << "Now Testing the packet calculations" << endl;
	testFillNum->setID(s_id);
	testFillNum->setTimestamp(timestamp);
	testFillNum->setSize(pkt_size);
	testFillNum->setDelay(t);
    
    test1->setID(2);
	test1->setTimestamp(20);
	test1->setSize(2);
	test1->setDelay(200);
    
    test2->setID(3);
	test2->setTimestamp(300);
	test2->setSize(3);
	test2->setDelay(10);
    
    test3->setID(3);
	test3->setTimestamp(300);
	test3->setSize(3);
	test3->setDelay(10);
    
    test4->setID(3);
	test4->setTimestamp(300);
	test4->setSize(3);
	test4->setDelay(10);
	cout << "See Packet to add" << endl;
	testFillNum->printPacket();
    
    
    cout << "Time to run the calculation" << endl;
    
    testD1.pPacketDelay(testFillNum, 300);
    testD1.print_R_Data();
    
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Add some other stuff to it" << endl;
    testD1.pPacketDelay(test1, 301);
    cout << "adding more!" << endl;
    testD1.pPacketDelay(test2, 301);
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Printing after 3 packets have been added"  << endl;
    testD1.print_R_Data();
    cout << " Going to add multiple from same sender" << endl;
    testD1.pPacketDelay(test3, 401);
    testD1.pPacketDelay(test4, 501);
    testD1.print_R_Data();
    
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "TESTING COMPLETE" << endl;
    
    return 0;
}