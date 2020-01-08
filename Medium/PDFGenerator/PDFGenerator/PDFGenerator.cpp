// PDFGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <hpdf.h>
#include <hpdf_types.h>

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
	int start_int = 0;
	int end_int;

	unsigned int place = 0;
	bool cycling = true;
	while (cycling) {
		char c = str[place];

		//std::cout << c;
		
		if (place == str.size())
		{
			vec.push_back(str.substr(start_int, place - start_int));
			cycling = false;
		}
		else if (c < 0)
		{
			place++;
			cycling = true;
		}
		else if (isspace(c))
		{
			vec.push_back(str.substr(start_int, place - start_int));
			place++;
			start_int = place;
		}
		else
		{
			place++;
		}
	}

	//std::cout << std::endl;

	//if (temp_word != "") { vec.push_back(temp_word); }

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

void pageWrapText(HPDF_Page page, HPDF_Font font, int height, std::vector<std::vector<std::string>> txt_data)
{
	int ypos = HPDF_Page_GetHeight(page) - 60;
	int write_width = HPDF_Page_GetWidth(page) - 120;
	std::string first_word;
	std::string print_line = "";
	std::string temp_line = "";
	int len;
	bool reading_text = true;
	int place = 0;

	// Reading the original text vector
	while (reading_text)
	{
		// Stops if the next line is beyond the size of the txt_data
		if (place >= txt_data.size())
		{
			reading_text = false;
		}
		else
		{
			std::vector<std::string> line = txt_data[place];
			bool is_reading_line = true;
			int line_place = 0;
			
			// During the reading of the line
			while (is_reading_line)
			{
				// If line is empty, doesn't print anything and just skips to the next spot.
				if (line.size() <= 0)
				{
					ypos -= height;
					is_reading_line = false;
					place++;
				}
				// If line_place has reached the end of the line
				else if (line_place == line.size())
				{
					is_reading_line = false;
					place++;
				}
				// If line is not empty and we have not yet reached the end
				else
				{
					// Gets the first word in the line
					first_word = line[line_place];
					// If the first word is longer than the width of the page, chops up the word between lines.
					if (HPDF_Page_TextWidth(page, first_word.c_str()) > write_width)
					{
						bool cycling = true;
						while (cycling)
						{
							len = HPDF_Page_MeasureText(page, first_word.c_str(), HPDF_Page_GetWidth(page) - 120,
								HPDF_FALSE, NULL);
							temp_line = first_word.substr(0, len);

							HPDF_Page_BeginText(page);
							HPDF_Page_SetFontAndSize(page, font, height);
							HPDF_Page_MoveTextPos(page, 60, ypos);
							HPDF_Page_ShowText(page, temp_line.c_str());
							HPDF_Page_EndText(page);

							ypos -= height;

							std::cout << temp_line << std::endl;

							if (len >= first_word.length())
							{
								cycling = false;
								print_line = "";
								temp_line = "";
								first_word = "";
							}
							else
							{
								first_word = first_word.substr(len);
							}
						}

						line_place++;
					}
					// If the first word is not longer than the page width
					else
					{
						print_line = first_word;
						line_place++;
						bool cycling = true;

						/*Cycles through words in the line until the length of the line is too great
						or the line runs out.*/
						while (cycling)
						{
							// In the event that we run out of line.
							if (line_place >= line.size())
							{
								HPDF_Page_BeginText(page);
								HPDF_Page_SetFontAndSize(page, font, height);
								HPDF_Page_MoveTextPos(page, 60, ypos);
								HPDF_Page_ShowText(page, print_line.c_str());
								HPDF_Page_EndText(page);

								ypos -= height;

								cycling = false;
								is_reading_line = false;
								place++;
							}
							else
							{
								std::string word = line[line_place];
								temp_line = print_line + " " + word;
								len = HPDF_Page_TextWidth(page, temp_line.c_str());

								// In the event that the length of the line is too great.
								if (len > write_width)
								{
									HPDF_Page_BeginText(page);
									HPDF_Page_SetFontAndSize(page, font, height);
									HPDF_Page_MoveTextPos(page, 60, ypos);
									HPDF_Page_ShowText(page, print_line.c_str());
									HPDF_Page_EndText(page);

									ypos -= height;

									print_line = "";
									temp_line = word + " ";
									line_place++;

									cycling = false;
								}
								// Updates print_line and moves on to the next word.
								else
								{
									print_line = temp_line;
									line_place++;
								}
							}
						}
					}
				}
			}
		}
	}
}

void pdfWrapText(HPDF_Doc pdf, HPDF_Font font, int height, std::vector<std::vector<std::string>> txt_data)
{
	HPDF_Page page;
	page = HPDF_AddPage(pdf);
	HPDF_Page_SetFontAndSize(page, font, 12);
	HPDF_Page_SetTextRenderingMode(page, HPDF_FILL);
	int ypos = HPDF_Page_GetHeight(page) - 60;
	int write_width = HPDF_Page_GetWidth(page) - 120;
	std::string first_word;
	std::string print_line = "";
	std::string temp_line = "";
	int len;
	bool reading_text = true;
	int place = 0;

	// Reading the original text vector
	while (reading_text)
	{
		// Stops if the next line is beyond the size of the txt_data
		if (place >= txt_data.size())
		{
			reading_text = false;
		}
		else
		{
			std::vector<std::string> line = txt_data[place];
			bool is_reading_line = true;
			int line_place = 0;

			// During the reading of the line
			while (is_reading_line)
			{
				// If line is empty, doesn't print anything and just skips to the next spot.
				if (line.size() <= 0)
				{
					ypos -= height;

					// CHECKING THAT WE DON'T GO OFF PAGE
					if (ypos < 60)
					{
						page = HPDF_AddPage(pdf);
						HPDF_Page_SetFontAndSize(page, font, 12);
						HPDF_Page_SetTextRenderingMode(page, HPDF_FILL);
						ypos = HPDF_Page_GetHeight(page) - 60;
					}

					is_reading_line = false;
					place++;
				}
				// If line_place has reached the end of the line
				else if (line_place == line.size())
				{
					if (!print_line.empty())
					{
						HPDF_Page_BeginText(page);
						HPDF_Page_SetFontAndSize(page, font, height);
						HPDF_Page_MoveTextPos(page, 60, ypos);
						HPDF_Page_ShowText(page, print_line.c_str());
						HPDF_Page_EndText(page);

						ypos -= height;

						// CHECKING THAT WE DON'T GO OFF PAGE
						if (ypos < 60)
						{
							page = HPDF_AddPage(pdf);
							HPDF_Page_SetFontAndSize(page, font, 12);
							HPDF_Page_SetTextRenderingMode(page, HPDF_FILL);
							ypos = HPDF_Page_GetHeight(page) - 60;
						}
					}

					is_reading_line = false;
					place++;
				}
				// If line is not empty and we have not yet reached the end
				else
				{
					// Gets the first word in the line
					first_word = line[line_place];
					// If the first word is longer than the width of the page, chops up the word between lines.
					if (HPDF_Page_TextWidth(page, first_word.c_str()) > write_width)
					{
						bool cycling = true;
						while (cycling)
						{
							len = HPDF_Page_MeasureText(page, first_word.c_str(), HPDF_Page_GetWidth(page) - 120,
								HPDF_FALSE, NULL);
							temp_line = first_word.substr(0, len);

							HPDF_Page_BeginText(page);
							HPDF_Page_SetFontAndSize(page, font, height);
							HPDF_Page_MoveTextPos(page, 60, ypos);
							HPDF_Page_ShowText(page, temp_line.c_str());
							HPDF_Page_EndText(page);

							ypos -= height;

							// CHECKING THAT WE DON'T GO OFF PAGE
							if (ypos < 60)
							{
								page = HPDF_AddPage(pdf);
								HPDF_Page_SetFontAndSize(page, font, 12);
								HPDF_Page_SetTextRenderingMode(page, HPDF_FILL);
								ypos = HPDF_Page_GetHeight(page) - 60;
							}

							if (len >= first_word.length())
							{
								cycling = false;
								print_line = "";
								temp_line = "";
								first_word = "";
							}
							else
							{
								first_word = first_word.substr(len);
							}
						}

						line_place++;
					}
					// If the first word is not longer than the page width
					else
					{
						print_line = first_word;
						line_place++;
						bool cycling = true;

						/*Cycles through words in the line until the length of the line is too great
						or the line runs out.*/
						while (cycling)
						{
							// In the event that we run out of line.
							if (line_place >= line.size())
							{
								HPDF_Page_BeginText(page);
								HPDF_Page_SetFontAndSize(page, font, height);
								HPDF_Page_MoveTextPos(page, 60, ypos);
								HPDF_Page_ShowText(page, print_line.c_str());
								HPDF_Page_EndText(page);

								ypos -= height;

								// CHECKING THAT WE DON'T GO OFF PAGE
								if (ypos < 60)
								{
									page = HPDF_AddPage(pdf);
									HPDF_Page_SetFontAndSize(page, font, 12);
									HPDF_Page_SetTextRenderingMode(page, HPDF_FILL);
									ypos = HPDF_Page_GetHeight(page) - 60;
								}

								cycling = false;
								is_reading_line = false;
								place++;
							}
							else
							{
								std::string word = line[line_place];
								temp_line = print_line + " " + word;
								len = HPDF_Page_TextWidth(page, temp_line.c_str());

								// In the event that the length of the line is too great.
								if (len > write_width)
								{
									HPDF_Page_BeginText(page);
									HPDF_Page_SetFontAndSize(page, font, height);
									HPDF_Page_MoveTextPos(page, 60, ypos);
									HPDF_Page_ShowText(page, print_line.c_str());
									HPDF_Page_EndText(page);

									ypos -= height;

									// CHECKING THAT WE DON'T GO OFF PAGE
									if (ypos < 60)
									{
										page = HPDF_AddPage(pdf);
										HPDF_Page_SetFontAndSize(page, font, 12);
										HPDF_Page_SetTextRenderingMode(page, HPDF_FILL);
										ypos = HPDF_Page_GetHeight(page) - 60;
									}

									print_line = "";
									temp_line = word + " ";

									cycling = false;
								}
								// Updates print_line and moves on to the next word.
								else
								{
									print_line = temp_line;
									line_place++;
								}
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
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

			//HPDF_Page page;
			HPDF_Font font;

			//page = HPDF_AddPage(pdf);
			font = HPDF_GetFont(pdf, "Courier", NULL);
			//HPDF_Page_SetFontAndSize(page, font, 12);
			
			//HPDF_Page_SetTextRenderingMode(page, HPDF_FILL);
			//HPDF_Page_BeginText(page);
			//HPDF_Page_EndText(page);
			//HPDF_Page_TextOut(page, 60, 800, "Hello! This is working!");
			
			std::vector<std::vector<std::string>> file_vec = para_split(file_content);

			//pageWrapText(page, font, 12, file_vec);
			pdfWrapText(pdf, font, 12, file_vec);

			//std::cout << "Width: " << HPDF_Page_GetWidth(page) << std::endl;
			//std::cout << "Height: " << HPDF_Page_GetHeight(page) << std::endl;

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
