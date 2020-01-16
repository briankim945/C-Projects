#pragma once

#include <QtWidgets/QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include "ui_TextEditor.h"
#include <string>
#include <fstream>

class TextEditor : public QWidget
{
	Q_OBJECT

public:
	//TextEditor(QWidget *parent = Q_NULLPTR);
	TextEditor();

private slots:
	//void open();
	void quit();
	void save();

private:
	//Ui::TextEditorClass ui;
	QTextEdit* text_edit;
	QLabel* text_label;
	QLineEdit* file_name;
	QPushButton* save_button;
	//QPushButton* open_button;
	QPushButton* quit_button;
};
