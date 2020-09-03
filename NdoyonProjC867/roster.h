#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

;using std::string;

class Roster {

private:
	int lastIndex;  
	int capacity;   
	
	

public:

	Roster(); //constructor sets to 0
	Roster(int capacity); //constructor sets max size
	Student** classRosterArray;
	
	void parseThenAdd(string studentData); //parses then adds
	void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysinc1, int daysinc2, int daysinc3, DegreeProgram degreeprogram);
	void Print_All(); 
	bool Remove(string studentID);
	void PrintAverageDaysInCourse(string studentID);
	void PrintInvalidEmails(); 
	void PrintByDegreeProgram(DegreeProgram degreeprogram); //pulls from Enum degree.h



	~Roster(); //destructor

};
