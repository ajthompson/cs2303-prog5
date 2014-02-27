/*
 * Mule.h
 *
 * Header file for mule nodes
 */

#ifndef MULE_H_
#define MULE_H_

class Packet;
class Node;

struct point{
    int xPoint;
    int yPoint;
};


class Mule {
    friend class Packet;
	friend class Node;
private:
    static struct point *l_op;/*To become a list of all the used points  */
    static int *xVals;  /* A static field of all the possible x positions of the mules  */
    static int *yVals;  /* A static field of all the possible y positions of the mules  */
    static int count;   /* A counter for knowing the current number of mules    */
    static int total_mules; /* A counter knowing the total number of mules  */
    static int field_length;/* Lets us know the length of the field */
    int xPos;           /*  X position of the Mule  */
    int yPos;			/*  Y position of the Mule  */
    int field_size;
	//Packet *pktHeadPtr;	/*  First packet in the queue of the Mule   */
	//Packet *pktTailPtr;	/*  Last packet in the queue of the Mule   */
    
    
public:
	Mule();
	virtual ~Mule();
    void init_positions();
    int not_used(int, int);
    void print_Mule();
    static void make_FieldVals(int, int);  /*  Function initializes the mules field info   */
    static void print_FieldVals();
};

#endif /* MULE_H_ */
