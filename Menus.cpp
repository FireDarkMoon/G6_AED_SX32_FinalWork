#include  "Libraries.h"
#include "Functions.h"
#include "ExtraFunctions.h"
#include "Student.h"
#include "StudentList.h"

void HandleSubMenu1_(StudentList& _studentList, Student* _tempStudent, const string& _code) {
	ClearScreen_();
	cout << "[]=== BIENVENIDO " << _tempStudent->getName_() << " " << _tempStudent->getLastName_() << " EXPLORA TUS OPCIONES ===[]" << endl;
	int option{ ShowSubMenuStudent_() };

	bool end{ false };
	do {
		bool execute{ false };

		switch (option) {
		case 1: {
			ClearScreen_();
			execute = true;
			_tempStudent->PrintCourses_();
			WaitKey_();


		}
			  break;

		case 2: {

		}
			  break;

		case 3: {




			/*
						  //ESPACIO
						  //ESPACIO
						  //ESPACIO
						  //ESPACIO
						  //ESPACIO
			execute = true;
			string course;
			int courseNumber{ 1 };

			cout << "Ingrese los cursos (escriba 'fin' para terminar):" << endl;
			while (true) {
				cout << "(" << courseNumber << ") "; cin >> course;
				if (course == "fin") break;

				_tempStudent->AddCourse_(course); // Asumiendo que Student tiene un método addCourse
				courseNumber++;
			}

			// Agregar el estudiante a la lista y actualizar la base de datos
			_studentList.AddStudent_(*_tempStudent);

			cout << "Cursos agregados correctamente." << endl;
			WaitKey_();
		  */
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
		if (execute) {
			cout << "[]=== BIENVENIDO " << _tempStudent->getName_() << " " << _tempStudent->getLastName_() << " EXPLORA TUS OPCIONES ===[]" << endl;
			option = ShowSubMenuStudent_();
		}

	} while (!end);

	ClearScreen_();
}

void HandleSubMenu2_() {
	bool end{ false };
	int option{ ShowSubMenuTeacher_() };

	do {
		bool execute{ false };

		switch (option) {
		case 1: {
			execute = true;
			{
				ClearScreen_();
				cout << "Funciona"; system("pause");
			}
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
			} while (!(1 <= option && option <= 5));

			if (option == 5)  end = true;
		}
			   break;
		}

		if (execute) option = ShowSubMenuTeacher_();
	} while (!end);

	ClearScreen_();
}

void HandleSubMenu3_() {


}
