/*
 * Mule.h
 *
 * Header file for mule nodes
 */

#ifndef MULE_H_
#define MULE_H_

#include "Packet.h"
#include "Node.h"

struct point{
    int xPoint;
    int yPoint;
};
enum direction {NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3};
enum NEXT {NOTHING = -1, WALL = -2, MULE = -3};


class Mule {
    friend class Packet;
	friend class Node;
private:
    
    static int *xVals;          /* A static field of all the possible x positions of the mules  */
    static int *yVals;          /* A static field of all the possible y positions of the mules  */
    static int total_mules;     /* A counter knowing the total number of mules  */
    static int field_length;    /* Lets us know the length of the field */
    
    direction mule_dir;         /*  Direction of the Mule   */
    int SR_ID;                  /*  The id of the Mule  */
    int num_mule;               /*  This is the number mule that was made   */
    int xPos;                   /*  X position of the Mule  */
    int yPos;                   /*  Y position of the Mule  */
	Packet *pktHeadPtr;         /*  First packet in the queue of the Mule   */
	Packet *pktTailPtr;         /*  Last packet in the queue of the Mule   */
    
    /*  Make sure to add one on the getter for the mule for x   */
    
public:
	Mule(int);
    direction retDirection();   /*  Returns the psuedo random value that is the direction   */
	virtual ~Mule();
    void init_positions();      /*  Initalizes the positions of the mules   */
    void print_Mule();          /*  Prints a mule */
    NEXT check_NSpace();
    void moveMule();
    void mule_Inc();
    void changeDir();
    int m_getX();
    int m_getY();
    int pLength();
    void pktEnqueue(Packet *);
    Packet* pktDequeue();
    Packet *getHead();
    Packet *getTail();
    
    
    
    
    
    /*  These Methods are used to initialize the shared mule values */
    
    static struct point *l_op;                  /*  To become a list of all the used points  */
    static int count;                           /*  A counter for knowing the current number of mules    */
    static int not_used(int, int);              /*  Checks if a point has been used yet */
    static void make_FieldVals(int, int);       /*  Function initializes the mules field info   */
    static void print_FieldVals();              /*  Prints the possible values after they've been shuffled  */
    static void fill_listOP();                  /*  Fills the list of possible points   */
    static void getPoint(int *, int *);         /*  Gets an independant point   */
    static void print_MuleLoc();                /*  Prints all possible locations of a mule */
};

#endif /* MULE_H_ */
