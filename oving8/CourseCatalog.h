#pragma once

#include <map>
#include <string>
#include <fstream>

class CourseCatalog
{
public:
	CourseCatalog();
	~CourseCatalog();

	// 1a
	void printCourses() const;
	// 1a
	void addCourse(std::string courseCode, std::string courseName);
	// 1a
	void removeSubject(std::string subjectCode);
	// 1a 
	// Gir navnet, eller tom streng om det ikke finnes
	// Fixme: Teller dette som "beskrivelsen til et gitt emne"?
	std::string getSubjectName(std::string subjectCode) const;

	friend std::ofstream &operator<<(std::ofstream &os, const CourseCatalog &catalog);
	friend std::ifstream &operator>>(std::ifstream &is, CourseCatalog &catalog);


private:
	std::map<std::string, std::string> courses;
};

// Mini-bug: takler ikke navn med linjeskift
std::ofstream &operator<<(std::ofstream &os, const CourseCatalog &catalog);
// Mini-bug: takler ikke navn med linjeskift
std::ifstream &operator>>(std::ifstream &is, CourseCatalog &catalog);
