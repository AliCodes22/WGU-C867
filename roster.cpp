#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>

Roster::Roster(int size) {
    this->classSize = size;
    this->index = 0;

    for(int i = 0; i < size; i++) {
        this->classRosterArray[i] = new Student;
    }
}


// returns student id based on the index provided
std::string Roster::getStudentID(int index) {
    std::string studentID = classRosterArray[index]->getStudentID();
    return studentID;
}

void Roster::parseData(std::string studentData) {
    std::string studentID, firstName, lastName, email;
    int age, day1, day2, day3;

    if (index < classSize) {
        classRosterArray[index] = new Student();


        // extract the substring upto the first comma to get the student id
        int currentPos = studentData.find(",");
        studentId = studentData.substr(0, currentPos);
        classRosterArray[index]->setStudentId(studentId);

        // here the starting position is from the previous position upto the next comma for firstName
        int startPos = currentPos + 1;
        currentPos = studentData.find(",", startPos);
        firstName = studentData.substr(startPos, currentPos - startPos);
        classRosterArray[index]->setFirstName(firstName);

        // here the starting position is from the previous position upto the next comma for lastName
        startPos = currentPos + 1;
        currentPos = studentData.find(",", startPos);
        lastName = studentData.substr(startPos, currentPos - startPos);
        classRosterArray[index]->setLastName(lastName);

        // here the starting position is from the previous position upto the next comma for email 

        startPos = currentPos + 1;
        currentPos = studentData.find(",", startPos);
        email = studentData.substr(startPos, currentPos - startPos);
        classRosterArray[index]->setEmail(email);


        // here the starting position is from the previous position upto the next comma for age

        startPos = currentPos + 1;
        currentPos = studentData.find(",", startPos);
        age = std::stoi(studentData.substr(startPos, currentPos - startPos));
        classRosterArray[index]->setAge(age);

        // here the starting position is from the previous position upto the next comma for day 1 , day 2, and day 3
        startPos = currentPos + 1;
        currentPos = studentData.find(",", startPos);
        day1 = std::stoi(studentData.substr(startPos, currentPos - startPos));

        startPos = currentPos + 1;
        currentPos = studentData.find(",", startPos);
        day2 = std::stoi(studentData.substr(startPos, currentPos - startPos));

        startPos = currentPos + 1;
        currentPos = studentData.find(",", startPos);
        day3 = std::stoi(studentData.substr(startPos, currentPos - startPos));
        classRosterArray[index]->setDaysToCompleteCourse(day1, day2, day3);

        // finally we extract the degree program
        startPos = currentPos + 1;
        currentPos = studentData.find(",", startPos);
        std::string degreeStr = studentData.substr(startPos, currentPos - startPos);


        DegreeProgram degree;
        if (degreeStr == "SOFTWARE") {
            degree = SOFTWARE;
        } else if (degreeStr == "SECURITY") {
            degree = SECURITY;
        } else if (degreeStr == "NETWORK") {
            degree = NETWORK;
        } else {
            std::cout << "Degree not found" << std::endl;
            return; // Exit function if degree is not found
        }
        classRosterArray[index]->setDegreeProgram(degree);
        index++;
    }
   
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age,
    int day1, int day2, int day3, DegreeProgram degreeProgram) {
    if (index < classSize) { 
        int daysToCompleteCourse[3] = { day1, day2, day3 };
        classRosterArray[index] = new Student(studentID, firstName, lastName, email, age, daysToCompleteCourse, degreeProgram);
        index++;
    }
}

void Roster::remove(std::string studentID) {
    bool studentFound = false;
    for(int i = 0; i < classSize; i++) {
        // if the student exists without a null value AND has an existing student id, delete the entry
        if(classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            studentFound = true;
            std::cout << "Student: " << classRosterArray[i]->getStudentID() << " " 
              << classRosterArray[i]->getFirstName() << " " 
              << classRosterArray[i]->getLastName() << " will be removed from the roster" << std::endl;            
              delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }

    // if student is not found print message
    if(!studentFound) {
        std::cout << "Student not found" << std::endl;
    }
}

void Roster::printData() {
    std::cout << "Class roster:" << std::endl;
    for(int i = 0; i < classSize; ++i) {
        if(classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    bool studentExists = false;
    for(int i = 0; i < classSize; ++i) {
        if(classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            studentExists = true;
            int* days = classRosterArray[i]->getDaysToCompleteCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            std::cout << "Average days to complete course: " << average << std::endl;
        }
    }
    if(!studentExists) {
        std::cout << "Student not found" << std::endl;
    }
}

void Roster::printInvalidEmails() {
    bool isInvalid = false;
    for(int i = 0; i < classSize; ++i) {
        if(classRosterArray[i] != nullptr) {
            std::string email = classRosterArray[i]->getEmail();
            if(email.find("@") == std::string::npos || email.find(".") == std::string::npos || email.find(" ") != std::string::npos) {
                isInvalid = true;
                std::cout << "Invalid email: " << email << std::endl;
            }
        }
    }
}


// print student data by degree program provided in argument
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for(int i = 0; i < classSize; ++i) {
        if(classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < classSize; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
