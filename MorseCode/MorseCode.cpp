#include "MorseCode.h"
#include "MorseTree.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

MorseCode::MorseCode(ifstream& in)
{
	string line;

	// Read and process each line
	while (getline(in, line))
	{
		// line: <letter><morse code>
		morseByLetter[line[0]] = line.substr(1);
		tree.insertNode(line[0], line.substr(1));
	}
}

string MorseCode::decode(const string& morseCode) const
{
	string result;
	string code;
	stringstream stream(morseCode);

	// Split message by whitespace
	while (stream >> code)
	{
		result += tree.getLetter(code);

		// Add a space if the next symbol is empty
		stream.seekg(1, ios_base::cur);
		if (stream.peek() == ' ')
		{
			result += ' ';
		}
	}
	return result;
}

string MorseCode::encode(const string& message) const
{
	stringstream stream;
	for (int i = 0; i != message.size(); i++)
	{
		stream << " ";

		auto morse = morseByLetter.find(tolower(message[i]));
		if (morse != morseByLetter.end())
		{
			stream << morse->second;
		}
	}
	return stream.str().substr(1);
}
