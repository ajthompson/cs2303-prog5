/**
 * Node.cpp
 */
#include <iostream>
#include "Node.h"
 using std::cout;
 using std::endl;
 using namespace std;

/** Constructor */
template<typename T>
Node<T>::Node(T data) {
	this->data = data;
	this->nextPtr = NULL;
}

/**
 * Stores an object of type T in the node.
 *
 * @param data Object that is stored in the node.
 */
template<typename T>
void Node<T>::setData(T data) {
	this->data = data;
}

/**
 * Returns the data of type T from the node.
 *
 * @return data of type T
 */
template<typename T>
T Node<T>::getData() {
	return this->data;
}

/**
 * Sets the pointer to the next node in the queue.
 */
template<typename T>
void Node<T>::setNext(T &nextPtr) {
	this->nextPtr = nextPtr;
}

/**
 * Prints out the node.
 */
template<typename T>
void Node<T>::printNode() {
	cout << data << endl;
}