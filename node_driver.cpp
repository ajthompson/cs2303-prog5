#include <iostream>
#include "Node.h"
using namespace std;

int numbers[] = {19, 17, 14, 51, 52, 19, 18};
Node testNodes[7];

int main() {
	for (int i = 0; i < 7; ++i) {
		testNodes[i].setData(numbers[i]);
	}
	for (int i = 0; i < 7; ++i) {
		testNodes[i].printNode();
	}
}