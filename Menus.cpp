#include  "Libraries.h"
#include "Functions.h"
#include "ExtraFunctions.h"
#include "List.h"
#include "Student.h"

int ShowMainMenu_() {
	int option;

	cout << "-------Menu--------"
		<< "\n1. Ingresar como alumno (codigo)"
		<< "\n2. Ingresar como profesor (codigo)"
		<< "\n3. Crear nuevo alumno"
		<< "\n4. Crear nuevo profesor"
		<< "\n5. Salir" << endl
		<< "\nIngrese su opcion: "; cin >> option;

	return option;
}

int ShowSubMenuStudent_() {
	int option;

	cout
		<< "\n1.1. Ver cursos matriculados"
		<< "\n1.2. Ver horario"
		<< "\n1.3. Inscribirse en un curso"
		<< "\n1.4. Ver calificaciones (notas)"
		<< "\n1.5. Ver pensiones pendientes"
		<< "\n1.6. Pagar pensiones"
		<< "\n1.7. Atras" << endl
		<< "\nIngrese su opcion: "; cin >> option;

	return option;
}

int ShowSubMenuTeacher_() {
	ClearScreen_();
	int option;

	cout << "\n2.1. Ver cursos impartidos"
		<< "\n2.2. Ver alumnos por curso"
		<< "\n2.3. Ver horario"
		<< "\n2.4. Registrar nota"
		<< "\n2.5. Atras" << endl
		<< "\nIngrese su opcion: "; cin >> option;

	return option;
}

void CallSubMenu1_(Student* _tempStudent) {
	ClearScreen_();

	List<Student*>* tempStudentList = LoadStudentsDataBaseToList_();
	Student* tempStudent = tempStudentList->Search_(_tempStudent->getCode_());

	cout << "[]=== BIENVENIDO " << tempStudent->getName_() << " " << tempStudent->getLastName_() << " EXPLORA TUS OPCIONES ===[]" << endl;

	int option{ ShowSubMenuStudent_() };
	bool end{ false };
	do {
		bool execute{ false };

		switch (option) {
		case 1: {
			ClearScreen_();
			tempStudent->PrintCourses_();
			execute = true;
			WaitKey_();
		}
			  break;

		case 2: {

		}
			  break;

		case 3: {
			ClearScreen_();

			cout << endl;
			string coursesAdd = EnterCourses_('S');

			cout << "\nCursos agregados correctamente";
			AddCoursesFile_(tempStudent->getCode_(), coursesAdd);

			execute = true;
			WaitKey_();
		}
			  break;

		case 4: {

		}
			  break;

		case 5: {

		}
			  break;

		case 6: {

		}
			  break;


		case 7: {
			end = true;
		}
			  break;

		default: {
			do {
				cout << "INGRESO INVALIDO... Vuelva a ingresar su opcion: "; cin >> option;
			} while (!(1 <= option && option <= 7));

			if (option == 7)  end = true;
		}
			   break;
		}

		ClearScreen_();

		tempStudentList = LoadStudentsDataBaseToList_();
		tempStudent = tempStudentList->Search_(_tempStudent->getCode_());
		if (execute) {
			cout << "[]=== BIENVENIDO " << tempStudent->getName_() << " " << tempStudent->getLastName_() << " EXPLORA TUS OPCIONES ===[]" << endl;
			option = ShowSubMenuStudent_();
		}
	} while (!end);

	ClearScreen_();
}

void CallSubMenu2_(Teacher* _tempTeacher) {
	ClearScreen_();
	cout << "Funciona"; system("pause");

	bool end{ false };
	int option{ ShowSubMenuTeacher_() };

	do {
		bool execute{ false };

		switch (option) {
		case 1: {

		}
			  break;

		case 2: {

		}
			  break;

		case 3: {
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

		if (execute) option = ShowSubMenuTeacher_();
	} while (!end);

	ClearScreen_();
}
