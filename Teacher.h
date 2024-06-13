#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include "Body.h"
using namespace std;
using namespace System;

class Teacher :public Body {
private:
	// Atributes

public:
	// Default Constructor
	Teacher() :Body() {}

	// Parameterized Constructor
	Teacher(const string& _name, const string& _lastName, const string& _code, const queue<string>& _courses) :
		Body(_name, _lastName, _code, _courses) {}

	// Destructor
	virtual ~Teacher(){}

	// Methods

};

#endif