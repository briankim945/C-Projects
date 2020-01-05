#include "CalcGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CalcGUI w;
	w.show();
	return a.exec();
}
