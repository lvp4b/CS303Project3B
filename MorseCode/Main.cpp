// Lia Vang
// lvp4b@mail.umkc.edu
// Project 3B
// CS 303

#include "MorseCode.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("morse.txt");
	const MorseCode morse_code(fin);

	const string word = "The five boxing wizards jump quickly";
	string morse = morse_code.encode(word);
	cout << "Words to encode: " << word << endl;
	cout << morse << endl << endl;

	cout << "Morse to decode: " << morse << endl;
	cout << morse_code.decode(morse) << endl;

	fin.close();

	system("PAUSE");
}
