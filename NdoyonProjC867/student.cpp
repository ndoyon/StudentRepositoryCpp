#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"
#include "degree.h"

using std::cout;
using std::string;

Student::Student()
{
	this->studentID = "studentID";
	this->firstName = "firstName";
	this->lastName = "lastName";
	this->emailAddress = "emailAddress";
	this->studentAge = 0;
	this->daysInCourse = new int[daysInCourse_Size];
	for (int i = 0; i < daysInCourse_Size; ++i) this->daysInCourse[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[], DegreeProgram degreeprogram) //full constructor
{	
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->daysInCourse = new int[daysInCourse_Size];
	for (int i = 0; i < daysInCourse_Size; ++i) this->daysInCourse[i] = daysInCourse[i];
	this->degreeprogram = degreeprogram;
}

	//getters
	string Student::getStudentID()
	{
		return studentID;
	}
	string Student::getFirstName()
	{
		return firstName;
	}

	string Student::getLastName()
	{
		return lastName;
	}

	string Student::getEmailAddress()
	{
		return emailAddress;
	}

	int Student::getStudentAge() 
	{
		return studentAge;
	}

	int* Student::getDaysInCourse()
	{
		return daysInCourse;
	}
	DegreeProgram	Student::getDegreeProgram()
	{
		return degreeprogram;
	}

	//setters

	void Student::setStudentID(string studentID)
	{
		studentID = studentID;
	}

	void Student::setFirstName(string firstName)
	{
		this->firstName = firstName;
	}

	void Student::setLastName(string lastName)
	{
		this->lastName = lastName;
	}

	void Student::setEmailAddress(string emailAddress)
	{ 
		this->emailAddress = emailAddress;
	}

	void Student::setStudentAge(int studentAge)
	{
		this->studentAge = studentAge;
	}

	void Student::setDaysInCourse(int daysInCourse[])
	{
		if (this->daysInCourse != nullptr) {
			delete[] this->daysInCourse;
			this->daysInCourse = nullptr;
		}
		this->daysInCourse = new int[daysInCourse_Size];
		for (int i = 0; i < 3; ++i) {
			this->daysInCourse[i] = daysInCourse[i];

		}
	}
	void Student::setDegreeProgram(DegreeProgram degreeprogram)
	{
		this->degreeprogram = degreeprogram;
	}
	 
	
	void Student::print() {
	
	
	string studentID = getStudentID();
	string firstName = getFirstName();
	string lastName = getLastName();
	string emailAddress = getEmailAddress();
	int studentAge = getStudentAge();
	int* course = getDaysInCourse();
	DegreeProgram degreeprogram = getDegreeProgram();
	
		
	cout << studentID << "\t";
	cout << "First name: " << firstName << "\t";
	cout << "Last name: " << lastName << "\t";
	cout << "Email: " << emailAddress << "\t";
	cout << "Age: " << studentAge << "\t";
	cout << "daysInCourse: {" << *course << " " << *(course + 1) << " " << *(course + 2) << "}" << "\t";
	cout << degreeTypeStrings[degreeprogram] << "\t";
	cout << endl;
	}
	
	
	//destructor
	Student::~Student() {


		if (daysInCourse != nullptr) {
			delete[] daysInCourse;
			daysInCourse = nullptr;

		}
	}