/*
 * Mule.cpp
 *
 *  Created on: Feb 26, 2014
 *      Author: troyhughes
 */
#include <iostream>
#include <cstdlib>
#include "Mule.h"
//#include "Packet.h"
#include "Node.h"
using std::cout;
using std::endl;

/*---------------------------------Constructors---------------------------------*/
/*---------------------------------Constructors---------------------------------*/
/*---------------------------------Constructors---------------------------------*/
/*---------------------------------Constructors---------------------------------*/
Mule::Mule(int ID_input) {
    SR_ID = ID_input;
	init_positions();
    mule_dir = retDirection();
    num_mule = count;
    pktHeadPtr = NULL;
    pktTailPtr = NULL;
    count++;

}
/*---------------------------------Destructors---------------------------------*/
/*---------------------------------Destructors---------------------------------*/
/*---------------------------------Destructors---------------------------------*/
/*---------------------------------Destructors---------------------------------*/
/*---------------------------------Destructors---------------------------------*/
Mule::~Mule() {
	
}
/*---------------------------------Getters---------------------------------*/
/*---------------------------------Getters---------------------------------*/
/*---------------------------------Getters---------------------------------*/
/*---------------------------------Getters---------------------------------*/
/*---------------------------------Getters---------------------------------*/
int Mule::m_getX(){
    return (xPos + 1);
    
}
int Mule::m_getY(){
    return (yPos);
}

Packet *Mule::getHead(){
    /*	Author: Troy Hughes
     * 		This function returns the head node
     */
	return pktHeadPtr;
}


Packet *Mule::getTail(){
    /*	Author: Troy Hughes
     * 		This function returns the tail node
     */
	return pktTailPtr;
}
/*---------------------------------init_Function---------------------------------*/
/*---------------------------------init_Function---------------------------------*/
/*---------------------------------init_Function---------------------------------*/
/*---------------------------------init_Function---------------------------------*/
/*---------------------------------init_Function---------------------------------*/
void Mule::init_positions(){
    int tempX, tempY;
    tempX = Mule::l_op[Mule::count].xPoint;
    tempY = Mule::l_op[Mule::count].yPoint;
    this->xPos = tempX;
    this->yPos = tempY;
}

direction Mule::retDirection(){
    int dir = count % 4;
    switch(dir){
        case 0:
            return NORTH;
        case 1:
            return SOUTH;
        case 2:
            return EAST;
        case 3:
            return WEST;
        default:
            cout << "THERE'S A PROBLEM IN THE RETURN DIRECTION FUNCTION" << endl;
            return NORTH;
    }
}

/*---------------------------------automatic Printers---------------------------------*/
/*---------------------------------automatic Printers---------------------------------*/
/*---------------------------------automatic Printers---------------------------------*/
/*---------------------------------automatic Printers---------------------------------*/
/*---------------------------------automatic Printers---------------------------------*/

void Mule::print_Mule(){
    cout<< "Mule: Xpos: " << xPos << " Ypos: " << yPos << endl;
}
/*---------------------------------Mover_Functions---------------------------------*/
/*---------------------------------Mover_Functions---------------------------------*/
/*---------------------------------Mover_Functions---------------------------------*/
/*---------------------------------Mover_Functions---------------------------------*/
/*---------------------------------Mover_Functions---------------------------------*/

NEXT Mule::check_NSpace(){
    int xPt = this->xPos;
    int yPt = this->yPos;
    direction mule_dir = this->mule_dir;
    switch (mule_dir) {
        case NORTH:
            if (yPt -1 < 0){
                return WALL;
            }else if (!not_used(xPt, yPt-1)){
                return MULE;
            }else
                return NOTHING;
            break;
        case SOUTH:
            if (yPt+1 > field_length){
                return WALL;
            }else if (!not_used(xPt, yPt+1)){
                return MULE;
            }else
                return NOTHING;
            break;
        case WEST:
            if (xPt -1 < 0){
                return WALL;
            }else if (!not_used(xPt-1, yPt)){
                return MULE;
            }else
                return NOTHING;
            break;
        case EAST:
            if (xPt+1 > field_length){
                return WALL;
            }else if (!not_used(xPt+1, yPt)){
                return MULE;
            }else
                return NOTHING;
            break;
        default:
            cout << "HUGE ASS ERROR IN check_NSpace() in Mule Class" << endl;
            break;
    }
    
}

void Mule::moveMule(){
    switch (check_NSpace()) {
        case WALL:
            this->changeDir();
            break;
        case MULE:
            this->mule_Inc();
            this->moveMule();
            break;
        case NOTHING:
            this->mule_Inc();
            break;
        default:
            cout << "ERROR in moveMule()" << endl;
            break;
    }
}
void Mule::mule_Inc(){
    direction dir = this->mule_dir;
    int xPt = this->xPos;
    int yPt = this->yPos;
    switch (dir) {
        case NORTH:
            this->xPos = xPt;
            this->yPos = (yPt - 1);
            l_op[this->num_mule].xPoint = this->xPos;
            l_op[this->num_mule].yPoint = this->yPos;
            break;
        case SOUTH:
            this->xPos = xPt;
            this->yPos = (yPt + 1);
            l_op[this->num_mule].xPoint = this->xPos;
            l_op[this->num_mule].yPoint = this->yPos;
            break;
        case WEST:
            this->xPos = (xPt - 1);
            this->yPos = yPt;
            l_op[this->num_mule].xPoint = this->xPos;
            l_op[this->num_mule].yPoint = this->yPos;
            break;
        case EAST:
            this->xPos = (xPt + 1);
            this->yPos = yPt;
            l_op[this->num_mule].xPoint = this->xPos;
            l_op[this->num_mule].yPoint = this->yPos;
            break;
        default:
            cout << "HUGE ASS ERROR IN changeDir() in Mule Class" << endl;
            break;
    }
}
void Mule::changeDir(){
    direction dir = this->mule_dir;
    switch (dir) {
        case NORTH:
            this->mule_dir = SOUTH;
            break;
        case SOUTH:
            this->mule_dir = NORTH;
            break;
        case WEST:
            this->mule_dir = EAST;
            break;
        case EAST:
            this->mule_dir = WEST;
            break;
        default:
            cout << "HUGE ASS ERROR IN changeDir() in Mule Class" << endl;
            break;
    }
    
}
/*---------------------------------Packet_Queue---------------------------------*/
/*---------------------------------Packet_Queue---------------------------------*/
/*---------------------------------Packet_Queue---------------------------------*/
/*---------------------------------Packet_Queue---------------------------------*/
/*---------------------------------Packet_Queue---------------------------------*/

void Mule::pktEnqueue(Packet *toQueue) {
    Packet *h_packet = getHead();
	Packet *t_packet = getTail();
	if (h_packet == NULL){
		this->pktHeadPtr = toQueue;
		this->pktTailPtr = NULL;
	}else if(t_packet == NULL){
		this->pktHeadPtr->nextPtr = toQueue;
		this->pktTailPtr = this->pktHeadPtr->nextPtr;
		this->pktTailPtr->nextPtr = NULL;
	}else{
		((this->pktTailPtr)->nextPtr) = toQueue;
		this->pktTailPtr = ((this->pktTailPtr)->nextPtr);
		((this->pktTailPtr)->nextPtr) = NULL;
	}
}

/**
 * Dequeues the first packet in the queue and returns.
 *
 * @return A pointer to the first packet in the queue.
 */
Packet *Mule::pktDequeue() {
	Packet *to_return = NULL;
	if(pLength() == 1){
		to_return = (getHead());
		this->pktHeadPtr = NULL;
		this->pktTailPtr = NULL;
		return to_return;
	}else if(pLength() == 2){
		to_return = (getHead());
		this->pktHeadPtr = this->pktTailPtr;
		this->pktTailPtr = NULL;
        to_return->nextPtr = NULL;
		return to_return;
	}else if (pLength() > 0){
		to_return = (getHead());
		this->pktHeadPtr = (this->pktHeadPtr)->nextPtr;
        to_return->nextPtr = NULL;
		return to_return;
	}else {
		cout << "Error in Remove node" << endl;
		cout << "Quitting the Program" << endl;
		exit(1);
	}
}

int Mule::pLength(){
    /*	Author: Troy Hughes
     * 		This function returns the length of the path
     */
	Packet *tmp = getHead();
	int qLength = 0;
	while (tmp != NULL){
		qLength++;
		tmp = tmp->nextPtr;
	}
	return qLength;
}


void Mule::pPrint(){
    /*	Author: Troy Hughes
     * 		This prints the whole path
     */
	Packet *tmp = getHead();
	for (int i = 0; i < pLength(); i++){
		cout << "Source ID: " << tmp->source_id <<  "Timestamp: " << tmp->timestamp << "Packet Size: " << tmp->pkt_size << "Delay: " << tmp->delay <<  "Nodes: " << endl;
		tmp = tmp->nextPtr;
	}
}




/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/
/*---------------------------------Static_Stuff---------------------------------*/


/*  Initialize the Static variables */
struct point *Mule::l_op = new struct point[1];
int *Mule::xVals = new int[1];
int *Mule::yVals = new int[1];
int Mule::total_mules = 0;
int Mule::count = 0;
int Mule::field_length = 0;

/*  Static Methods  */
void Mule::make_FieldVals(int total, int size_field){
    delete(xVals);
    delete(yVals);
    delete(l_op);
    l_op = new struct point[total]; //Create a list of points of length to be the total number of mules
    xVals = new int[size_field];
    yVals = new int[size_field];
    total_mules = total;
    field_length = size_field;

    
    srand(time(NULL));
    /*  Fills the 'field' with a value for every x or y possible*/
    for (int i = 0; i < size_field; i++){
        xVals[i] = i;
        yVals[i] = i;
    }
    /*  Below function is a Fisher-Yates shuffel. Found it on the internet  */
    for (int i = size_field - 1; i > 0; --i)
    {
        std::swap(xVals[i], xVals[rand() % (i + 1)]);
        std::swap(yVals[i], yVals[rand() % (i + 1)]);
    }
    /*  This algorythm is not mine, it is somebody elses    */
}


void Mule::print_FieldVals(){
    cout << "These are the x values"    << endl;
    for (int i = 0; i < field_length; i++){
        cout << i << ": "<< xVals[i] << endl;
    }
    cout << "These are the y values"    << endl;
    for (int i = 0; i < field_length; i++){
        cout << i << ": "<< yVals[i] << endl;
    }
    
}

void Mule::fill_listOP(){
    int tempX;
    int tempY;
    //Initalize the struct to all -2
    for (int i = 0; i < total_mules; i++){
        l_op[i].xPoint = -2;
        l_op[i].yPoint = -2;
    }
    getPoint(&tempX, &tempY);
    /*See if it's in the list   */
        /* If it is then get a new one  */
        /* If it's not then store it in the list at the next point  */
    for (int j = 0; j < total_mules; j++){
        while(!not_used(tempX, tempY)){
            getPoint(&tempX, &tempY);
        }
        for (int i = 0; i < total_mules; i++){
            if (l_op[i].xPoint == -2){
                l_op[i].xPoint = tempX;
                l_op[i].yPoint = tempY;
                break;
            }
        }
    }
}

void Mule::getPoint(int *point1, int *point2){
    if (field_length > total_mules){
        *point1 = xVals[rand() % (total_mules)];
        *point2 = yVals[rand() % (total_mules)];
    }else{
        *point1 = xVals[rand() % (field_length)];
        *point2 = yVals[rand() % (field_length)];
    }
    if (*point1 == -1 || *point2 == -1){
        getPoint(point1, point2);
    }
    
}

int Mule::not_used(int xpt, int ypt){
    int returnVal;
    for (int i = 0; i < total_mules; i++){
        if (xpt == l_op[i].xPoint && ypt == l_op[i].yPoint){    /*Checks if the point has been used yet, if so return 0 */
            returnVal = 0;
            break;
        }
        else{
            returnVal = 1;
        }
    }
    return returnVal;
}

void Mule::print_MuleLoc(){
    for (int i = 0; i < total_mules; i++){
        cout << "(" << l_op[i].xPoint << "," << l_op[i].yPoint << ")" << endl;
    }
}
    
    
    
    
    
    
    
    
    
    
    
