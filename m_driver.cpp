/* Driver for the mule function
 *
 *
 *
 *
 */


#include <iostream>
#include <cstdlib>
#include "Mule.h"
#include "Packet.h"
#include "Node.h"
using std::cout;
using std::endl;

int main(void){
    cout << "Time to initialize the mules field" << endl;
    Mule::make_FieldVals(10, 10);
    cout << "initalizationg complete" << endl;
    cout << "time to make the mules" << endl;
    Mule mule1;
    Mule mule2;
    Mule mule3;
    Mule mule4;
    Mule mule5;
    Mule mule6;
    Mule mule7;
    Mule mule8;
    Mule mule9;
    Mule mule10;
    cout << "the mules have been made, now see the field" << endl;
    Mule::print_FieldVals();
    cout << "Now let's see the mules points" << endl;
    mule1.print_Mule();
    mule2.print_Mule();
    mule3.print_Mule();
    mule4.print_Mule();
    mule5.print_Mule();
    mule6.print_Mule();
    mule7.print_Mule();
    mule8.print_Mule();
    mule9.print_Mule();
    mule10.print_Mule();
    
}