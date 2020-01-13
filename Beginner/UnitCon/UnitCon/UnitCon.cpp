// UnitCon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TempCalc.h"
#include "CurrCalc.h"
#include <iostream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << "Unit Converter Console Application" << endl << endl;

	string choiceIn = "a";
	char choice = 'a';

	while (true) {
		cout << "Select what type of unit to convert:" << endl;
		cout << "(t)emperature, (c)urrency, (e)xit" << endl;
		
		// 'cin >> ws' gets rid off all the '\n' whitespace
		getline(cin >> ws, choiceIn);
		if (cin.fail()) {
			cout << "That is not a valid choice." << endl << endl;
			// get rid of failure state
			cin.clear();
			// get rid of 'bad' characters
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else if (choiceIn.length() != 1) {
			cout << "That is not a valid choice." << endl << endl;
			continue;
		}
		
		vector<char> cstr(choiceIn.c_str(), choiceIn.c_str() + choiceIn.size() + 1);

		choice = cstr[0];
		
		double val = 0.0f;
		char init = 'a';
		char end = 'a';
		string errormsg = "Sorry, there was an error processing your request. Please check your entry";
		
		TempCalc tc;
		CurrCalc cc;

		switch (choice) {
		case 't':
			cout << "Enter in this format: '19.0 f c', which whill convert (19.0) degrees (f)ahrenheit to (c)elsius" << endl;
			cin >> val >> init >> end;
			if (cin.fail()) {
				cout << errormsg << endl << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
			}
			else if ((init == 'f' && end == 'c') || (init == 'c' && end == 'f')) {
				cout << "The new temperature is: " << tc.Calculate(val, init, end) << endl << endl;
			}
			else {
				cout << errormsg << endl << endl;
			}
			break;
		case 'c':
			cout << "Currency options are (u)SD, (e)uro, (y)en, (p)ound." << endl;
			cout << "Enter in this format: '19.00 e u', which whill convert (19.0) (e)uro to (u)SD dollars." << endl;
			cin >> val >> init >> end;
			if (cin.fail()) {
				cout << errormsg << endl << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else if ((init == 'u' || init == 'e' || init == 'y' || init == 'p') && (end == 'u' || end == 'e' || end == 'y' || end == 'p')) {
				double result = cc.Calculate(val, init, end);
				cout.precision(17);
				if (result >= 0.01) {
					cout << "The new value is: " << setprecision(2) << fixed << showpoint << result << endl << endl;
				}
				else {
					cout << "The new value is: " << result << endl << endl;
				}
			}
			else {
				cout << errormsg << endl << endl;
			}
			break;
		case 'e':
			cout << "Exiting..." << endl;
			return 0;
		default:
			cout << "That is not an option" << endl << endl;
			break;
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
