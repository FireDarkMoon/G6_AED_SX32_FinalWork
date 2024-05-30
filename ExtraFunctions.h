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
void Trim_(string&);
vector<string> Split_(const string&, char);
void LoadDataBaseToList_(const string&, StudentList&);
 void SaveStudentFile_(const Student&);

#endif