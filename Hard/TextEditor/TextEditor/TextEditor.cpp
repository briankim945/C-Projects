#include "TextEditor.h"
/*
TextEditor::TextEditor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}*/

void TextEditor::quit()
{
	QMessageBox messageBox;
	messageBox.setWindowTitle(tr("Quit"));
	messageBox.setText(tr("Do you really want to quit?"));
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	messageBox.setDefaultButton(QMessageBox::No);
	if (messageBox.exec() == QMessageBox::Yes)
		qApp->quit();
}

void TextEditor::save()
{
	std::string file_title;
	QString data = text_edit->toPlainText();
	QMessageBox messageBox;
	messageBox.setWindowTitle(tr("Save"));
	messageBox.setText(tr("Do you really want to save?"));

	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	messageBox.setDefaultButton(QMessageBox::Yes);
	file_title = file_name->text().toUtf8().constData();
	file_title += ".txt";

	if (messageBox.exec() == QMessageBox::Yes)
	{
		std::ofstream outfile(file_title);

		outfile << data.toUtf8().constData() << std::endl;

		outfile.close();
	}
}
/*
void TextEditor::open()
{

}*/

TextEditor::TextEditor()
{
	file_name = new QLineEdit();
	text_edit = new QTextEdit();
	save_button = new QPushButton("&Save");
	//open_button = new QPushButton("&Open");
	quit_button = new QPushButton("&Quit");
	text_label = new QLabel();

	text_label->setText("File name (omit file extension): ");
	file_name->setText("Untitled");

	connect(save_button, SIGNAL(clicked()), this, SLOT(save()));
	connect(quit_button, SIGNAL(clicked()), this, SLOT(quit()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(text_label);
	layout->addWidget(file_name);
	layout->addWidget(text_edit);
	layout->addWidget(save_button);
	layout->addWidget(quit_button);

	setLayout(layout);

	setWindowTitle(tr("Unsaved File"));
}
