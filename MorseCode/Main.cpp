#include "MorseCode.h"
#include <fstream>
#include <iostream>
#include <string>
#include "MorseTree.h"
using namespace std;

int main()
{
	ifstream fin("morse.txt");
	MorseCode morse_code(fin);

	cout << morse_code.encode("hello") << endl;
	cout << morse_code.encode("h") << endl;
	cout << morse_code.decode("... --- ...") << endl;

	//tree.insertNode('.', fin.get());
	fin.close();

	system("PAUSE");
}
