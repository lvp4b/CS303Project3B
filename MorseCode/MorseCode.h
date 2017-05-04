#pragma once
#include <map>
#include "BTNode.h"
#include "MorseTree.h"

struct Tree
{
	Tree();
	char letter;
	Tree *left;
	Tree *right;
};

class MorseCode
{
public:
	MorseCode(std::ifstream& in);

	std::string decode(std::string message);

	std::string encode(std::string charString);

private:
	std::map<char, std::string> morseByLetter;
	void buildTree(char key);
	MorseTree tree;
};

