#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "roster.h"
#include "student.h"
#include "degree.h"
using std::cout;
using std::cerr;
using std::string;
using namespace std;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity]; 
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int numCourseDay[Student::daysInCourse_Size] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	
	Student* student = new Student(studentID, firstName, lastName, emailAddress, studentAge, numCourseDay, degreeprogram);
	
	classRosterArray[lastIndex] = student;
}

void Roster::parseThenAdd(string row) 
{
	
	if (lastIndex < capacity) {
		lastIndex++;
		
	}
	else{
	
	cerr << "Error, max capacity!\n Exiting Now";
	exit(-1);
	}

	
	int rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int studentAge = std::stoi(row.substr(lhs, rhs - lhs));
		
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse1 = std::stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = std::stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = std::stoi(row.substr(lhs, rhs - lhs));

		
	lhs = rhs + 1;			
	rhs = row.length();
	string degreeprogramstring = row.substr(lhs, rhs);
	DegreeProgram degreeprogram;
		
	if (degreeprogramstring == "SOFTWARE") {
			degreeprogram = DegreeProgram::SOFTWARE;
	}
	else if ( degreeprogramstring =="NETWORK"){
			degreeprogram = DegreeProgram::NETWORK;
	}
	else if (degreeprogramstring == "SECURITY") {
			degreeprogram = DegreeProgram::SECURITY;
	}
	else {
			cout << "Error! Non Degree Type! ";
			exit(-1);
	}
		
	add(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	
}


void Roster::Print_All() {
	

	for (int i = 0; i <= this->lastIndex; ++i) {
		(this->classRosterArray)[i]->print();

	}


}

bool Roster::Remove(string studentID) { //removes A3

	bool found = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;

		}
	}
	return found;
}




void Roster::PrintInvalidEmails() //Prints invalid email
{
	for (int i = 0; i < lastIndex; ++i) {

		string emails = classRosterArray[i]->getEmailAddress();

		int npos = -1;
		if ((emails.find("@") == npos) || (emails.find(".") == npos) || !(emails.find(" ") == npos)) {
			cout << emails << " is an invalid email\n";
		}
	}
	cout << endl;
}

void Roster::PrintAverageDaysInCourse(string studentID) //Prints Average
{

	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			int* courseDays = classRosterArray[i]->getDaysInCourse();
			cout << "Average number of days per course for student: " << studentID << " is " << (courseDays[0] + courseDays[1] + courseDays[2]) / 3 << endl;
		}
	}
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeprogram)
{
	cout << "Students with degree type:  " <<degreeTypeStrings[degreeprogram] << "\n";

	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeprogram) this->classRosterArray[i]->print();

			
	}
}

Roster::~Roster()
{
	for (int i = 0; i < lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}