#include "Vowels.h"


vowels Vowels::VowelCounter(std::string word)
{
	vowels vList = vowels();
	vList.numA = 0;
	vList.numE = 0;
	vList.numI = 0;
	vList.numO = 0;
	vList.numU = 0;

	for (int i = 0; i < word.size(); i++) {
		char newLet = word[i];
		if (tolower(newLet) == 'a') {
			vList.numA++;
		}
		else if (tolower(newLet) == 'e') {
			vList.numE++;
		}
		else if (tolower(newLet) == 'o') {
			vList.numO++;
		}
		else if (tolower(newLet) == 'i') {
			vList.numI++;
		}
		else if (tolower(newLet) == 'u') {
			vList.numU++;
		}
	}

	return vList;
}
