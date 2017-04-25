#include "MorseCode.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

MorseCode::MorseCode(std::ifstream& in)
{
	string line;
	while(getline(in, line))
	{
		morseByLetter[line[0]] = line.substr(1);
	}
}

std::string MorseCode::decode(std::string code)
{
	return code;
}

std::string MorseCode::encode(std::string charString)
{
	stringstream s;
	for (int i = 0; i < charString.size(); i++)
	{
		s << morseByLetter[tolower(charString[i])];
	}
	return s.str();
}

void MorseCode::buildTree(char key)
{
}
