#include <algorithm>
#include <iostream>
#include <string>

bool notalpha(char c) {
	return !(isalpha(c));
}

int main()
{
    std::cout << "Palindrome Check Application" << std::endl << std::endl;

	while (true) {
		std::string word;
		std::string wordRev;
		std::cout << "Enter a word or string of words and we'll tell you if it's a palindrome, ignoring non-alphabetic characters and case (to exit, type 'exit'): " << std::endl;
		getline(std::cin, word);

		if (word.compare("exit") == 0) {
			return 1;
		}

		// remove all non-alphabetic letters
		word.erase(std::remove_if(word.begin(), word.end(), notalpha), word.end());
		for (int i = 0; i < word.size(); i++) {
			word[i] = tolower(word[i]);
		}

		//Failed Method
		/*for (int i = 0; i < word.size(); i++) {
			if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
				char newChar = tolower(word[i]);
				word[i] = newChar;
			}
			else {
				word[i] = '\0';
			}
		}*/


		wordRev = word;
		std::reverse(wordRev.begin(), wordRev.end());

		if (word.compare(wordRev) == 0) {
			std::cout << std::endl << "This is a palindrome!" << std::endl << std::endl;
		}
		else {
			std::cout << "This is not a palindrome." << std::endl << std::endl;
		}
	}
}