#include <iostream>
#include <vector>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;
using std::cout;
using std::cerr;


int main() {

	int numStudents = 5;


	{
		std::cout << "C867 Scripting and Programming: Applications" << endl;
		std::cout << "Language: C++" << endl;
		std::cout << "Student ID: 001050187" << endl;
		std::cout << "Nicholas Doyon" << endl;
	}
	const std::string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Nicholas,Doyon,ndoyon1@wgu.edu,30,35,14,10,SOFTWARE"
	};

	
	Roster* classRoster = new Roster(numStudents);
	cout << "Parsing data and Adding Students, please hold:\t";
	for (int i = 0; i < numStudents; ++i)
		
	{
		
		classRoster->parseThenAdd(studentData[i]);

	}
	cout << endl;
	
	cout << "Done.\n";
	cout << endl;
	cout << "Displaying all students:\n";
	cout << endl;

	classRoster->Print_All();
	cout << endl;
	cout << endl;

	cout << "Invalid Emails:" << endl;
	classRoster->PrintInvalidEmails();
	cout << endl;
	cout << endl;

	cout << "Average days in a course:\n";
	for (int i = 0; i < numStudents; ++i) {
		classRoster->PrintAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
	}
	cout << endl;
	cout << endl;
	
	classRoster->PrintByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;
	cout << "Removing A3:\n";

	if (classRoster->Remove("A3")) {
		classRoster->Print_All();
		numStudents--;
	}
	else cout << "a student with this ID was not found.\n";

	cout << endl;

	cout << "Removing A3:\n";
	if (classRoster->Remove("A3")) classRoster->Print_All();
	else cout << "a student with this ID was not found.\n";

	cout << endl;
	cout << "Done!\n";

	system("pause");
	return 0;
}