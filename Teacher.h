#pragma once
#ifndef TEACHER_H
#define TEACHER_H

using namespace std;
using namespace System;

class Teacher {
private:
	string name;
	string lastName;
	string code;
	queue<string> courses;

public:
	Teacher(string _name, string _lastName, string _code, queue<string> _courses) :
		name(_name), lastName(_lastName), code(_code), courses(_courses) {}



};

#endif