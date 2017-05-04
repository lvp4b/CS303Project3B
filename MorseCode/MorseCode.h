#pragma once
#include <map>
#include "MorseTree.h"

// Processes morse code
class MorseCode
{
public:
	// Initializes this processor using the morse code mapping from file input
	MorseCode(std::ifstream& in);

	// Decodes a morse code message
	std::string decode(const std::string& morseCode) const;

	// Encodes a string into morse code
	std::string encode(const std::string& message) const;

private:
	std::map<char, std::string> morseByLetter;
	MorseTree tree;
};
