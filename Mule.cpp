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


Mule::Mule() {
	this->init_positions();

}

Mule::~Mule() {
	
}


void Mule::init_positions(){
    if (this->xVals[count] == -1){
        count++;
        this->init_positions();
    }else{
        /*  Sets them to the x or y value in the list of shuffled list  */
        this->xPos = xVals[count];
        this->yPos = yVals[count];
        count++;
    }
}


void Mule::make_FieldVals(int total, int size_field){
    xVals = new int[size_field];
    yVals = new int[size_field];
    count = 0;
    srand(time(NULL));
    /*  Fills the 'field' with a value for every x or y possible*/
    for (int i = 0; i < size_field; i++){
        if (i == 0 || i == size_field){
            xVals[i] = -1;      // Doesnt allow 0 or size_field because cannot put mules there
            yVals[i] = i;
        }
        else{
            xVals[i] = i;
            yVals[i] = i;
        }
    }
    /*  Below function is a Fisher-Yates shuffel. Found it on the internet  */
    for (int i = size_field - 1; i > 0; --i)
    {
        std::swap(xVals[i], xVals[rand() % (i + 1)]);
        std::swap(yVals[i], xVals[rand() % (i + 1)]);
    }
    /*  This algorythm is not mine, it is somebody elses    */
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}