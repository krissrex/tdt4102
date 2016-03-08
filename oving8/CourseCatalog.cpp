#include "CourseCatalog.h"
#include <iostream>


CourseCatalog::CourseCatalog()
{
}


CourseCatalog::~CourseCatalog()
{
}

void CourseCatalog::printCourses() const
{
	std::cout << "All courses:" << std::endl;
	//for (auto iter = courses.begin(); iter != courses.end(); ++iter)

	// Bruker referanse & for å unngå copy til course. auto blir pair<string, string>
	for (auto& course : courses)
	{
		std::cout << course.first << ": " << course.second << std::endl;
	}
}

void CourseCatalog::addCourse(std::string courseCode, std::string courseName)
{
	courses[courseCode] = courseName;
}

void CourseCatalog::removeSubject(std::string subjectCode)
{
	courses.erase(subjectCode);
}

std::string CourseCatalog::getSubjectName(std::string subjectCode) const
{
	// operator[] inserter tomme element hvis det ikke finnes
	// at vil i stedet throw'e
	try 
	{
		return courses.at(subjectCode);
	} 
	// catch alt med ...
	catch (...)
	{
		return std::string();
	}
}

std::ofstream & operator<<(std::ofstream &os, const CourseCatalog &catalog)
{
	/*
	Lagrer som:
	TDT4102
	C++
	TMA4100
	Matematikk 1

	*/
	for (auto &course : catalog.courses)
	{
		os << course.first << std::endl << course.second << std::endl;
	}
	return os;
}

std::ifstream &operator>>(std::ifstream &is, CourseCatalog &catalog)
{
	std::string courseCode;
	std::string courseName;

	while (std::getline(is, courseCode) && std::getline(is, courseName))
	{
		catalog.addCourse(courseCode, courseName);
	}
	return is;
}
