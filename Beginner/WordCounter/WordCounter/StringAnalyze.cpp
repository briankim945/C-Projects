#include "StringAnalyze.h"

std::pair<std::vector<std::string>, std::map<std::string, int>> StringAnalyze::Analyze(std::string s)
{
	std::vector<std::string> names;
	std::map<std::string, int> mapOut;

	// BORROWED aND ADAPTED FROM STACKOVERFLOW: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c

	std::string delimiter1 = " ";
	std::string delimiter2 = "\n";

	size_t pos = 0;
	std::string token;
	while (((pos = s.find(delimiter1)) != std::string::npos) ||
		((pos = s.find(delimiter2)) != std::string::npos)) {
		token = s.substr(0, pos);
		token.erase(std::remove_if(token.begin(),
			token.end(), [](char c) {return !std::isalnum(c); }), token.end());

		// std::find(std::begin(names), std::end(names), token)
		if (mapOut.find(token) != mapOut.end()) {
			int currVal = mapOut.find(token)->second;
			mapOut.erase(token);
			mapOut.insert({token, currVal + 1});
		}
		else {
			mapOut.insert({ token, 1 });
			names.push_back(token);
		}

		if (s.substr(pos, pos + 1).compare(" ") == 0) {
			s.erase(0, pos + delimiter1.length());
		}
		else {
			s.erase(0, pos + delimiter2.length());
		}
	}

	s.erase(std::remove_if(s.begin(), s.end(), [](char c) {return !std::isalnum(c); }), s.end());

	if (mapOut.find(s) != mapOut.end()) {
		int currVal = mapOut.find(s)->second;
		mapOut.erase(s);
		mapOut.insert({ s, currVal + 1 });
	}
	else {
		mapOut.insert({ s, 1 });
		names.push_back(s);
	}

	// END BORROW

	std::sort(names.begin(), names.end());

	return std::pair<std::vector<std::string>, std::map<std::string, int>>(names, mapOut);
}

int StringAnalyze::AnalysisReader(std::pair<std::vector<std::string>, std::map<std::string, int>> values)
{
	std::vector<std::string> names = values.first;
	std::map<std::string, int>dict = values.second;
	for (int i = 0; i < names.size(); i++) {
		std::cout << names[i] << ": " << dict.find(names[i])->second << std::endl;
	}
	return 0;
}
