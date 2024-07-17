#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"


using namespace std;

Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    this->daysToCompleteCourse[0] = 0;
    this->daysToCompleteCourse[1] = 0;
    this->daysToCompleteCourse[2] = 0;
    this->degreeProgram = SOFTWARE;
}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysToCompleteCourse[3], DegreeProgram degreeProgram) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysToCompleteCourse[0] = daysToCompleteCourse[0];
    this->daysToCompleteCourse[1] = daysToCompleteCourse[1];
    this->daysToCompleteCourse[2] = daysToCompleteCourse[2];
    this->degreeProgram = degreeProgram;
}

// Mutators
void Student::setStudentId(string id) {
    this->studentId = id;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student:: setLastName(string lastName) {
    this->lastName = lastName;
}

void Student:: setEmail(string email){
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToCompleteCourse(int day1, int day2, int day3) {
    this->daysToCompleteCourse[0] = day1;
    this->daysToCompleteCourse[1] = day2;
    this->daysToCompleteCourse[2] = day3;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}


// Getters

string Student::getStudentId() {
    return this -> studentId;
}


string Student::getFirstName() {
    return this->firstName;
}

string Student::getLastName() {
    return this->lastName;
}

string Student::getEmail() {
    return this->email;
}

int Student::getAge() {
    return this->age;
}

int* Student::getDaysToCompleteCourse() {
    return this->daysToCompleteCourse;
}

DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}

void Student::print() {

    string degree;

	if (degreeProgram == SECURITY) {
		degree = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degree = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		degree = "SOFTWARE";
	} else {
		degree = "No degree found";
	}

 	cout << studentId
		<< "   First Name: " << getFirstName()
		<< "   Last Name: " << getLastName()
		<< "   Age: " << getAge() << "  "
		<< "Days in courses: {" << getDaysToCompleteCourse()[0] << " " << getDaysToCompleteCourse()[1] << " " << getDaysToCompleteCourse()[2] << "} Degree Program: " << degree << " "<< endl;


}