#pragma once

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>

#define FORMULA_LENGTH_EXCEEDS_LIMIT	6
#define UNKNOWN_ELEMENT_IN_FORMULA		5
#define INVALID_BRACKETS				4
#define ERROR_WHILE_INITIALIZING_REGEX	3
#define NO_FORMULA_SPECIFIED			2
#define GENERAL_ERROR					1
#define SUCCESS							0
#define MAX_FORMULA_LENGTH				255

using namespace std;

namespace FormulaParserUWPComponent
{
struct ltstr
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};

class FormulaParser
{
	public:
		FormulaParser();
        string GetLastError();
        map<string, double> ParseElements(int *errorCode);
        int SetFormula(string moleculeFormula, string* formulaSummary, double* moleMass);
	private:
		static map<const char*, double, ltstr> periodicTableOfElements;
        int AscIICharsFromString(string source, char** destination);
        string StringFromAscIIChars(const char* chars);
        void SetLastError(string error);
		double calculatedMoleMass;
        string lastError;
		char* formula;
};
}
