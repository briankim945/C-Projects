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