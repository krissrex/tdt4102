/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
V�r 2016
�ving 8
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 1a
void saveWordsToFile(const char* path);
// 1b
void copyFileWithLineNumbers(const char* inPath, const char* outPath);

int main() 
{
	//saveWordsToFile("output.txt");
	copyFileWithLineNumbers("input.txt", "inputLineNumbers.txt");
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

	// getline stopper p� eof, og returnerer input. 
	// input sin "operator bool" gir false om den er i fail state, men ikke eof. 
	// Dermed m� den faile neste omgang, n�r den er p� eof.
	// S� det skal i teori bli en matcho m�te
	while (getline(input, line))
	{
		output << lineNumber++ << " " << line << endl;
	}

	input.close();
	output.close();
}
