// BinDec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Calculator.h"
#include <iostream>

using namespace std;

int main()
{
	char choice = 'a';
	cout << "Binary-Decimal Conversion Application" << endl << endl;

	while (true) {
		cout << "Choose to convert to either binary or decimal (b or d), or enter 'e' to exit:" << endl;
		cin >> choice;
		if (cin.fail()) {
			cout << "Invalid option. Please try again:" << endl;
			continue;
		}
		else {
			Calculator c;
			int value = 0;
			int result = 0;
			switch (choice) {
			case 'b':
				cout << "Enter a decimal number to convert to binary:" << endl;
				cin >> value;
				result = c.BinCalc(value);
				cout << result << endl << endl;
				break;
			case 'd':
				cout << "Enter a binary number to convert to decimal:" << endl;
				cin >> value;
				result = c.DecCalc(value);
				cout << result << endl << endl;
				break;
			case 'e':
				cout << "Exiting program" << endl << endl;
				return 0;
			default:
				cout << "That is not a valid choice" << endl << endl;
				break;
			}
		}
	}

	return 0;
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
