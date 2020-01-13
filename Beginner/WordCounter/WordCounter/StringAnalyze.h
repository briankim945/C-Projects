#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iterator> 
#include <map> 
#include <vector> 
#include <utility>
#include <algorithm>
#include <cctype>
#include <chrono>

class StringAnalyze
{
public:
	std::pair<std::vector<std::string>, std::map<std::string, int>> Analyze(std::string s);
	int AnalysisReader(std::pair<std::vector<std::string>, std::map<std::string, int>> values);
};

