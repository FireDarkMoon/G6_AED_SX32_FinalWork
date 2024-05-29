#pragma once
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
using namespace System;

class Student {
private:
	string name;
	string lastName;
	string code;
	queue<string> courses;
	queue<int> scores;

public:
	Student(string _name, string _lastName, string _code, queue<string> _courses, queue<int> _scores) :
		name(_name), lastName(_lastName), code(_code), courses(_courses), scores(_scores) {}

	void AddCourse_(const string& _course) {
		courses.push(_course);
	}

	void AddScore_(const int& _score) {
		scores.push(_score);
	}

	void printCourses() const {
		queue<string> tempCourses = courses;
		while (!tempCourses.empty()) {
			cout << tempCourses.front() << " ";
			tempCourses.pop();
		}
		cout << endl;
	}

	// Métodos para acceder y modificar los datos del estudiante
	string getName() const { return name; }
	string getLastName() const { return lastName; }
	string getCode() const { return code; }
	queue<string> getCourses() const { return courses; }
	queue<int> getScores() const { return scores; }
};

#endif