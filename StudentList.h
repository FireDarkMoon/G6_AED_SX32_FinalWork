#pragma once
#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"
using namespace std;
using namespace System;

class StudentList {
private:
	struct Node {
		Student student;
		Node* next;

		Node(const Student& student) : student(student), next(nullptr) {}
	};

	Node* head;

public:
	// Constructor para StudentList
	StudentList() : head(nullptr) {}

	// Destructor para liberar memoria
	~StudentList() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	// Metodo para agregar un estudiante a la lista
	void AddStudent_(const Student& student) {
		Node* newNode = new Node(student);
		newNode->next = head;
		head = newNode;
	}

	//Metodo para guardar en la base de datos
	void SaveStudentToFile_(const Student& _newStudent) {
		ofstream file("StudentsDataBase.txt", ios::app); // Abrir en modo de escritura
		if (!file.is_open()) {
			cout << "Error al abrir el archivo." << endl;
			return;
		}

		Node* current = head;
		while (current != nullptr) {
			const Student& student = current->student;
			file << student.getName_() << "," << student.getLastName_() << "," << student.getCode_() << ",\"";

			queue<string> tempCourses = student.getCourses_();
			while (!tempCourses.empty()) {
				file << tempCourses.front();
				tempCourses.pop();
				if (!tempCourses.empty()) file << ",";
			}
			file << "\",\"";

			queue<int> tempScores = student.getScores_();
			while (!tempScores.empty()) {
				file << tempScores.front();
				tempScores.pop();
				if (!tempScores.empty()) file << ",";
			}
			file << "\"\n";

			current = current->next;
		}

		file.close();
	}

	// Metodo para buscar un estudiante por código
	Student* FindStudent_(const string& code) {
		Node* current = head;
		while (current != nullptr) {
			if (current->student.getCode_() == code) {
				return &current->student;
			}
			current = current->next;
		}
		return nullptr;
	}

	// Metodo para validar un estudiante por código
	bool ValidateFindStudent_(const string& _code) {
		Node* current = head;
		while (current != nullptr) {
			if (current->student.getCode_() == _code) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	// Metodo para mostrar todos los estudiantes
	void ShowAllStudents_() {
		Node* current = head;
		while (current != nullptr) {
			cout << "Nombre: " << current->student.getName_()
				<< ", Apellido: " << current->student.getLastName_()
				<< ", Código: " << current->student.getCode_() << endl;
			current = current->next;
		}
	}
};

#endif // STUDENTLIST_H



/**
	// Constructor para StudentList
	StudentList() : head(nullptr) {}

	// Destructor para liberar memoria
	~StudentList() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void AddStudent_(const Student& _newStudent) {
		// Buscar si el estudiante ya existe en la base de datos
		if (FindStudent_(_newStudent.getCode_()) != nullptr) {
			// El estudiante ya existe, actualizar sus cursos
			updateStudentCourses(_newStudent);
		}
		else {
			// El estudiante no existe, agregarlo a la lista y a la base de datos
			Node* newNode = new Node(_newStudent);
			newNode->next = head;
			head = newNode;

			// Agregar el estudiante a la base de datos
			SaveStudentToFile_(_newStudent);
		}
	}





	void printList() const {
		Node* current = head;
		while (current) {
			cout << "Name: " << current->student.getName_() << endl;
			cout << "Last Name: " << current->student.getLastName_() << endl;
			cout << "Code: " << current->student.getCode_() << endl;
			cout << "Courses: ";
			current->student.PrintCourses_();
			cout << "Scores: ";
			queue<int> scores = current->student.getScores_();
			while (!scores.empty()) {
				cout << scores.front() << " ";
				scores.pop();
			}
			cout << endl << endl;
			current = current->next;
		}
	}
	// Metodo para actualizar los cursos de un estudiante en la base de datos
	void updateStudentCourses(const Student& _newStudent) {
		// Abrir el archivo en modo de lectura y escritura
		ifstream inputFile("StudentsDataBase.txt");
		ofstream tempFile("temp.txt");

		if (!inputFile.is_open() || !tempFile.is_open()) {
			cout << "Error al abrir el archivo." << endl;
			return;
		}

		string line;
		while (getline(inputFile, line)) {
			// Separar la línea en partes usando ',' como delimitador
			stringstream ss(line);
			string name, lastName, code, courses, scores;
			getline(ss, name, ',');
			getline(ss, lastName, ',');
			getline(ss, code, ',');
			getline(ss, courses, ',');
			getline(ss, scores);

			// Comparar el código del estudiante actual con el nuevo estudiante
			if (code == _newStudent.getCode_()) {
				// Sobrescribir los cursos del estudiante con los cursos del nuevo estudiante
				tempFile << name << "," << lastName << "," << code << ",\"";
				queue<string> tempCourses = _newStudent.getCourses_();
				while (!tempCourses.empty()) {
					tempFile << tempCourses.front();
					tempCourses.pop();
					if (!tempCourses.empty()) tempFile << ",";
				}
				tempFile << "\",\"" << scores << "\"\n";
			}
			else {
				// Escribir la línea original sin modificar en el archivo temporal
				tempFile << line << endl;
			}
		}

		// Cerrar los archivos
		inputFile.close();
		tempFile.close();

		// Eliminar el archivo original y renombrar el archivo temporal
		remove("StudentsDataBase.txt");
		rename("temp.txt", "StudentsDataBase.txt");
	}

	// Metodo para eliminar un estudiante por código
	void removeStudent(const string& code) {
		Node* current = head;
		Node* previous = nullptr;

		while (current != nullptr && current->student.getCode_() != code) {
			previous = current;
			current = current->next;
		}

		if (current == nullptr) {
			cout << "Estudiante no encontrado." << endl;
			return;
		}

		if (previous == nullptr) {
			head = current->next;
		}
		else {
			previous->next = current->next;
		}

		delete current;
		cout << "Estudiante eliminado." << endl;
	}



	**/