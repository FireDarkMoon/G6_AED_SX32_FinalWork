#include  "Libraries.h"
#include "Defines.h"
#include "EnumsConstants.h"
#include "Functions.h"
#include "ExtraFunctions.h"
#include "List.h"
#include "Student.h"
#include "Menus.h"

int ShowMainMenu_() {
	int option;

	cout
		<< "-------Menu--------" << endl
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
		<< "\n1.1. Ver horario"//Falta
		<< "\n1.2. Inscribirse en un curso"
		<< "\n1.3. Ver cursos matriculados"
		<< "\n1.4. Ver calificaciones"
		<< "\n1.5. Ver pensiones pendientes"//Falta
		<< "\n1.6. Pagar pensiones"//Falta
		<< "\n1.7. Atras" << endl
		<< "\nIngrese su opcion: "; cin >> option;

	return option;
}

int ShowSubMenuTeacher_() {
	int option;

	cout
		<< "\n2.1. Ver horario"//Falta
		<< "\n2.2. Ver cursos impartidos"
		<< "\n2.3. Ver alumnos por curso"//Falta
		<< "\n2.4. Registrar nota"//Falta
		<< "\n2.5. Atras" << endl
		<< "\nIngrese su opcion: "; cin >> option;

	return option;
}

string ShowSubMenuStudentsByCourse_(Teacher* _tempTeacher) {
	Teacher* tempTeacher = _tempTeacher;
	queue<string> tempCourses = tempTeacher->getCourses_();

	int option;

	cout << endl;
	tempTeacher->PrintCourses_();
	cout << "\nIngrese su opcion: "; cin >> option;


	bool end{ false };
	while (!(1 <= option && option <= tempCourses.size())) {
		cout << "\nINGRESO INVALIDO... Vuelva a ingresar su opcion: "; cin >> option;
	}

	for (int i = 1; i <= option - 1; i++)
		tempCourses.pop();

	return tempCourses.front();
}

void CallSubMenuStudent_(Student* _tempStudent) {
	ClearScreen_();

	List<Student*>* tempStudentList = LoadStudentsDataBaseToList_();
	Student* tempStudent = tempStudentList->Search_(_tempStudent->getCode_());

	cout << "\n[]=== BIENVENIDO " << tempStudent->getName_() << " " << tempStudent->getLastName_() << " EXPLORA TUS OPCIONES ===[]" << endl;

	int option{ ShowSubMenuStudent_() };
	bool end{ false };
	do {
		bool execute{ false };

		switch (option) {
		case 1: {
			ClearScreen_();



			execute = true;
			WaitKey_();
		}
			  break;

		case 2: {
			ClearScreen_();

			cout << endl;
			queue<string>tempCoursesScores = EnterCoursesScores_('S');
			string coursesAdd = tempCoursesScores.front();
			string scoresAdd = tempCoursesScores.back();
			AddCoursesFile_(tempStudent->getCode_(), coursesAdd, scoresAdd);

			cout << "\nCursos agregados correctamente";

			execute = true;
			WaitKey_();
		}
			  break;

		case 3: {
			ClearScreen_();

			cout << endl;
			tempStudent->PrintCourses_();
			execute = true;

			WaitKey_();
		}
			  break;

		case 4: {
			ClearScreen_();

			cout << endl;
			tempStudent->PrintScores_();
			execute = true;

			WaitKey_();
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
			cout << "\n[]=== BIENVENIDO " << tempStudent->getName_() << " " << tempStudent->getLastName_() << " EXPLORA TUS OPCIONES ===[]" << endl;
			option = ShowSubMenuStudent_();
		}
	} while (!end);

	ClearScreen_();
}

void CallSubMenuTeacher_(Teacher* _tempTeacher) {
	ClearScreen_();

	List<Teacher*>* tempTeacherList = LoadTeachersDataBaseToList_();
	Teacher* tempTeacher = tempTeacherList->Search_(_tempTeacher->getCode_());

	cout << "\n[]=== BIENVENIDO " << tempTeacher->getName_() << " " << tempTeacher->getLastName_() << " EXPLORA TUS OPCIONES ===[]" << endl;

	int option{ ShowSubMenuTeacher_() };
	bool end{ false };
	do {
		bool execute{ false };

		switch (option) {
		case 1: {
			ClearScreen_();

			ShowSchedule_();
			execute = true;

			WaitKey_();
		}
			  break;

		case 2: {
			ClearScreen_();

			cout << endl;
			tempTeacher->PrintCourses_();
			execute = true;

			WaitKey_();
		}
			  break;

		case 3: {
			ClearScreen_();

			string course = ShowSubMenuStudentsByCourse_(tempTeacher);
			CallSubMenuStudentsByCourse_(course);
			execute = true;

			WaitKey_();
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

		tempTeacherList = LoadTeachersDataBaseToList_();
		tempTeacher = tempTeacherList->Search_(_tempTeacher->getCode_());
		if (execute) {
			cout << "\n[]=== BIENVENIDO " << tempTeacher->getName_() << " " << tempTeacher->getLastName_() << " EXPLORA TUS OPCIONES ===[]" << endl;
			option = ShowSubMenuTeacher_();
		}
	} while (!end);

	ClearScreen_();
}

void CallSubMenuStudentsByCourse_(string _course) {

	List<Student*>* tempStudentList = LoadStudentsDataBaseToList_();
	List<Student*>* studentsWithCourse = tempStudentList->SearchCourses_(_course);

	if (!studentsWithCourse->Empty_()) {
		Node<Student*>* currentNode = studentsWithCourse->getInitial_();
		while (currentNode != nullptr) {
			Student* student = currentNode->getElement_();
			cout << "Estudiante: " << student->getName_() << " " << student->getLastName_() << ", Codigo: " << student->getCode_() << endl;
			currentNode = currentNode->getNext_();
		}
	}
	else {
		cout << "No se encontraron estudiantes con el curso: " << _course << endl;
	}
}

