#include <iostream>
#include <sstream>
#include "degree.h"
#include "roster.h"

using namespace std;

int main()
{
    cout << "Course Title: Scripting and Programming Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 010827702" << endl;
    cout << "Name: Sophia Birbas" << endl;
    cout << endl;

    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Sophia,Birbas,sbirbas@wgu.edu,20,20,30,40,SOFTWARE"};

    // create an instance of the Roster class
    const int numStudents = sizeof(studentData) / sizeof(studentData[0]);
    Roster classRoster;

    //add each student to classRoster
    for (int i = 0; i < numStudents; ++i)
    {
        stringstream ss(studentData[i]);
        string token;
        string data[9];
        int index = 0;
        while (getline(ss, token, ','))
        {
            data[index++] = token;
        }

        DegreeProgram degreeProgram = SOFTWARE;
        if (data[8] == "SECURITY")
            degreeProgram = SECURITY;
        else if (data[8] == "NETWORK")
            degreeProgram = NETWORK;

        int daysInCourse[3] = {stoi(data[5]), stoi(data[6]), stoi(data[7])};
        classRoster.add(data[0], data[1], data[2], data[3], stoi(data[4]), daysInCourse, degreeProgram);
    }

    // print all students
    classRoster.printAll();

    // print invalid emails
    classRoster.printInvalidEmails();

    // print average days in course for each student
    for (int i = 0; i < numStudents; ++i)
    {
        string studentID = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }

    // print students by degree program
    classRoster.printByDegreeProgram(SOFTWARE);


    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
