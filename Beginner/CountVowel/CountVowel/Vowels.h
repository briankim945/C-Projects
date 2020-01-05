#pragma once

#include "CountVowel.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

class Vowels
{
private:
	//template <typename Out>;
	//void split(const std::string& s, char delim, Out result);
	//std::vector<std::string> split(const std::string& s, char delim);
public:
	vowels VowelCounter(std::string word);
	//vowels VowelCopy(vowels v);
};

