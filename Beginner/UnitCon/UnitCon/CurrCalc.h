#pragma once
class CurrCalc
{
private:
	double USDtoEuro;
	double USDtoYen;
	double USDtoPound;
	double EurotoUSD;
	double EurotoYen;
	double EurotoPound;
	double PoundtoUSD;
	double PoundtoEuro;
	double PoundtoYen;
	double YentoUSD;
	double YentoEuro;
	double YentoPound;
public:
	CurrCalc();

	double Calculate(double val, char init, char end);
};

