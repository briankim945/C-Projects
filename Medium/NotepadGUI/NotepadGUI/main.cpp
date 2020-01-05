#include "NotepadGUI.h"
//#include <QtWidgets/QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QtGui>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*
	
	//NotepadGUI w;
	//w.show();

	QTextEdit *textEdit = new QTextEdit();
	QPushButton* quitButton = new QPushButton("&Quit");

	QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(textEdit);
	layout->addWidget(quitButton);

	QWidget window;
	window.setLayout(layout);

	window.show();
	*/

	NotepadGUI n;

	n.show();

	return a.exec();
}
