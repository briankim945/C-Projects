#pragma once

//#include <QtWidgets/QMainWindow>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include "ui_NotepadGUI.h"

class NotepadGUI : public QWidget
{
	Q_OBJECT

public:
	//NotepadGUI(QWidget *parent = Q_NULLPTR);
	NotepadGUI();

private slots:
	void clear();
	void printText();
	void quit();

private:
	Ui::NotepadGUIClass ui;
	QTextEdit* textEdit;
	QPushButton* showText;
	QPushButton* clearText;
	QPushButton* quitButton;
	QLabel* readText;
};
