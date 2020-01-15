#include "StringAnalyze.h"

int main()
{
    std::cout << "Word Counter Application" << std::endl;

	std::string line;

	while (true) {
		std::cout << "If you would like me to read the text file, preface the name of the file with 'text'." << std::endl << 
			"If you would like to exit the program, type 'exit'." << std::endl <<
			"Otherwise, enter a string: " << std::endl << std::endl;

		getline(std::cin, line);
		std::pair<std::vector<std::string>, std::map<std::string, int>> values;
		StringAnalyze s;

		std::transform(line.begin(), line.end(), line.begin(),
			[](unsigned char c) { return std::tolower(c); });
		/*line.erase(std::remove_if(line.begin(), line.end(),
			[](auto const& c) -> bool { return !std::isalnum(c); }), line.end());*/

		if (line.compare("exit") == 0) {
			std::cout << "Shutting down..." << std::endl;
			return 1;
		}
		else if (line.size() > 4 && line.substr(0, 5).compare("text ") == 0) {
			std::string fileName = line.substr(5, line.size());
			std::string newLine;
			std::ifstream myfile(fileName);
			if (myfile.is_open())
			{
				auto start = std::chrono::high_resolution_clock::now();
				std::string target;
				while (getline(myfile, newLine))
				{
					std::transform(newLine.begin(), newLine.end(), newLine.begin(),
						[](unsigned char c) { return std::tolower(c); });

					if (target.empty()) {
						target = newLine;
					}
					else {
						target += " " + newLine;
					}
				}
				myfile.close();

				values = s.Analyze(target);
				s.AnalysisReader(values);
				std::cout << std::endl;
				auto stop = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
				std::cout << "Program took " << duration.count() << " microseconds." << std::endl << std::endl;
			}
			else {
				std::cout << "Sorry, file does not exist." << std::endl << std::endl;
			}
		}
		else {
			auto start = std::chrono::high_resolution_clock::now();
			values = s.Analyze(line);
			s.AnalysisReader(values);
			std::cout << std::endl;
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			std::cout << "Program took " << duration.count() << " microseconds." << std::endl << std::endl;
		}
	}

	return 1;
}