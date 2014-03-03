/**
 * Receiver.h
 *
 * Header file for receiving routers,
 */
#ifndef RECEIVER_H_
#define RECEIVER_H_
#include "Packet.h"
#include "Node.h"

class Packet;
class Node;
class Sender;

#include "Shared.h"

#ifndef DEBUG
#define DEBUG 0
#endif

class Receiver {
    
    
	friend class Packet;
	friend class Node;
private:
    // Static Figures
    static int total_receivers;  /*  Total number of senders            */
    static int field_length;     /*  Total height of the field          */
    static int *yVals;           /* A static field of all the possible y positions of the mules  */
    static int *xVals;           /* A static field of all the possible y positions of the mules  */

    // Statics done
    double *avgDpS;              /*Pointer to an array of floats that represent the average delay time per sender    */
    double totalAvgDelay;        /*  Total average delay time of all the packets from any sender */
    long numPackets;             /*  Total number of packets sent to this receiver   */
    long *numPacketsPS;           /*  Pointer to an array of int's that represent the number of packets per Sender    */
    int *senderNumber;          /*  List of all the numbers for each of the senders, used as a reference for storage of the average delay and the sender number */
	int xPos;                   /*  The X position of this receiver     */
	int yPos;                   /*  The Y position of this receiver     */
	int SR_ID;                  /*  The id of this receiver             */
    int rec_num;                /*  The number receiver that this is    */
    int tot_numSenders;               /*  Number of senders to this Receiver  */
    int numSenders;              /*  Number of senders at a given time   */
    
public:
	Receiver();					/*  Constructor: Should never use this one -- It doesnt allow us to reset the number of senders easily making calculations dificult */
    Receiver(int, int);         /*  Constructor: Preferable Constructor */
    /** Setter functions */
	void setX();
	void setY();
	void setID(int);
    //void setSenderNum(int);   /*  Could not get this working          */

	/** Getter functions */
	int getX();
	int getY();
	int getID();
    int getNumSenders();         /*  This works though                   */
    int getTotNumSenders();
    double getTAD();             /*  Get the total average delay of all the points in this receiver  */
    long getTNP();               /*  Get the total number of points in this receiver */
	
	/** Miscellaneous Operations */
    void print_Receiver();
    void print_R_Data();
    
    /** Packet Processing   **/
    void pPacketDelay(Packet *toProcess, int time);
    
    
    /*  Static Members  */
    // Variables
    static int num_receivers;   /*  Static list of the number of receivers */
    
    // Functions
    static void make_FieldVals(int, int);   /*  Sets the location of all the Receivers   */
    static void print_FieldVals();          /*  Prints the location of all the Receivers */
};

#endif
