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
    int tempX = -11;
    int tempY = -11;
    int tempC;
    if (count > (field_length-1) || count > (total_mules-1)){
        count = 0;
    }
    if (xVals[count] == -1){
        count++;
        this->init_positions();
    }else{
        /*  Sets them to the x or y value in the list of shuffled list  */
        if (count%2 == 1){
            tempX = xVals[count];
            tempY = yVals[rand() % (field_length)];
        }
        else{
            tempY = yVals[count];
            tempX = xVals[rand() % (field_length)];
            while (tempX == -1){
                tempX = xVals[rand() % (field_length)];
            }
        }
        
        tempC = count;
        while(!not_used(tempX, tempY)){
            count++;
            if (xVals[count] == -1){
                count++;
            }
            if (count%2 == 1){
                tempX = xVals[count];
                tempY = yVals[rand() % (field_length)];
                
            }
            else{
                tempY = yVals[count];
                tempX = xVals[rand() % (field_length)];
                while (tempX == -1){
                    tempX = xVals[rand() % (field_length)];
                }
            }
            
        }
        count = tempC;
        
        this->xPos = tempX;
        this->yPos = tempY;
    }
}
int Mule::not_used(int xpt, int ypt){
    int tmp = -1;
    for (int i = 0; i < total_mules; i++){
        if (l_op[i].xPoint < 0){            /*  Tells us when we've hit the end of used parts of the list   */
            tmp = i;
        }
        if (xpt == l_op[i].xPoint || ypt == l_op[i].yPoint){    /*Checks if the point has been used yet, if so return 0 */
            return 0;
        }
        else if(tmp == i){   /*  if you've hit the end of the list AND its' not been used, then return 1 and put it in the list  */
            l_op[i].xPoint = xpt;
            l_op[i].yPoint = ypt;
            return 1;
        }
        else{
            continue;
        }
    }
    return 0;  // It should never get here.
}

void Mule::print_Mule(){
    cout<< "Mule: Xpos: " << xPos << " Ypos: " << yPos << endl;
}









/*  Initialize the Static variables */
struct point *Mule::l_op = new struct point[1];
int *Mule::xVals = new int[1];
int *Mule::yVals = new int[1];
int Mule::total_mules = 0;
int Mule::count = 0;
int Mule::field_length = 0;
/*  Static Methods  */
void Mule::make_FieldVals(int total, int size_field){
    free(xVals);
    free(yVals);
    free(l_op);
    l_op = new struct point[total];
    xVals = new int[size_field];
    yVals = new int[size_field];
    total_mules = total;
    field_length = size_field;
    
    //Initalize the struct to all -2
    for (int i = 0; i < total; i++){
        l_op[i].xPoint = -2;
        l_op[i].yPoint = -2;
    }
    
    srand(time(NULL));
    /*  Fills the 'field' with a value for every x or y possible*/
    for (int i = 0; i < size_field; i++){
        if (i == 0 || (i == (size_field-1))){
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

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
