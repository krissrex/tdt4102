/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 8
*/

#include <iostream>
#include <fstream>
#include <string>

#include "CourseCatalog.h"

using namespace std;

// 1a
void saveWordsToFile(const char* path);
// 1b
void copyFileWithLineNumbers(const char* inPath, const char* outPath);

// 2a
void printCharStatistics(const char* path);

int main() 
{
	//saveWordsToFile("output.txt");
	//copyFileWithLineNumbers("input.txt", "inputLineNumbers.txt");
	//printCharStatistics("bokstavStatistikkInput.txt");

	// 3c
	CourseCatalog catalog;
	catalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	catalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	catalog.addCourse("TMA4100", "Matematikk 1");
	catalog.printCourses();

	/*
	3d
	Emnet TDT4102 blir som oftest bare kalt for «C++» blant studentene. Kan du oppdatere
	emnenavnet i emnekatalogen din ved hjelp av funksjoner du allerede har implementert i
	klassen?

	Fordi addCourse bare bruker courses[code] = name, kan jeg like godt overskrive en eksisterende
	med addCourse.
	*/
	catalog.addCourse("TDT4102", "C++");
	catalog.printCourses();
	
	// 3e
	cout << endl << "Serializing catalog to file" << endl;
	const std::string catalogPath = "catalog.dat";
	ofstream catalogFile{ catalogPath };
	catalogFile << catalog;
	catalogFile.close();

	cout << "Deserializing catalog from file" << endl;
	ifstream catalogInput{ catalogPath };
	CourseCatalog catalogFromFile;
	catalogInput >> catalogFromFile;
	catalogInput.close();
	catalogFromFile.printCourses();


	cin.ignore();
	cin.get();
}

void saveWordsToFile(const char * path)
{
	cout << "Enter words to save to " << path << endl;
	string exitWord = "quit";
	cout << "Type " << exitWord << " to quit" << endl;
	string input;

	// Overskriver filen. Legg ved ios::app for append
	ofstream outfile{ path };


	while (true)
	{
		// cin vil automatisk splitte opp setninger til ord
		cin >> input;
		if (exitWord.compare(input) == 0) {
			break;
		}
		// outfile.write(input.c_str(), input.length());
		outfile << input << endl;
	}

	outfile.close();
}

void copyFileWithLineNumbers(const char * inPath, const char * outPath)
{
	ifstream input{ inPath };
	if (input.fail())
	{
		cout << "Failed to open " << inPath << endl;
		return;
	}

	ofstream output{ outPath };

	string line;
	int lineNumber = 0;

	// getline stopper på eof, og returnerer input. 
	// input sin "operator bool" gir false om den er i fail state, men ikke eof. 
	// Dermed må den faile neste omgang, når den er på eof.
	// Så det skal i teori bli en matcho måte
	while (getline(input, line))
	{
		output << lineNumber++ << " " << line << endl;
	}

	input.close();
	output.close();
}

void printCharStatistics(const char * path)
{
	ifstream input{ path };

	if (input.fail())
	{
		cout << "Failed to read " << path << endl;
		return;
	}

	const int ALPHABET_SIZE = 26;
	int counts[ALPHABET_SIZE]{};

	char letter;
	int totalChars = 0;
	int totalValid = 0;

	while (input >> letter)
	{
		totalChars++;

		letter = tolower(letter);
		int index = letter - 'a';
		if (index < 0 || index >= ALPHABET_SIZE)
		{
			// Må skippe noen, fordi filen inneholder .,()-æøå osv.
			// Mini-bug: unicode kan fylle 2+ chars, så hvis et tegn blir lest som f.eks. aÃ, øker a med 1.
			cout << "Invalid character " << letter << ", skipping." << endl;
			continue;
		}

		totalValid++;
		counts[index]++;
	}

	cout << "Character statistics:" << endl
		 << "Total number of characters: " << totalChars << " (" << totalValid << " valid)" << endl;
	for (size_t i = 0; i < ALPHABET_SIZE; i++)
	{
		cout << (char)('a' + i) << ": " << counts[i] << "\t";
	}
	cout << endl;

	input.close();
}
