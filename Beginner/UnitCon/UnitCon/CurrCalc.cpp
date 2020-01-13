#include "CurrCalc.h"

CurrCalc::CurrCalc()
{
	CurrCalc::USDtoEuro = 0.897990;
	CurrCalc::USDtoYen = 108.161813;
	CurrCalc::USDtoPound = 0.773405;
	CurrCalc::EurotoUSD = 1.113754;
	CurrCalc::EurotoYen = 120.429484;
	CurrCalc::EurotoPound = 0.861221;
	CurrCalc::PoundtoUSD = 1.293248;
	CurrCalc::PoundtoEuro = 1.161136;
	CurrCalc::PoundtoYen = 139.836007;
	CurrCalc::YentoUSD = 0.009248;
	CurrCalc::YentoEuro = 0.008304;
	CurrCalc::YentoPound = 0.007151;
}

double CurrCalc::Calculate(double val, char init, char end)
{
	if (init == 'u') {
		if (end == 'e') {
			return val * USDtoEuro;
		}
		else if (end == 'y') {
			return val * USDtoYen;
		}
		else if (end == 'p') {
			return val * USDtoPound;
		}
		else {
			return val;
		}
	}
	else if (init == 'e') {
		if (end == 'u') {
			return val * EurotoUSD;
		}
		else if (end == 'y') {
			return val * EurotoYen;
		}
		else if (end == 'p') {
			return val * EurotoPound;
		}
		else {
			return val;
		}
	}
	else if (init == 'p') {
		if (end == 'e') {
			return val * PoundtoEuro;
		}
		else if (end == 'y') {
			return val * PoundtoYen;
		}
		else if (end == 'u') {
			return val * PoundtoUSD;
		}
		else {
			return val;
		}
	}
	else if (init == 'y') {
		if (end == 'e') {
			return val * YentoEuro;
		}
		else if (end == 'u') {
			return val * YentoUSD;
		}
		else if (end == 'p') {
			return val * YentoPound;
		}
		else {
			return val;
		}
	}
	else {
		return val;
	}
}
