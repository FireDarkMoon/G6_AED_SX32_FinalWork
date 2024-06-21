#pragma once
#ifndef LIST_H
#define LIST_H

#include "Node.h"
using namespace std;
using namespace System;

typedef unsigned int uint;
template <class T>
class List {
private:
	// Atributes
	uint length;
	Node<T>* node;
	Node<T>* initial;
	typedef function<int(T, T)> comp;

public:
	// Default Constructor
	List() : length(0), node(nullptr), initial(nullptr) {}

	// Parameterized Constructor
	List(Node<T>* _node) :length(0), node(_node), initial(_node) {}

	// Destructor
	~List() {
		/*
		 *Node<T>* auxNode = initial;
		while (auxNode != nullptr) {
			Node<T>* nextNode = auxNode->getNext_();
			delete auxNode;
			auxNode = nextNode;
		}
		*/
	}

	// Setters
	void setLength_(uint _length) { length = _length; }
	void setNode_(Node<T>* _node) { node = _node; }
	void setInitial_(Node<T>* _initial) { initial = _initial; }

	// Getters
	uint getLength_() const { return length; }
	Node<T>* getNode_() const { return node; }
	Node<T>* getInitial_() const { return initial; }

	// Other Methods
	bool Empty_() const {
		return length == 0;
	}

	// Search Methods
	/*
	T Search_(const T& _element, comp _compare) const {
		Node<T>* auxNode = initial;

		while (auxNode != nullptr) {
			if (_compare(auxNode->getElement_(), _element) == 0) {
				return auxNode->getElement_();
			}

			auxNode = auxNode->getNext_();
		}

		return 0;
	}
	*/

	T Search_(const string& _code) const {
		Node<T>* auxNode = initial;

		while (auxNode != nullptr) {
			if (auxNode->getElement_()->getCode_() == _code) {
				return auxNode->getElement_();
			}

			auxNode = auxNode->getNext_();
		}

		return nullptr; // Retornar nullptr si no se encuentra el elemento
	}

	List<T>* SearchCourses_(const string& _course) const {
		List<T>* resultList = new List<T>();
		Node<T>* auxNode = initial;

		while (auxNode != nullptr) {
			queue<string> temp = auxNode->getElement_()->getCourses_();
			while (!temp.empty()) {
				if (temp.front() == _course) {
					resultList->AddFinal_(auxNode->getElement_());
					break; // No necesitamos seguir revisando cursos de este estudiante
				}
				temp.pop();
			}
			auxNode = auxNode->getNext_();
		}

		return resultList;
	}

	T SearchInitial_() const {
		return SearchPosition_(0);
	}

	T SearchPosition_(uint _position) const {
		if (0 <= _position && _position < length) {
			Node<T>* auxNode = initial;
			for (int i = 0; i < _position; i++)
				auxNode = auxNode->getNext_();

			return auxNode->getElement_();
		}
		else return T();
	}

	T SearchFinal_() const {
		return SearchPosition_(length - 1);
	}

	// Add Methods
	void Add_(const T& _element) {
		Node<T>* newNode = new Node<T>(_element);
		newNode->setNext_(node);
		node = newNode;
	}

	void AddInitial_(const T& _element) {
		Node<T>* newNode = new Node<T>(_element);

		if (newNode != nullptr) {
			initial = newNode;
			length++;
		}
	}

	void AddPosition_(const T& _element, uint _position) {
		if (_position > length) return;
		if (_position == 0) AddInitial_(_element);
		else {
			Node<T>* auxNode = initial;
			for (int i{ 1 }; i < _position; i++)
				auxNode = auxNode->getNext_();

			Node<T>* newNode = new Node<T>(_element);
			newNode->setNext_(auxNode->getNext_());

			if (newNode != nullptr) {
				auxNode->setNext_(newNode);
				length++;
			}
		}
	}

	void AddFinal_(T _element) {
		AddPosition_(_element, length);
	}

	// Modify Methods
	void ModifyInitial_(const T& _element) {
		if (length > 0)
			initial->element = _element;
	}

	void ModifyPosition_(T _element, uint _position) {
		if (0 <= _position && _position < length) {
			Node<T>* auxNode = initial;
			for (int i = 0; i < _position; i++)
				auxNode = auxNode->next;

			auxNode->element = _element;
		}
	}

	void ModifyFinal_(const T& _element) {
		ModifyPosition_(_element, length - 1);
	}

	// Delete Methods
	void DeleteInitial_() {
		if (length > 0) {
			Node<T>* auxNode = initial;
			initial = initial->next;
			delete auxNode;
			length--;
		}
	}

	void DeletePosition_(uint _position) {
		if (_position < length) {
			if (_position == 0) DeleteInitial_();
			else {
				Node<T>* auxNode = initial;
				for (uint i = 0; i < _position - 1; i++)
					auxNode = auxNode->getNext_();

				Node<T>* nodeToDelete = auxNode->getNext_();
				auxNode->setNext_(nodeToDelete->getNext_());

				delete nodeToDelete;
				length--;
			}
		}
	}

	void DeleteFinal_() {
		if (length > 0) {
			if (length == 1) DeleteInitial_();
			else {
				Node<T>* auxNode = initial;
				while (auxNode->getNext_()->getNext_() != nullptr) {
					auxNode = auxNode->getNext_();
				}

				delete auxNode->getNext_();
				auxNode->setNext_(nullptr);
				length--;
			}
		}
	}
};

#endif