/**
 * Field.h
 *
 * Container class for the field that will be printed out.
 *
 * When a particular point is 0, it is empty, otherwise it is the position
 * of a router.
 */
#ifndef DEBUG
 #define DEBUG 0
#endif

#ifndef FIELD_H_
#define FIELD_H_

#include <vector>

class Field {
private:
	std::vector<std::vector<int> > field;
	int maxDigits;
	int width;
	int height;
public:
	/** Constructor */
	Field(int, int);
	/** Setters */
	void setMaxDigits(int);
	void setWidth(int);
	void setHeight(int);
	void setPos(int x, int y, int Val=0);
	void updateSize();
	/** Getters */
	std::vector<std::vector<int> > getField();
	int getMaxDigits();
	int getWidth();
	int getHeight();
	int getVal(int, int);
	void getPos(int, int &, int &);
	/** Printing */
	void printField();
};

#endif