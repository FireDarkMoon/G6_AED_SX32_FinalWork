#include "Libraries.h"
#include "Defines.h"
#include "EnumsConstants.h"
#include "Functions.h"
#include "ExtraFunctions.h"
#include "List.h"
#include "Student.h"
#include "Teacher.h"
#include "Menus.h"
using namespace std;
using namespace System;

int main() {
	Settings_();

	List<Student*>* studentList = LoadStudentsDataBaseToList_();
	List<Teacher*>* teacherList = LoadTeachersDataBaseToList_();

	bool end{ false };
	int option{ ShowMainMenu_() };

	do {
		bool execute{ false };

		switch (option) {
		case 1: {
			ClearScreen_();

			string code;
			cout << "\nIngrese su codigo de estudiante: "; cin >> code;

			Student* foundStudent = studentList->Search_(code);

			if (foundStudent != nullptr)
				CallSubMenuStudent_(foundStudent);
			else {
				cout << "\nERROR ESTUDIANTE NO ENCONTRADO" << endl;
				WaitKey_();
			}

			execute = true;
		}
			  break;

		case 2: {
			ClearScreen_();

			string code;
			cout << "\nIngrese su codigo de maestro: "; cin >> code;

			Teacher* foundTeacher = teacherList->Search_(code);

			if (foundTeacher != nullptr)
				CallSubMenuTeacher_(foundTeacher);
			else {
				cout << "\nERROR MAESTRO NO ENCONTRADO" << endl;
				WaitKey_();
			}

			execute = true;
		}
			  break;

		case 3: {
			ClearScreen_();

			string name, lastName, code;
			cout << "\nIngrese el nombre del estudiante: "; cin >> name;
			cout << "Ingrese el apellido del estudiante: "; cin >> lastName;
			cout << "Ingrese el c�digo del estudiante: "; cin >> code;

			string courses{ "NULL" };
			int scores{ -2 };

			ofstream file("StudentsDataBase.txt", ios::app);
			file << name << "," << lastName << "," << code << ",\"" << courses << "\",\"" << scores << "\"" << endl;

			cout << "\nNuevo estudiante agregado correctamente." << endl;

			execute = true;
			WaitKey_();
		}
			  break;

		case 4: {
			ClearScreen_();

			string name, lastName, code, course;
			cout << "\nIngrese el nombre del maestro: "; cin >> name;
			cout << "Ingrese el apellido del maestro: "; cin >> lastName;
			cout << "Ingrese el codigo del maestro: "; cin >> code;
			cout << "Ingrese el curso del maestro: "; cin >> course;

			int j = 0;
			int default = 4;

			if (!ValidateCourse_(course)) {
				do {
					cout << endl;
					if (j == 0) {
						ShowStringColor_(30, default + j, course, DarkRed);
						ShowStringColor_(30 + course.size(), default + j, " ERROR CURSO NO ENCONTRADO", DarkRed);
					}
					else {
						ShowStringColor_(1, default + j, "(x)", DarkRed);
						ShowStringColor_(10 + course.size(), default + j, "ERROR CURSO NO ENCONTRADO", DarkRed);
					}

					j++;
					ShowStringColor_(0, default + j, " (i) ", White); cin >> course;
				} while (!ValidateCourse_(course));

				cout << endl;
				j++;
			}

			ofstream file("TeachersDataBase.txt", ios::app);
			file << name << "," << lastName << "," << code << ",\"" << course << "\"" << endl;

			cout << "\nNuevo maestro agregado correctamente." << endl;

			execute = true;
			WaitKey_();
		}
			  break;

		case 5: {
			end = true;
		}
			  break;

		default: {
			do {
				cout << "INGRESO INVALIDO... Vuelva a ingresar su opcion: "; cin >> option;
			} while (!(1 <= option && option <= 5));

			if (option == 5)  end = true;
		}
			   break;
		}

		ClearScreen_();

		studentList = LoadStudentsDataBaseToList_();
		teacherList = LoadTeachersDataBaseToList_();
		if (execute) option = ShowMainMenu_();
	} while (!end);

	ClearScreen_();
	cout << "\n �Hasta luego!" << endl;

	WaitKey_();
	return 0;
}