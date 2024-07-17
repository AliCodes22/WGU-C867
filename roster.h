#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "student.h"



// creating roster class
class Roster {
	public:

	// pointer
		Student* classRosterArray[5];
		Roster(int size);

		std::string getStudentId(int index);
		void parseData(std::string studentData);
		void remove(std::string studentId);
		void printData();
		void printAverageDaysInCourse(std::string studentId);
		void printInvalidEmails();


		// typo corrected
		// this was the issue in my first attempt. I had mistyped the method name
		void printByDegreeProgram(DegreeProgram degreeProgram);
			

		int classSize;
		int index;

		void add(std:: string studentId, std::string firstName, std::string lastName, std::string email, int age, int day1, int day2, int day3, DegreeProgram degreeProgram);

		~Roster();



};

#endif