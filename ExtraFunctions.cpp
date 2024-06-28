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

		string nameSS, lastNameSS, codeSS, courseSS;
		getline(ss, nameSS, ',');
		getline(ss, lastNameSS, ',');
		getline(ss, codeSS, ',');
		getline(ss, courseSS, '"');
		getline(ss, courseSS, '"');

		queue<string> coursesSS;
		coursesSS.push(courseSS);

		Teacher* tempTeacher = new Teacher(nameSS, lastNameSS, codeSS, coursesSS);
		teacherList->AddFinal_(tempTeacher);
	}

	return teacherList;
}

queue<string> EnterCoursesScores_(char _c) {
	int index = 1;
	int j = 0;
	int default = (_c == 'T') ? 4 : ((_c == 'S') ? 1 : 0);
	int counter = 0;

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
		counter++;
		courses += course + ",";
	}

	queue<string> tempCoursesScores;
	tempCoursesScores.push(courses);

	if (_c == 'S') {
		string scores;
		for (int i = 0; i < counter; i++) {
			if (i == counter - 1) scores += "-1";
			else scores += "-1,";
		}

		tempCoursesScores.push(scores);
	}

	return tempCoursesScores;
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


	string line;
	while (getline(dataBase, line)) {
		istringstream ss(line);

		string courseSS, daysSS, hoursSS;
		getline(ss, courseSS, ',');
		getline(ss, daysSS, '"');
		getline(ss, daysSS, '"');
		getline(ss, hoursSS, '"');
		getline(ss, hoursSS, '"');

		if (courseSS == _course)
			return true;
	}

	return false;
}

void AddCoursesFile_(string _codeStudent, string _newCourse, string _newScore) {
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
			if (coursesSS == "NULL" || scoresSS == "-2") {
				coursesSS = "";
				coursesSS += _newCourse;

				scoresSS = "";
				scoresSS += _newScore;
			}
			else {
				coursesSS += "," + _newCourse;
				scoresSS += "," + _newScore;
			}
		}

		tempDataBase << nameSS << "," << lastNameSS << "," << codeSS << ",\"" << coursesSS << "\",\"" << scoresSS << "\"" << endl;
	}

	dataBase.close();
	tempDataBase.close();

	remove(fileName.c_str());
	rename("Temp.txt", fileName.c_str());
}




void AddScoresFile_(string _codeStudent, int _amountCourses, int _newScore, int _indexCourse) {
	string fileName = "StudentsDataBase.txt";
	ifstream dataBase(fileName);
	ofstream tempDataBase("Temp.txt");

	if (!dataBase.is_open()) {
		cout << "ERROR AL ABRIR EL ARCHIVO: " << fileName << endl;
		return;
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
			istringstream scoreSS(scoresSS);
			string score;
			string newScores = "";

			for (int i = 0; i < _amountCourses; ++i) {
				getline(scoreSS, score, ',');
				if (i == _indexCourse - 1) {
					newScores += to_string(_newScore);
				}
				else {
					newScores += score;
				}
				if (i != _amountCourses - 1) {
					newScores += ",";
				}
			}

			tempDataBase << nameSS << "," << lastNameSS << "," << codeSS << ",\"" << coursesSS << "\",\"" << newScores << "\"" << endl;
		}
		else {
			tempDataBase << line << endl;
		}
	}

	dataBase.close();
	tempDataBase.close();

	remove(fileName.c_str());
	rename("Temp.txt", fileName.c_str());
}



void ShowSchedule_(queue<string> _tempCourses) {
	int numCellsHorizontal = 7;
	int numCellsVertical = 17;
	int cellWidth = 13;
	int cellHeight = 1;
	int cellWidthWithBorder = cellWidth + 1;
	int cellHeightWithBorder = cellHeight + 1;
	int tableWidth = numCellsHorizontal * cellWidthWithBorder + 1;
	int tableHeight = numCellsVertical * cellHeightWithBorder + 1;
	int x = 2;
	int y = 2;
	int color = DarkGreen;

	DrawTable_(numCellsHorizontal, numCellsVertical, cellWidth, cellHeight, color, x, y);

	int start = 7;
	int end = start + 1;
	int day = 1;
	for (int j = 0; j < tableWidth; j++) {
		for (int i = 0; i < tableHeight; i++) {
			if (i > 2 && i % 2 != 0 && j == 1) {
				string hourRange =
					(start < 9) ? "0" + to_string(start) + ":00-0" + to_string(end) + ":00" :
					(start == 9) ? "0" + to_string(start) + ":00-" + to_string(end) + ":00" :
					to_string(start) + ":00-" + to_string(end) + ":00";

				FontColor_(DarkRed);
				ShowString_(j + 2 * x + 1, i + y, hourRange);

				start++;
				end++;
			}

			if (j > 14 && (j - 1) % 14 == 0 && i == 1) {
				string days =
					(day == 1) ? "    Lunes" :
					(day == 2) ? "   Martes" :
					(day == 3) ? "  Miercoles" :
					(day == 4) ? "   Jueves" :
					(day == 5) ? "   Viernes" :
					"   Sabado";

				FontColor_(DarkBlue);
				ShowString_(j + 2 * x, i + y, days);

				day++;
			}
		}
	}

	string course = "";
	string M[16][6] = { "" };
	for (int k = 0; k < 16; k++) {
		for (int p = 0; p < 6; p++) {
			M[k][p] = "(" + to_string(k + 1) + "," + to_string(p + 1) + ")";

			if (
				M[k][p] == "(2,1)" ||
				M[k][p] == "(3,1)" ||
				M[k][p] == "(5,5)" ||
				M[k][p] == "(6,5)" ||
				M[k][p] == "(16,3)"
				) course = "Algebra";
			else if (
				M[k][p] == "(1,6)" ||
				M[k][p] == "(2,6)" ||
				M[k][p] == "(5,3)" ||
				M[k][p] == "(6,3)"
				) course = "Geometria";
			else if (
				M[k][p] == "(3,2)" ||
				M[k][p] == "(4,6)" ||
				M[k][p] == "(5,6)" ||
				M[k][p] == "(8,4)" ||
				M[k][p] == "(9,4)"
				) course = "Trigonometria";
			else if (
				M[k][p] == "(4,1)" ||
				M[k][p] == "(6,6)" ||
				M[k][p] == "(9,5)" ||
				M[k][p] == "(10,5)"
				) course = "Aritmetica";
			else if (
				M[k][p] == "(7,1)" ||
				M[k][p] == "(10,3)"
				) course = "Estadistica";
			else if (
				M[k][p] == "(1,4)" ||
				M[k][p] == "(2,4)" ||
				M[k][p] == "(4,2)" ||
				M[k][p] == "(5,2)"
				) course = "RazLogico";
			else if (
				M[k][p] == "(5,1)" ||
				M[k][p] == "(11,5)"
				) course = "RazMatematico";
			else if (
				M[k][p] == "(6,2)" ||
				M[k][p] == "(7,2)" ||
				M[k][p] == "(12,4)" ||
				M[k][p] == "(13,4)"
				) course = "Fisica";
			else if (
				M[k][p] == "(2,3)" ||
				M[k][p] == "(3,3)" ||
				M[k][p] == "(8,6)" ||
				M[k][p] == "(9,6)"
				) course = "Quimica";
			else if (
				M[k][p] == "(10,6)" ||
				M[k][p] == "(11,6)" ||
				M[k][p] == "(12,2)" ||
				M[k][p] == "(13,2)" ||
				M[k][p] == "(14,4)"
				) course = "Biologia";
			else if (
				M[k][p] == "(6,1)" ||
				M[k][p] == "(14,6)" ||
				M[k][p] == "(15,6)" ||
				M[k][p] == "(16,6)"
				) course = "Lenguaje";
			else if (
				M[k][p] == "(1,2)" ||
				M[k][p] == "(2,2)" ||
				M[k][p] == "(13,5)" ||
				M[k][p] == "(14,5)"
				) course = "Literatura";
			else if (
				M[k][p] == "(1,3)" ||
				M[k][p] == "(13,1)" ||
				M[k][p] == "(14,1)"
				) course = "RazVerbal";
			else if (
				M[k][p] == "(10,4)" ||
				M[k][p] == "(11,4)" ||
				M[k][p] == "(14,2)" ||
				M[k][p] == "(15,5)" ||
				M[k][p] == "(16,5)"
				) course = "Economia";
			else if (
				M[k][p] == "(1,1)" ||
				M[k][p] == "(12,6)" ||
				M[k][p] == "(13,6)"
				) course = "DPCC";
			else if (
				M[k][p] == "(8,2)" ||
				M[k][p] == "(9,2)" ||
				M[k][p] == "(13,3)" ||
				M[k][p] == "(14,3)"
				) course = "Historia";
			else if (
				M[k][p] == "(11,1)" ||
				M[k][p] == "(15,4)"
				) course = "Geografia";
			else if (
				M[k][p] == "(4,4)" ||
				M[k][p] == "(5,4)" ||
				M[k][p] == "(15,2)"
				) course = "Filosofia";
			else if (
				M[k][p] == "(7,5)" ||
				M[k][p] == "(8,5)" ||
				M[k][p] == "(9,1)" ||
				M[k][p] == "(10,1)"
				) course = "Psicologia";
			else if (
				M[k][p] == "(2,5)" ||
				M[k][p] == "(3,5)" ||
				M[k][p] == "(8,3)" ||
				M[k][p] == "(16,1)"
				) course = "Ingles";
			else {
				course = " ";
			}

			M[k][p] = course;
		}
	}

	bool show;
	string cell;
	queue<string> auxCourses;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 6; j++) {
			cell = M[i][j];
			show = false;
			auxCourses = _tempCourses;

			while (!auxCourses.empty()) {
				if (auxCourses.front() == cell) {
					show = true;
					break;
				}
				auxCourses.pop();
			}

			if (show)
				ShowStringColor_(
					2 * x + (cellWidthWithBorder * (j + 1) + 1),
					y + (cellHeightWithBorder * (i + 1)) + 1,
					cell,
					DarkYellow);
		}
	}

	FontColor_(White);
}
