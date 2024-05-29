#include "Libraries.h"
#include "Functions.h"
#include "ExtraFunctions.h"

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
		<< "\n1.7. Atrás" << endl
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
		<< "\n2.5. Atrás" << endl
		<< "\nIngrese su opcion: "; cin >> option;

	return option;
}

bool ValidateDataBase_(const string& _code) {
	string line;
	ifstream inputFile("StudentsDataBase.txt");

	if (!inputFile.is_open()) {
		cout << "Error al abrir el archivo de la base de datos." << endl;
		return false;
	}

	while (getline(inputFile, line)) {
		// Crear un stringstream para dividir la línea
		stringstream ss(line);
		string name, lastName, code, courses, scores;

		// Leer los campos de la línea
		getline(ss, name, ',');
		getline(ss, lastName, ',');
		getline(ss, code, ',');

		// Validar si el código coincide
		if (_code == code) {
			inputFile.close();
			return true;
		}
	}

	inputFile.close();
	return false;
}

void trim(string& str) {
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');
    str = (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void loadStudentsFromFile(const string& filename, StudentList& studentList) {
    ifstream file;
    try {
        file.open(filename);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo!");
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name, lastName, code, coursesStr, scoresStr;

            getline(ss, name, ',');
            getline(ss, lastName, ',');
            getline(ss, code, ',');

            // Leer los cursos y los scores que están entre comillas
            getline(ss, coursesStr, '"');
            getline(ss, coursesStr, '"');
            getline(ss, scoresStr, '"');
            getline(ss, scoresStr, '"');

            // Trim leading and trailing spaces
            trim(name);
            trim(lastName);
            trim(code);
            trim(coursesStr);
            trim(scoresStr);

            queue<string> courses;
            queue<int> scores;

            // Procesar la lista de cursos
            vector<string> courseList = split(coursesStr, ',');
            for (const auto& course : courseList) {
                string trimmedCourse = course;
                trim(trimmedCourse);
                if (!trimmedCourse.empty()) {
                    courses.push(trimmedCourse);
                }
            }

            // Procesar la lista de calificaciones
            vector<string> scoreList = split(scoresStr, ',');
            for (const auto& score : scoreList) {
                string trimmedScore = score;
                trim(trimmedScore);
                if (!trimmedScore.empty()) {
                    try {
                        scores.push(stoi(trimmedScore));
                    }
                    catch (invalid_argument& e) {
                        cerr << "Error: invalid score '" << trimmedScore << "'" << endl;
                    }
                }
            }

            // Crear el objeto Student y añadirlo a la lista
            if (!name.empty() && !lastName.empty() && !code.empty() && !courses.empty() && !scores.empty()) {
                Student student(name, lastName, code, courses, scores);
                studentList.addStudent(student);
            }
            else {
                cerr << "Warning: Invalid data line '" << line << "'" << endl;
            }
        }

        file.close();
    }
     
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        if (file.is_open()) {
            file.close();
        }
    }
}