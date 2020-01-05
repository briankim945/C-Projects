// CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Calculator.h"
#include <iostream>

using namespace std;

int main()
{
	double x = 0.0;
	double y = 0.0;
	double result = 0.0;
	char op = '+';

	cout << "Calculator Console Application" << endl << endl;
	cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b" << endl;
	cout << "Enter a non-format to end the program." << endl << endl;

	Calculator c;
	while (true) {
		if (cin.fail()) {
			break;
		}
		else {
			cin >> x >> op >> y;
			if (op == '/' && y == 0) {
				cout << "Division by 0 exception" << endl;
				continue;
			}
			else {
				result = c.Calculate(x, op, y);
			}
			cout << "Result is: " << result << endl;
		}
	}

	return 0;
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
