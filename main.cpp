#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;

int main()
{
 
    // printing student's info
    cout <<"Course Title: C867 - Scripting and Programming - Applications"<< endl;
    cout << "Programming Language Used: C++ " << endl;
    cout << "Student ID: 012242342" << endl;
    cout << "Student Name: Ali Ahmed" << endl;
    


  // student data
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

        // my student data
        "A5,Ali,Ahmed,aahm405@wgu.edu,29,17,60,90,SOFTWARE"
    };

    

    
    // initializing class
    Roster * classRoster = new Roster(5);

    // parsing classRoster with student data
    for (int i = 0; i < 5; i++) {
        classRoster->parseData(studentData[i]);
    };

 
    // methods
    classRoster->printData();


    // printing invalid emails
    classRoster->printInvalidEmails();

    // printing average days in course for each student
    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->getStudentID(i));
    }
    



    classRoster->printByDegreeProgram(SOFTWARE);
  
    classRoster->remove("A3");
   
  
    classRoster->printData();

    // attempting to remove student with ID A3 will return message "Not found" as the entry has been deleted
    classRoster->remove("A3");

    

  
    classRoster->~Roster();
    delete classRoster;

}