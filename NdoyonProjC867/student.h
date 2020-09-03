#pragma once
#include <string>
#include "degree.h"

;using std::string;

class Student {  //class for student

public:
	const static int daysInCourse_Size = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int* daysInCourse; //days will be an array of 3
	DegreeProgram degreeprogram; //security,network,software


public:

	Student(); //constructor


	//Getters

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();


	//Setters

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setStudentAge(int studentAge);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeprogram);

	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[], DegreeProgram degreeprogram);

	void print();

	//Destructor
	~Student();
};