#include "TempCalc.h"

double TempCalc::Calculate(double val, char init, char end)
{
	if (init == 'f' && end == 'c') {
		return (val - 32.0) * (5.0 / 9.0);
	}
	else if (init == 'c' && end == 'f') {
		return (val * 1.8) + 32;
	}
	else {
		return val;
	}
}
