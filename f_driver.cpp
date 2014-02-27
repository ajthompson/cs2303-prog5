/* 
* @Author: alecthompson
* @Date:   2014-02-26 16:19:40
* @Last Modified by:   alecthompson
* @Last Modified time: 2014-02-26 17:14:25
*/

#include <iostream>
#include <cstdlib>
#include "Field.h"
using std::cout;
using std::endl;
using namespace std;

int main(){
	cout << "CREATING FIELD" << endl;
    // create a field
    Field* fPtr = new Field(30, 9);
    int x=0, y=0;

    cout << "PRINTING FIELD" << endl;
    // print out the empty field
    fPtr->printField();

    cout << "ADDING VALUES TO FIELD" << endl;
    // input values from 1 to 9
    for (int i = 1; i < 10; ++i) {
    	fPtr->setPos(rand() % 33, rand() % 31, i);
    	fPtr->printField();
    }
    // find a value of 9 and remove it
    cout << "FINDING POSITION OF 9" << endl;
    fPtr->getPos(9, x, y);
    cout << "9 IS AT (" << x << "," << y << ")" << endl;
    cout << "REMOVING VALUE 9" << endl;
    fPtr->setPos(x, y);
    cout << "9 REMOVED" << endl;
    fPtr->printField();

    // convert to 2 digit values
    cout << "CONVERTING TO 2 DIGIT VALUES" << endl;
    fPtr->setMaxDigits(55);
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();
    cout << "CLEARING FIELD" << endl;
    for (int i = 0; i < fPtr->getWidth(); ++i) {
    	for (int j = 0; j < fPtr->getHeight(); ++j) {
    		fPtr->setPos(i, j);
    	}
    }
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();
    cout << "FILLING FIELD WITH 2 DIGIT VALUES" << endl;
    for (int i = 1; i < 36; ++i) {
    	fPtr->setPos(rand() % (fPtr->getWidth()), rand() % (fPtr->getHeight()), i);
    }
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();

    // convert to 3 digit values
    cout << "CONVERTING TO 3 DIGIT VALUES" << endl;
    fPtr->setMaxDigits(543);
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();
    cout << "CLEARING FIELD" << endl;
    for (int i = 0; i < fPtr->getWidth(); ++i) {
    	for (int j = 0; j < fPtr->getHeight(); ++j) {
    		fPtr->setPos(i, j);
    	}
    }
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();
    cout << "FILLING FIELD WITH 3 DIGIT VALUES" << endl;
    for (int i = 91; i < 150; ++i) {
    	fPtr->setPos(rand() % (fPtr->getWidth()), rand() % (fPtr->getHeight()), i);
    }
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();

    // convert to 4 digit values
    cout << "CONVERTING TO 4 DIGIT VALUES" << endl;
    fPtr->setMaxDigits(5432);
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();
    cout << "CLEARING FIELD" << endl;
    for (int i = 0; i < fPtr->getWidth(); ++i) {
    	for (int j = 0; j < fPtr->getHeight(); ++j) {
    		fPtr->setPos(i, j);
    	}
    }
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();
    cout << "FILLING FIELD WITH 4 DIGIT VALUES" << endl;
    for (int i = 950; i < 1050; ++i) {
    	fPtr->setPos(rand() % (fPtr->getWidth()), rand() % (fPtr->getHeight()), i);
    }
    cout << "PRINTING FIELD" << endl;
    fPtr->printField();

    cout << "TESTING COMPLETE" << endl;

    return 0;
}