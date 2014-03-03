/* 
* @Author: Alec Thompson
* @Date:   2014-02-25 10:16:11
* @Last Modified by:   ajthompson
* @Last Modified time: 2014-03-03 16:39:25
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "Field.h"
using std::cout;
using std::endl;
using std::vector;
using std::exit;
using namespace std;

/**
 * @Author: Alec Thompson
 * 
 * Field constructor
 * 
 * @param dim  Dimension of the field read into the program
 * @param dMax Maximum router ID
 */
Field::Field(int dim, int dMax) {
	// set the max amount of digits for a source id
	this->setMaxDigits(dMax);

	this->setWidth(dim);
	this->setHeight(dim);

	// sets the field to dimensions of DIMENSION +2, DIMENSION
	this->field.resize(dim + 2);
	for (int i = 0; i < dim + 2; ++i) {
		this->field[i].resize(dim);
	}
}

////////////////////////
/// SETTER FUNCTIONS ///
////////////////////////

/**
 * @Author: Alec Thompson
 * 
 * Sets the maximum number of digits a router ID has to control printing
 * of the field.
 * 
 * @param dMax Maximum router ID
 */
void Field::setMaxDigits(int dMax) {
	if (dMax >= 10000) {
		maxDigits = 5;
	} else if (dMax >= 1000) {
		maxDigits = 4;
	} else if (dMax >= 100) {
		maxDigits = 3;
	} else if (dMax >= 10) {
		maxDigits = 2;
	} else {
		maxDigits = 1;
	}
}

/**
 * @Author: Alec Thompson
 * 
 * Sets the width of the field given the dimension input into the program.
 * This adds 2 to account for the sender and receiver columns
 * 
 * @param dimension Dimension of the field entered as a program argument
 */
void Field::setWidth(int dimension) {
	width = dimension + 2;
}

/**
 * @Author: Alec Thompson
 * 
 * Sets the height of the field given the dimension
 * 
 * @param dimension Dimension argument of the program
 */
void Field::setHeight(int dimension) {
	height = dimension;
}

/**
 * @Author: Alec Thompson
 * 
 * Sets the position specified to the given value.  If no value is
 * given, sets the position to 0.
 * 
 * @param x		 X position
 * @param y		 Y position
 * @param newVal New value to insert
 */
void Field::setPos(int x, int y, int newVal) {
	if (DEBUG) {
		cout << "adding value " << newVal << " at position";
		cout << " (" << x << "," << y << ")" << endl;
	}
	field[x][y] = newVal;
	if (DEBUG) {
		cout << "added value " << newVal << " at position";
		cout << " (" << x << "," << y << ")" << endl;
	}
}

/**
 * @Author: Alec Thompson
 *
 * Updates the size of the 2D vector to be consistent with the height
 * and width settings.
 *
 * WARNING: WHEN DECREASING SIZE, HIGHER INDICES WILL BE TRUNCATED
 */
void Field::updateSize() {
	this->field.resize(getWidth());
	for (int i = 0; i < getWidth(); ++i) {
		this->field[i].resize(getHeight());
	}
}

////////////////////////
/// GETTER FUNCTIONS ///
////////////////////////

// @author Alec Thompson
// I don't feel like breaking my inline comments to sign them, so you get this instead

/** Gets the maximum router id digits */
int Field::getMaxDigits() {
	return maxDigits;
}

/** Gets the width of the field */
int Field::getWidth() {
	return width;
}

/** Gets the height of the field */
int Field::getHeight() {
	return height;
}

/** Gets the value at the given point */
int Field::getVal(int x, int y) {
	return field[x][y];
}

/**
 * @Author: Alec Thompson
 *
 * Returns the position of the given value by reference.
 * Exits the program if a val of less than 1 is used, as
 * 0 is the empty space specifier, and negative values
 * are not supported
 * 
 * @param val Value to be found
 * @param x   x position of val
 * @param y   y position of val
 */
void Field::getPos(int val, int &x, int &y) {
	if (val < 1) {
		cout << "Value is less than 1. This could be an invalid input ";
		cout << "or any unused point." << endl;
	} else {
		for (int j = 0; j < getHeight(); ++j) {
			for (int i = 0; i < getWidth(); ++i) {
				if (field[i][j] == val) {
					x = i;
					y = j;
					goto finish;
				}
			}
		}
	}

	cout << "Value is not found in array." << endl;
	cout << "Setting X and Y to 0" << endl;
	x = 0;
	y = 0;

	finish:;
}

//////////////////////
/// PRINT FUNCTION ///
//////////////////////

/**
 * @Author: Alec Thompson
 *
 * Prints the field
 */
void Field::printField() {
	/** Print out the top border of the field */
	cout << endl << "/";
	for (int w = 0; w < getWidth(); ++w) {
		for (int m = 0; m < getMaxDigits(); ++m) {
			cout << "-";
		}
	}
	cout << "\\" << endl;

	/** Print out the main body of the field */
	for (int h = 0; h < getHeight(); ++h) {
		cout << "|";
		for (int w = 0; w < getWidth(); ++w) {
			if (getVal(w, h) == 0) {
				for (int m = 0; m < getMaxDigits(); ++m) {
					cout << ".";
				}
			} else {
					cout << setfill('0') << setw(getMaxDigits());
					cout << getVal(w, h);
			}
			cout << setw(1);
		}
		cout << "|" << endl;
	}

	/** Print out the bottom border of the field */
	cout << "\\";
	for (int w = 0; w < getWidth(); ++w) {
		for (int m = 0; m < getMaxDigits(); ++m) {
			cout << "-";
		}
	}
	cout << "/" << endl << endl;
}
