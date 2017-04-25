#include "MorseCode.h"
#include <ostream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("morse.txt");
	MorseCode morse_code(fin);

	cout << morse_code.encode("A A") << endl;
	fin.close();

	system("PAUSE");
}
