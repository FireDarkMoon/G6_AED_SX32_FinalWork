#include "Libraries.h"
#include "EnumsConstants.h"
#include "Functions.h"
#include "ExtraFunctions.h"
#include "List.h"
#include "Student.h"
#include "Teacher.h"

List<Student*>* LoadStudentsDataBaseToList_() {
	string fileName{ "StudentsDataBase.txt" };
	ifstream dataBase(fileName);

	if (!dataBase.is_open()) {
		ClearScreen_();
		cout << "\nERROR AL ABRIR EL ARCHIVO: \"" << fileName << "\"" << endl;
		WaitKey_();
		return nullptr;
	}

	List<Student*>* studentList = new List<Student*>(); // Crear la lista de estudiantes

	string line;
	while (getline(dataBase, line)) {
		istringstream ss(line);

		string nameSS, lastNameSS, codeSS;
		getline(ss, nameSS, ',');
		getline(ss, lastNameSS, ',');
		getline(ss, codeSS, ',');

		string coursesLineSS;
		getline(ss, coursesLineSS, '"');
		getline(ss, coursesLineSS, '"');

		istringstream ssC(coursesLineSS);

		string course;
		queue<string> coursesSS;
		while (getline(ssC, course, ','))
			coursesSS.push(course);

		string scoresLineSS;
		getline(ss, scoresLineSS, '"');
		getline(ss, scoresLineSS, '"');

		istringstream ssS(scoresLineSS);

		string score;
		queue<int> scoresSS;
		while (getline(ssS, score, ','))
			scoresSS.push(stoi(score));

		Student* tempStudent = new Student(nameSS, lastNameSS, codeSS, coursesSS, scoresSS);
		studentList->AddFinal_(tempStudent);
	}

	return studentList;
}

List<Teacher*>* LoadTeachersDataBaseToList_() {
	string fileName{ "TeachersDataBase.txt" };
	ifstream dataBase(fileName);

	if (!dataBase.is_open()) {
		ClearScreen_();
		cout << "\nERROR AL ABRIR EL ARCHIVO: \"" << fileName << "\"" << endl;
		WaitKey_();
	}

	List<Teacher*>* teacherList = new List<Teacher*>(); // Crear la lista de profesores

	string line;
	while (getline(dataBase, line)) {
		istringstream ss(line);

		string nameSS, lastNameSS, codeSS;
		getline(ss, nameSS, ',');
		getline(ss, lastNameSS, ',');
		getline(ss, codeSS, ',');

		string coursesLineSS;
		getline(ss, coursesLineSS, '"');
		getline(ss, coursesLineSS, '"');

		istringstream ssC(coursesLineSS);

		string course;
		queue<string> coursesSS;
		while (getline(ssC, course, ','))
			coursesSS.push(course);

		Teacher* tempTeacher = new Teacher(nameSS, lastNameSS, codeSS, coursesSS);
		teacherList->AddFinal_(tempTeacher);
	}

	return teacherList;
}

void AddCoursesFile_(string _codeStudent, string _newCourse) {
	string fileName = "StudentsDataBase.txt";
	ifstream dataBase(fileName);
	ofstream tempDataBase("Temp.txt");

	if (!dataBase.is_open()) {
		cout << "ERROR AL ABRIR EL ARCHIVO: " << fileName << endl;
		WaitKey_();
	}

	string line;
	while (getline(dataBase, line)) {
		istringstream ss(line);
		string nameSS, lastNameSS, codeSS, coursesSS, scoresSS;

		getline(ss, nameSS, ',');
		getline(ss, lastNameSS, ',');
		getline(ss, codeSS, ',');
		getline(ss, coursesSS, '"');
		getline(ss, coursesSS, '"');
		getline(ss, scoresSS, '"');
		getline(ss, scoresSS, '"');

		if (codeSS == _codeStudent) {
			if (coursesSS == "NULL") {
				coursesSS = "";
				coursesSS += _newCourse;
			}
			else
				coursesSS += "," + _newCourse;
		}

		tempDataBase << nameSS << "," << lastNameSS << "," << codeSS << ",\"" << coursesSS << "\",\"" << scoresSS << "\"" << endl;
	}

	dataBase.close();
	tempDataBase.close();

	remove(fileName.c_str());
	rename("Temp.txt", fileName.c_str());
}

bool ValidateCourse_(const string& _course) {
	if (_course == "fin") return true;

	string fileName{ "CoursesDataBase.txt" };
	ifstream dataBase(fileName);

	if (!dataBase.is_open()) {
		ClearScreen_();
		cout << "\nERROR AL ABRIR EL ARCHIVO: \"" << fileName << "\"" << endl;
		WaitKey_();
		return false;
	}

	string course;
	while (getline(dataBase, course))
		if (course == _course)
			return true;

	return false;
}

string EnterCourses_(char _c) {
	int index = 1;
	int j = 0;
	int default = (_c == 'T') ? 4 : ((_c == 'S') ? 1 : 0);

	string course, courses;
	cout << "Ingrese los cursos ('fin' para terminar):" << endl;
	while (true) {
		cout << "(" << index << ") "; cin >> course;

		if (!ValidateCourse_(course)) {
			do {
				ShowStringColor_(1, default + index + j, "X", DarkRed);
				ShowStringColor_(10 + course.size(), default + index + j, "ERROR CURSO NO ENCONTRADO", DarkRed);

				j++;
				ShowStringColor_(0, default + index + j, "(" + to_string(index) + ") ", White); cin >> course;
			} while (!ValidateCourse_(course));

			cout << endl;
			j++;
		}

		if (course == "fin") {
			courses.erase(courses.size() - 1);
			break;
		}

		index++;
		courses += course + ",";
	}

	return courses;
}