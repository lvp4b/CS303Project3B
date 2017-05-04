#include "MorseTree.h"
#include <iostream>
#include <stack>

using namespace std;

MorseTree::MorseTree()
{
	root = new Node();
}

void MorseTree::insertNode(char letter, const string& morseCode)
{
	Node* current = root;

	// Read each morse code symbol
	for (int i = 0; i <= morseCode.length(); ++i)
	{
		// Dots traverse to the left child in the subtree
		if (morseCode[i] == '.')
		{
			// Ensure left child exists
			if (current->left == nullptr)
			{
				current->left = new Node();
			}
			current = current->left;
		}

		// Dashes traverse to the right child in the subtree
		else if (morseCode[i] == '-' || morseCode[i] == '_')
		{
			// Ensure right child exists
			if (current->right == nullptr)
			{
				current->right = new Node();
			}
			current = current->right;
		}
	}

	current->letter = tolower(letter);
}

string MorseTree::getLetter(const string& morseCode) const
{
	Node* current = root;

	for (int i = 0; i <= morseCode.length(); ++i)
	{
		// Returns a space if current node doesn't exist
		if (current == nullptr)
		{
			return " ";
		}
		else if (morseCode[i] == '.')
		{
			current = current->left;
		}
		else if (morseCode[i] == '-' || morseCode[i] == '_')
		{
			current = current->right;
		}
	}

	return current->letter;
}

MorseTree::~MorseTree()
{
	// Delete each node using a pre-order traversal
	stack<Node*> stack;
	stack.push(root);
	while (!stack.empty())
	{
		Node* current = stack.top();
		stack.pop();

		if (current->right != nullptr)
		{
			stack.push(current->right);
		}
		if (current->left != nullptr)
		{
			stack.push(current->left);
		}

		delete current;
	}
}
