#include "CaesarGUI.h"

CaesarGUI::CaesarGUI()
{
	//ui.setupUi(this);

	textEntry = new QTextEdit();
	offsetLabel = new QLabel("Select the offset for the cipher:");
	offsetBox = new QSpinBox();
	offsetBox->setSingleStep(1);
	offsetBox->setValue(0);
	encodeButton = new QPushButton("&Encode");
	decodeButton = new QPushButton("&Decode");
	readText = new QLabel("");
	readText->setWordWrap(true);
	quitButton = new QPushButton("&Quit");

	connect(encodeButton, SIGNAL(clicked()), this, SLOT(encode()));
	connect(decodeButton, SIGNAL(clicked()), this, SLOT(decode()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(textEntry);
	layout->addWidget(offsetLabel);
	layout->addWidget(offsetBox);
	layout->addWidget(encodeButton);
	layout->addWidget(decodeButton);
	layout->addWidget(readText);
	layout->addWidget(quitButton);

	setLayout(layout);

	setWindowTitle(tr("Caesar Cipher Program"));
}

void CaesarGUI::encode()
{
	QString data = textEntry->toPlainText();
	std::string initText = data.toUtf8().constData();
	std::string endText = "";

	int offset = offsetBox->value();

	for (int i = 0; i < initText.length(); i++)
	{
		char letter = initText[i];
		if (!isalpha(letter))
		{
			endText += letter;
		}
		else if (isupper(letter))
		{
			int place = std::distance(alphabet, std::find(alphabet, alphabet + 26, std::string(1, tolower(letter))));
			endText += (putchar (toupper(alphabet[(place + offset) % 26][0])));
		}
		else
		{
			int place = std::distance(alphabet, std::find(alphabet, alphabet + 26, std::string(1, letter)));
			endText.append(alphabet[(place + offset) % 26]);
		}
	}

	readText->setText(QString::fromStdString(endText));
}

void CaesarGUI::decode()
{
	QString data = textEntry->toPlainText();
	std::string initText = data.toUtf8().constData();
	std::string endText = "";

	int offset = offsetBox->value();

	for (int i = 0; i < initText.length(); i++)
	{
		char letter = initText[i];
		if (!isalpha(letter))
		{
			endText += letter;
		}
		else if (isupper(letter))
		{
			int place = std::distance(alphabet, std::find(alphabet, alphabet + 26, std::string(1, tolower(letter))));
			endText += (putchar(toupper(alphabet[(place + 26 - offset) % 26][0])));
		}
		else
		{
			int place = std::distance(alphabet, std::find(alphabet, alphabet + 26, std::string(1, letter)));
			endText.append(alphabet[(place + 26 - offset) % 26]);
		}
	}

	readText->setText(QString::fromStdString(endText));
}

void CaesarGUI::quit()
{
	QMessageBox messageBox;
	messageBox.setWindowTitle(tr("Notepad"));
	messageBox.setText(tr("Do you really want to quit?"));
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	messageBox.setDefaultButton(QMessageBox::No);
	if (messageBox.exec() == QMessageBox::Yes)
		qApp->quit();
}
