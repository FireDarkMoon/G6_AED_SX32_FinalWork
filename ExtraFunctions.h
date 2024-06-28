#pragma once
#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H

#include "List.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;
using namespace System;

List<Student*>* LoadStudentsDataBaseToList_();
List<Teacher*>* LoadTeachersDataBaseToList_();
void AddCoursesFile_(string, string, string);
bool ValidateCourse_(const string&);
queue<string> EnterCoursesScores_(char);
void ShowSchedule_(queue<string>);

void AddScoresFile_(string, int, int,int);

#endif