/*
 * Mule.h
 *
 * Header file for mule nodes
 */

#ifndef MULE_H_
#define MULE_H_

class Packet;
class Node;

class Mule {
    friend class Packet;
	friend class Node;
private:
    static int *xVals;  /* A static field of all the possible x positions of the mules  */
    static int *yVals;  /* A static field of all the possible y positions of the mules  */
    static int count;   /* A counter for knowing how many mules are created thus knowing which values to give them on initialization    */
    int xPos;           /*  X position of the Mule  */
    int yPos;			/*  Y position of the Mule  */
	//Packet *pktHeadPtr;	/*  First packet in the queue of the Mule   */
	//Packet *pktTailPtr;	/*  Last packet in the queue of the Mule   */
    
    
public:
	Mule();
	virtual ~Mule();
    void init_positions();
    static void make_FieldVals(int, int);  /*  Function initializes the mules field info   */
};

#endif /* MULE_H_ */
