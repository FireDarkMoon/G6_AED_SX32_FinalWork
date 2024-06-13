#pragma once
#ifndef NODE_H
#define NODE_H

using namespace std;
using namespace System;

template <class T>
class Node {
private:
	// Atributes
	T element;
	Node* next;

public:
	// Default Constructor
	Node() :element(T()), next(nullptr) {}

	// Parameterized Constructor
	Node(const T& _element) : element(_element), next(nullptr) {}

	// Setters
	void setElement_(const T& _element) { element = _element; }
	void setNext_(Node* _next) { next = _next; }

	//Getters
	T getElement_() const { return element; }
	Node* getNext_() const { return next; }

	// Methods
	bool Empty_() const {
		return next == nullptr;
	}
};

#endif