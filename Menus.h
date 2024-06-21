#pragma once
#ifndef MENUS_H
#define  MENUS_H

using namespace  std;
using namespace  System;

int  ShowMainMenu_();
int  ShowSubMenuStudent_();
int  ShowSubMenuTeacher_();
string ShowSubMenuStudentsByCourse_(Teacher*);
void CallSubMenuStudent_(Student*);
void CallSubMenuTeacher_(Teacher*);
void CallSubMenuStudentsByCourse_(string);


#endif
