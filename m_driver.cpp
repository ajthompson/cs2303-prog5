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
    cout << "Lets see the field" << endl;
    Mule::print_FieldVals();
    Mule::fill_listOP();
    
    Mule::print_MuleLoc();
    cout << "time to make the mules" << endl;
    
    Mule mule1(10);
    Mule mule2(20);
    Mule mule3(30);
    Mule mule4(40);
    Mule mule5(50);
    Mule mule6(60);
    Mule mule7(70);
    Mule mule8(80);
    Mule mule9(90);
    Mule mule10(100);

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
    cout << "Now it's time to check what's next to each mule" << endl;
    cout << mule1.check_NSpace() << endl;
    cout << mule2.check_NSpace() << endl;
    cout << mule3.check_NSpace() << endl;
    cout << mule4.check_NSpace() << endl;
    for (int i = 0; i < 10; i++){
        mule1.moveMule();
        mule2.moveMule();
        mule3.moveMule();
        mule4.moveMule();
        mule5.moveMule();
        mule6.moveMule();
        mule7.moveMule();
        mule8.moveMule();
        mule9.moveMule();
        mule10.moveMule();
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
        cout << "next" << endl;
    }
    
    
}