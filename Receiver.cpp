/*
 * Receiver.cpp
 *
 *  Created on: Feb 26, 2014
 *      Author: troyhughes
 */
#include <iostream>
#include <cstdlib>
#include "Sender.h"
#include "Receiver.h"
#include "Packet.h"
#include "Node.h"

using std::cout;
using std::endl;
/*---------------------------------Constructors---------------------------------*/
/*---------------------------------Constructors---------------------------------*/
/*---------------------------------Constructors---------------------------------*/
/*---------------------------------Constructors---------------------------------*/
Receiver::Receiver(int ID_input, int num_senders) {
    rec_num = num_receivers;                          /* Sets what number receiver this is    */
    setID(ID_input);                                  /* Sets the input ID                    */
    setX();                                           /* Sets the X                           */
    setY();                                           /* Sets the Y                           */
    avgDpS = new float[num_senders];                  /* Initializes the Average D per Sendr  */
    numPacketsPS = new int[num_senders];              /* Initializes the Num Pkts per Sendr   */
    totalAvgDelay = 0;                                /* Initializes the tot avg delay        */
    numSndrs = num_senders;                           /* Stores the number of senders to this */
    num_receivers++;                                  /* Increments for next construction     */
}



Receiver::Receiver(){
    rec_num = num_receivers;
    setID(0);
    setX();
    setY();
    avgDpS = new float[1];
    numSndrs = 0;
    num_receivers++;

}

/*---------------------------------Getters---------------------------------*/
/*---------------------------------Getters---------------------------------*/
/*---------------------------------Getters---------------------------------*/
/*---------------------------------Getters---------------------------------*/
/*---------------------------------Getters---------------------------------*/
int Receiver::getX(){
   return xPos;
}
int Receiver::getY(){
    return yPos;
}
int Receiver::getID(){
    return SR_ID;
}
int Receiver::getNumSendrs(){
    return numSndrs;
    
}



/*--------------------------------Get_to_Screen(PRINT)---------------------*/
/*--------------------------------Get_to_Screen(PRINT)---------------------*/
/*--------------------------------Get_to_Screen(PRINT)---------------------*/
/*--------------------------------Get_to_Screen(PRINT)---------------------*/

void Receiver::print_Receiver(){
/*  This prints some the receiver's fields   */
    cout << "(" << getX() << "," << getY() << ")" << "ID: " << getID() << " Numm of Senders: " << getNumSendrs() << endl;

}


/*---------------------------------Setters---------------------------------*/
/*---------------------------------Setters---------------------------------*/
/*---------------------------------Setters---------------------------------*/
/*---------------------------------Setters---------------------------------*/
/*---------------------------------Setters---------------------------------*/

void Receiver::setX(){
/*  Gets an x value from the list of possible x values  */
    xPos = (xVals[rec_num]);
   
}
void Receiver::setY(){
/*  Gets an y value from the list of possible y values  */
   yPos = (yVals[rec_num]);
   
}

void Receiver::setID(int new_ID){
    SR_ID = new_ID;
}








/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/


/*  Initialize the Static variables */

int *Receiver::xVals = new int[1];
int *Receiver::yVals = new int[1];
int Receiver::total_receivers = 0;
int Receiver::num_receivers = 0;
int Receiver::field_length = 0;

/*  Static Methods  */
void Receiver::make_FieldVals(int total, int size_field){
/*  Clears the static variables - For lack of better way of knowing how to do it -- */
    delete(xVals);
    delete(yVals);
/*  Re initializes these to the inputted values */
    xVals = new int[size_field];
    yVals = new int[size_field];
    total_receivers = total;
    field_length = size_field;
    
/*  Seeds Random number generater   */
    srand(time(NULL));
    /*  Fills the 'field' with a value for every x or y possible*/
    for (int i = 0; i < field_length; i++){
        xVals[i] = field_length + 1;
        yVals[i] = i;
    }
/*  Below function is a Fisher-Yates shuffel. Found it on the internet  */
    /*  It's designed to randomally shuffle the numbers and keep 1 instance of each number  */
    for (int i = size_field - 1; i > 0; --i)
    {
        std::swap(yVals[i], yVals[rand() % (i + 1)]);
    }
    /*  This algorythm is not mine, it is somebody elses    */
}


void Receiver::print_FieldVals(){
/*  Print's out the possible values of the field    */
    cout << "These are the x values"    << endl;
    for (int i = 0; i < field_length; i++){
        cout << i << ": "<< xVals[i] << endl;
    }
    cout << "These are the y values"    << endl;
    for (int i = 0; i < field_length; i++){
        cout << i << ": "<< yVals[i] << endl;
    }
    
}

/*---------------------------------PacketManipulator---------------------------------*/
/*---------------------------------PacketManipulator---------------------------------*/
/*---------------------------------PacketManipulator---------------------------------*/
/*---------------------------------PacketManipulator---------------------------------*/
/*---------------------------------PacketManipulator---------------------------------*/

void Receiver::pPacketDelay(Packet *toProcess, int time){
/*  Calculates the delay of one packet  -   Does not return becuae of how much more neeeds to be done   */
    int timeStamp, delay;
    timeStamp = toProcess->getTimestamp();
    delay = time - timeStamp;
    
}













