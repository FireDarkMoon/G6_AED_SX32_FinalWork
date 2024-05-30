#include "Libraries.h"
#include "Defines.h"
#include "EnumsConstants.h"
#include "Student.h"
#include "StudentList.h"
#include "Teacher.h"
#include "Functions.h"
#include "ExtraFunctions.h"
#include "Menus.h"
using namespace std;
using namespace System;

int main() {
	Settings_();

	StudentList studentList;
	LoadDataBaseToList_("StudentsDataBase.txt", studentList);

	bool end{ false };
	int option{ ShowMainMenu_() };

	do {
		bool execute{ false };

		switch (option) {
		case 1: {
			ClearScreen_();
			execute = true;

			string code;
			cout << "Ingrese su codigo de estudiante: "; cin >> code;

			if (studentList.ValidateFindStudent_(code)) {
				Student* tempStudent = studentList.FindStudent_(code);
				HandleSubMenu1_(studentList, tempStudent, code);
			}
			else {
				cout << "\nEstudiante no encontrado." << endl;
				WaitKey_();
			}
		}
			  break;

		case 2: {
			execute = true;
			HandleSubMenu2_();
		}
			  break;

		case 3: {
			execute = true;
			ClearScreen_();

			string name, lastName, code;
			queue<string> courses; // Cola de cursos vacía
			queue<int> scores;  // Cola de calificaciones vacía

			cout << "Ingrese el nombre del estudiante: "; cin >> name;
			cout << "Ingrese el apellido del estudiante: "; cin >> lastName;
			cout << "Ingrese el código del estudiante: "; cin >> code;
			courses.push("NULL"); scores.push(NULL);

			Student newStudent(name, lastName, code, courses, scores);
			SaveStudentFile_(newStudent);

			cout << "\nEstudiante agregado correctamente..." << endl;
			LoadDataBaseToList_("StudentsDataBase.txt", studentList);
		}
			  break;

		case 4: {
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
		if (execute) option = ShowMainMenu_();
	} while (!end);

	ClearScreen_();
	cout << "\n ¡Hasta luego!" << endl;

	char c = _getch();
	return 0;
}