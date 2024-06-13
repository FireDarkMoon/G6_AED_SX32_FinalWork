#pragma once
#ifndef BODY_H
#define BODY_H

using namespace std;
using namespace System;

class Body {
private:
	// Atributes
	string name;
	string lastName;
	string code;
	queue<string>courses;

public:
	// Default Constructor
	Body() :name(""), lastName(""), code("") {}

	// Parameterized Constructor
	Body(const string& _name, const string& _lastName, const string& _code, const queue<string>& _courses) :
		name(_name), lastName(_lastName), code(_code), courses(_courses) {}

	// Destructor
	virtual ~Body() {}

	// Setters
	void setName_(const string& _name) { name = _name; }
	void setLastName_(const string& _lastName) { lastName = _lastName; }
	void setCode_(const string& _code) { code = _code; }
	void setCourses_(const queue<string>& _courses) { courses = _courses; }

	// Getters
	string getName_() const { return name; }
	string getLastName_() const { return lastName; }
	string getCode_() const { return code; }
	queue<string> getCourses_() const { return courses; }

	// Methods
	void AddCourse_(const string& _course) {
		courses.push(_course);
	}

	void PrintCourses_() const {
		queue<string> tempCourses = courses;

		if (tempCourses.front() == "NULL")
			cout << "No esta inscrito en ningun curso" << endl;
		else {
			cout << "Sus cursos son: " << endl;

			int index{ 1 };
			while (!tempCourses.empty()) {
				cout << "(" << index++ << ") " << tempCourses.front() << endl;
				tempCourses.pop();
			}
		}

		cout << endl;
	}
};

#endif
