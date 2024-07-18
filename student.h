
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
#include <iostream>




// Student class 
class Student {

        private:
                // declaring variables for Student class
                std::string studentID;
                std::string firstName;
                std::string lastName;
                std::string email;
                int age;
                int daysToCompleteCourse[3];
                DegreeProgram degreeProgram;
        


        public: 
                Student();
                
                Student(std::string studentID, std:: string firstName, std::string lastName, std::string email, int age, int daysToCompleteCourse[3], DegreeProgram degreeProgram);
                

                // getters
                std::string getStudentID();
                std::string getFirstName();
                std::string getLastName();
                std::string getEmail();
                int getAge();
                int* getDaysToCompleteCourse();
                DegreeProgram getDegreeProgram();

                // mutators

                void setStudentID(std::string studentID);
                void setFirstName(std::string firstName);
                void setLastName(std::string lastName);
                void setEmail(std::string email);
                void setAge(int age);
                void setDaysToCompleteCourse(int day1, int day2, int day3);
                void setDegreeProgram(DegreeProgram degreeProgram);


                // print student data
                void print();

};

#endif