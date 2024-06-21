#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Body.h"
using namespace std;
using namespace System;

class Student :public Body {
private:
	// Atributes
	queue<int> scores;

public:
	// Default Constructor
	Student() :Body() {}

	// Parameterized Constructor
	Student(const string& _name, const string& _lastName, const string& _code, const queue<string>& _courses, const queue<int>& _scores) :
		Body(_name, _lastName, _code, _courses), scores(_scores) {}

	// Destructor
	virtual ~Student() {}

	// Setters
	void setScores_(queue<int>& _scores) { scores = _scores; }

	// Getters
	queue<int> getScores_() const { return scores; }

	// Methods
	void AddScore_(const int& _score) {
		scores.push(_score);
	}

	void PrintScores_() const {
		queue<string> tempCourses = getCourses_();
		queue<int> tempScores = scores;

		if (tempCourses.front() == "NULL")
			cout << "No esta inscrito en ningun curso" << endl;
		else {
			cout << "Sus notas son: " << endl;

			int index{ 1 };
			while (!(tempCourses.empty() && tempScores.empty())) {
				if (tempScores.front() == -1)
					cout << " (" << index++ << ") " << tempCourses.front() << ": NOTA NO REGISTRADA" << endl;
				else
					cout << " (" << index++ << ") " << tempCourses.front() << ": " << tempScores.front() << endl;

				tempCourses.pop();
				tempScores.pop();
			}
		}

		cout << endl;
	}

};

#endif