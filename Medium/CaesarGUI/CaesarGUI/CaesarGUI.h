#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CaesarGUI.h"
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSpinBox>
#include <string>
#include <algorithm>

class CaesarGUI : public QWidget
{
	Q_OBJECT

public:
	//CaesarGUI(QWidget *parent = Q_NULLPTR);
	CaesarGUI();

private slots:
	void encode();
	void decode();
	void quit();

private:
	Ui::CaesarGUIClass ui;
	QTextEdit* textEntry;
	QLabel* offsetLabel;
	QSpinBox* offsetBox;
	QPushButton* encodeButton;
	QPushButton* decodeButton;
	QLabel* readText;
	QPushButton* quitButton;
	std::string alphabet [26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l",
	"m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
};
