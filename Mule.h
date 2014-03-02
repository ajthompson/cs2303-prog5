/*
 * Mule.h
 *
 * Header file for mule nodes
 */

#ifndef MULE_H_
#define MULE_H_

#include "Packet.h"
#include "Node.h"

/*  Global information -- May be a problem because of multiple definition. Working to fix   */
struct point{
    int xPoint;
    int yPoint;
};
/*  Global stuff that only Mules have to worry about    */
enum direction {NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3};
enum NEXT {NOTHING = -1, WALL = -2, MULE = -3};


class Mule {
    friend class Packet;
	friend class Node;
private:
    
    static int *xVals;          /* A static field of all the possible x positions of the mules  */
    static int *yVals;          /* A static field of all the possible y positions of the mules  */
    static int total_mules;     /* A counter knowing the total number of mules                  */
    static int field_length;    /* Lets us know the length of the field                         */
    
    direction mule_dir;         /*  Direction of the Mule                                       */
    int SR_ID;                  /*  The id of the Mule                                          */
    int num_mule;               /*  This is the number mule that was made                       */
    int xPos;                   /*  X position of the Mule                                      */
    int yPos;                   /*  Y position of the Mule                                      */
	Packet *pktHeadPtr;         /*  First packet in the queue of the Mule                       */
	Packet *pktTailPtr;         /*  Last packet in the queue of the Mule                        */
    
    /*  Make sure to add one on the getter for the mule for x   */
    
public:
	Mule(int);
    direction retDirection();   /*  Returns the psuedo random value that is the direction       */
	virtual ~Mule();
    void init_positions();      /*  Initalizes the positions of the mules                       */
    void print_Mule();          /*  Prints a mule                                               */
    NEXT check_NSpace();        /*  Checks what is next to this mule                            */
    void moveMule();            /*  Switch statement for moving a mule                          */
    void mule_Inc();            /*  Program that increments the mule                            */
    void changeDir();           /*  Changes the direction of the mule                           */
    int m_getX();               /*  Get's the x value of the mule                               */
    int m_getY();               /*  Get's the y value of the mule                               */
    int m_getID();              /*  Get's the ID of a Mule                                      */
    int pLength();              /*  gets the length of the queue of the mule                    */
    void pPrint();              /*  Prints the queue of the mule                                */
    void pktEnqueue(Packet *);  /*  Queue's a packet                                            */
    Packet* pktDequeue();       /*  Dequeues a packet                                           */
    Packet *getHead();          /*  Gets the head of the a packet                               */
    Packet *getTail();          /*  Gets the tail of the queue                                  */
    
    
    
    
    
    /*  These Methods are used to initialize the shared mule values */
    // Variables
    static struct point *l_op;                  /*  To become a list of all the used points  */
    static int count;                           /*  A counter for knowing the current number of mules    */
    
    // Functions
    static int not_used(int, int);              /*  Checks if a point has been used yet */
    static void make_FieldVals(int, int);       /*  Function initializes the mules field info   */
    static void print_FieldVals();              /*  Prints the possible values after they've been shuffled  */
    static void fill_listOP();                  /*  Fills the list of possible points   */
    static void getPoint(int *, int *);         /*  Gets an independant point   */
    static void print_MuleLoc();                /*  Prints all possible locations of a mule */
};

#endif /* MULE_H_ */
