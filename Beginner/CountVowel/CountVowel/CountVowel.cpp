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