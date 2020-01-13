// CountVowel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CountVowel.h"
#include "Vowels.h"

int main()
{
	std::string searchString = "";

    std::cout << "Vowel Search Application" << std::endl << std::endl;

	while (true) {
		Vowels v;
		vowels vArr;
		std::cout << "Enter a word or sentence (to quit, type 'quit'): " << std::endl;
		//std::cin.ignore();
		std::getline(std::cin, searchString);
		if (searchString.compare("quit") == 0) {
			return 1;
		}
		vArr = v.VowelCounter(searchString);

		for (int j = 0; j < 5; j++) {
			if (j == 0) {
				std::cout << "a: " << vArr.numA << std::endl;
			}
			else if (j == 1) {
				std::cout << "e: " << vArr.numE << std::endl;
			}
			else if (j == 2) {
				std::cout << "i: " << vArr.numI << std::endl;
			}
			else if (j == 3) {
				std::cout << "o: " << vArr.numO << std::endl;
			}
			else if (j == 4) {
				std::cout << "u: " << vArr.numU << std::endl << std::endl;
			}
		}
	}

	return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
