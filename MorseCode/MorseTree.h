#pragma once
#include <string>

// Represents a node within the morse code tree
struct Node
{
	Node() : left(nullptr), right(nullptr) {}
	std::string letter;
	Node* left;
	Node* right;
};

// Represents a tree that maps morse code into letters
class MorseTree
{
public:
	// Instantiates a new morse code tree
	MorseTree();

	// Adds a letter with the specified morse code representation into the tree
	void insertNode(char letter, const std::string& morseCode);

	// Gets the letter of the specified morse code
	std::string getLetter(const std::string& morseCode) const;

	// Frees the memory associated with the morse code tree
	~MorseTree();
private:
	Node* root;
};

