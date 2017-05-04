#include "MorseTree.h"
#include <iostream>

MorseTree::MorseTree()
{
	root = new Node;
}

void MorseTree::insertNode(char letter, const std::string& morseCode)
{
	Node *currentRoot = root;
	for (int i = 0; i <= morseCode.length(); ++i)
	{
		if(morseCode[i] == '.')
		{
			if (currentRoot->left == nullptr)
			{
				currentRoot->left = new Node;
			}
			currentRoot = currentRoot->left;
		}
		else if (morseCode[i] == '-' || morseCode[i] == '_')
		{
			if(currentRoot->right == nullptr)
			{
				currentRoot->right = new Node;
			}
			currentRoot = currentRoot->right;
		}
	}
	currentRoot->letter = letter;
}

std::string MorseTree::getLetter(std::string morseCode)
{
	Node * currentNode = root;
	for (int i = 0; i <= morseCode.length(); ++i)
	{
		if(currentNode == nullptr)
		{
			return "";
		}
		else if (morseCode[i] == '.')
		{
			currentNode = currentNode->left;
		}
		else if (morseCode[i] == '-' || morseCode[i] == '_')
		{
			currentNode = currentNode->right;
		}
	}
	return currentNode->letter;
}
