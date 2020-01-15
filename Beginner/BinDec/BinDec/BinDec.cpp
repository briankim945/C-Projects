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