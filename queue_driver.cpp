/**
 * queue_driver.cpp
 *
 * Testing the Queue and Node classes.
 */
#include <iostream>
#include "Queue.h"
 using std::cout;
 using std::endl;
 using namespace std;

int main() {
	int i;		// counter to add test values to queues
	// test data
	int test_int[10] = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1};
	char test_char[10] = {33, 34, 35, 36, 37, 38, 39, 40, 41, 42};
						// !   "   #   $   %   &   '   (   )   *
	// test queues
	Queue<int> *intQueue = new Queue<int>();
	Queue<char> *charQueue = new Queue<char>();

	for (i = 0; i < 10; i++) {
		intQueue->enqueue(test_int[i]);
		charQueue->enqueue(test_char[i]);
		cout << "--------------------------" << endl;
		cout << "Printing intQueue" << endl;
		intQueue->printQueue();
		cout << "--------------------------" << endl;
		cout << "Printing charQueue" << endl;
		charQueue->printQueue();
		cout << "--------------------------" << endl;
	}

	cout << "Dequeue Tests" << endl;
	for (i = 0; i < 10; i++) {
		cout << "Dequeuing int Node " << i << endl;
		cout << intQueue->dequeue();
	}
	for (i = 0; i < 10; i++) {
		cout << "Dequeuing char Node " << i << endl;
		cout << charQueue->dequeue();
	}

	return 0;
}