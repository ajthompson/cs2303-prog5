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
    Receiver::make_FieldVals(14, 14);
    Receiver::print_FieldVals();
    cout << "Initialize the receivers" << endl;
    Receiver listOfR[9];
    Receiver testD1(10, 3);
    Receiver testD2(15, 30);
    Receiver testD3(2, 10);
    cout << "-------------------------------------------------------------------------" << endl;


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
    cout << "TESTING COMPLETE" << endl;
    
    return 0;
}