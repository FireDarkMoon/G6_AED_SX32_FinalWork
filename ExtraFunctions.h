#pragma once
#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H

#include "StudentList.h"
using namespace std;
using namespace System;

int  ShowMainMenu_();
int  ShowSubMenuStudent_();
int  ShowSubMenuTeacher_();
bool ValidateDataBase_(const string&);
void trim(string&);
vector<string> split(const string&, char);
void loadStudentsFromFile(const string&, StudentList&);

#endif