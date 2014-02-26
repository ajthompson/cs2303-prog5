/**
 * Field.h
 *
 * Container class for the field that will be printed out.
 */

#ifndef FIELD_H_
#define FIELD_H_

class Field {
private:
	int *field;
	int maxDigits;
public:
	Field(int, int);
	void setPos(int, int, int);
	void printField();
}