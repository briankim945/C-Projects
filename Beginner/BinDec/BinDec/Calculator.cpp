#include "Calculator.h"
#include <cmath>

int Calculator::BinCalc(int x)
{
	int power = 0;
	for (int count = 0; x / int(pow(2, count)) >= 1; count++) {
		power = count;
	};

	int bin = 0;
	for (int count = 0; power >= 0; count++) {
		int exp = int(pow(2, power));
		if (x >= exp) {
			x = x % exp;
			bin = bin * 10 + 1;
		}
		else {
			x = x % exp;
			bin = bin * 10;
		}
		power--;
	};

	return bin;
}

int Calculator::DecCalc(int x)
{
	int dec = 0;

	for (int power = 0; x > 0; power++) {
		int cf = x % 10;
		dec = dec + cf * (int(pow(2, power)));
		x = x / 10;
	}

	return dec;
}
