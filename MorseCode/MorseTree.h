#pragma once
#include <vector>

struct Node
{
	Node() : left(nullptr), right(nullptr) {}
	std::string letter;
	Node * left;
	Node * right;
};

class MorseTree
{
public:
	MorseTree();
	void insertNode(char letter, const std::string& morseCode);
	std::string getLetter(std::string morseCode);
private:
	Node* root;
};

