// PDFGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <hpdf.h>
#include <hpdf_types.h>
//#include <hpdf_error.h>
//#include <hpdf_doc.h>
//#include <setjmp.h>

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <sstream>


void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data)
{
	/* throw exception when an error has occured */
	printf("ERROR: error_no=%04X, detail_no=%d\n", (unsigned int)error_no,
		(int)detail_no);
	/*try
	{
		throw "HPDF Error";
	}
	catch (std::string msg)
	{
		std::cout << msg << std::endl;
	}*/
	throw std::exception();
}

std::vector<std::string> string_split(std::string str)
{
	std::vector<std::string> vec;
	std::string temp_word = "";

	for (unsigned int i = 0; i < str.length(); i++) {
		char c = str[i];

		//std::cout << c;

		if (c < 0)
		{
			std::string s(1, c);
			//std::cout << "Getting this write: " << s << std::endl;
			temp_word += s;
		}
		else if (isspace(c))
		{
			vec.push_back(temp_word);
			temp_word = "";
		}
		else
		{
			temp_word += c;
		}
	}

	//std::cout << std::endl;

	if (temp_word != "") { vec.push_back(temp_word); }

	return vec;
}

std::vector<std::vector<std::string>> para_split(std::string str)
{
	std::vector<std::vector<std::string>> vec;

	std::string line;

	std::stringstream ss(str);

	while (std::getline(ss, line, '\n')) {
		vec.push_back(string_split(line));
	}

	return vec;
}

void printWrapText(HPDF_Page page, HPDF_Font font, int height, std::vector<std::vector<std::string>> txt_data)
{
	/*
	bool page_incomplete = true;
	
	while (page_incomplete)
	{
		std::string newline;
	}*/

	int ypos = 800;
	int char_height = HPDF_Font_GetCapHeight(font);

	for (std::vector<std::string> line : txt_data) {
		std::string print_line =  "";
		for (std::string word : line) {
			print_line += word + " ";
		}

		//std::cout << print_line << std::endl;
		//std::cout << char_height << std::endl;

		/*
		HPDF_Page_SetTextRenderingMode(pdf, HPDF_FILL);
		HPDF_Page_BeginText(pdf);
		HPDF_Page_TextOut(pdf, 0, ypos, print_line.c_str());
		HPDF_Page_EndText(pdf);*/

		HPDF_Page_MoveTextPos(page, 0, ypos);
		HPDF_Page_SetFontAndSize(page, font, height);
		HPDF_Page_ShowText(page, print_line.c_str());

		ypos -= height;
	}

	/*
	std::cout << HPDF_Font_MeasureText(font, (const HPDF_BYTE*) txt_data, (HPDF_UINT) ((std::string) txt_data).length(), (HPDF_REAL) 492,
		(HPDF_REAL) 12, (HPDF_REAL) 0, (HPDF_REAL) 1, HPDF_FALSE, NULL) <<
		std::endl;*/
}

int main()
{
	// TESTING STRING SPLITTER
	/*
	std::vector<std::vector<std::string>> vec = 
		para_split(
			"Hello darkness my old friend.\nThis is the beginning of the end."
		);
	for (std::vector<std::string> line : vec) {
		std::cout << "ONE LINE" << std::endl;
		for (std::string word : line) {
			std::cout << word << std::endl;
		}
	}*/

	std::string file_name;
	std::string file_content;

    std::cout << "Enter the path to a txt file, and we'll convert it to a pdf for you!" << std::endl;
	getline(std::cin, file_name);

	std::regex re_1("(.*)(\.txt)");
	if (regex_match(file_name, re_1)) {
		HPDF_Doc pdf = HPDF_New((HPDF_Error_Handler) error_handler, NULL);

		/* set compression mode */
		HPDF_SetCompressionMode(pdf, HPDF_COMP_ALL);
		
		if (!pdf) {
			printf("ERROR: cannot create pdf object.\n");
			return 1;
		}

		std::ifstream txt_file;

		txt_file.open(file_name);

		if (txt_file.is_open()) {
			std::string line;

			while (getline(txt_file, line)) {
				file_content += line + "\n";
			}

			txt_file.close();

			HPDF_Page page;
			HPDF_Font font;

			page = HPDF_AddPage(pdf);
			font = HPDF_GetFont(pdf, "Courier", NULL);
			HPDF_Page_SetFontAndSize(page, font, 12);

			std::cout << HPDF_Font_GetXHeight(font) << std::endl;
			
			HPDF_Page_SetTextRenderingMode(page, HPDF_FILL);
			HPDF_Page_BeginText(page);
			//HPDF_Page_TextOut(page, 60, 800, "Hello! This is working!");
			
			std::vector<std::vector<std::string>> file_vec = para_split(file_content);
			/*
			HPDF_Page_MoveTextPos(page, 0, 800);
			HPDF_Page_SetFontAndSize(page, font, 12);
			HPDF_Page_ShowText(page, file_content.c_str());*/

			//SEEING IF THIS WORKS
			
			int height = 12;

			int ypos = HPDF_Page_GetHeight(page) - 60;
			int char_height = HPDF_Font_GetCapHeight(font);
			/*
			std::string print_line = "";
			for (std::string word : file_vec[0]) {
				print_line += word + " ";
			}

			std::cout << print_line << std::endl;

			for (int i = 0; i < 8; i++)
			{
				HPDF_Page_TextOut(page, 60, ypos - (i * 100), print_line.c_str());
			}*/

			
			for (std::vector<std::string> line : file_vec) {
				std::string print_line = "";
				for (std::string word : line) {
					print_line += word + " ";
				}

				std::cout << print_line << std::endl;
				std::cout << char_height << std::endl;

				std::cout << "printline: " << print_line << std::endl;
				std::cout << "xpos: " << 0 << std::endl;
				std::cout << "ypos: " << ypos << std::endl;
				
				HPDF_Page_MoveTextPos(page, 0, ypos);
				HPDF_Page_SetFontAndSize(page, font, height);
				HPDF_Page_ShowText(page, print_line.c_str());

				ypos -= height;
			}

			//printWrapText(pdf, font, 12, file_vec);

			HPDF_Page_EndText(page);

			//std::cout << file_content << std::endl;
			
			std::cout << "Width: " << HPDF_Page_GetWidth(page) << std::endl;
			std::cout << "Height: " << HPDF_Page_GetHeight(page) << std::endl;

			try
			{
				HPDF_SaveToFile(pdf, "out.pdf");
			}
			catch (std::exception e)
			{
				std::cout << "Problem writing to file." << std::endl;
			}
		}
		else {
			std::cout << "We could not open the file." << std::endl;
		}

		HPDF_Free(pdf);
	}
	else {
		std::cout << "We do not support this file format." << std::endl;
	}
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
