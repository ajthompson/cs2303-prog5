/**
 * Node.cpp
 */
#include "Node.h"

/** Constructor */
template<typename T>
Node<T>::Node(T data) {
	this->data = data;
	this->nextPtr = NULL;
}


void Node<T>::setData(T data) {
	this->data = data;
}

template<typename T>
T Node<T>::getData() {
	return this->data;
}

template<typename T>
void Node<T>::setNext(T& nextPtr) {
	this->nextPtr = nextPtr;
}