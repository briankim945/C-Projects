#include "notepadnative.h"
#include "ui_notepadnative.h"
/*
NotepadNative::NotepadNative(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotepadNative)
{
    ui->setupUi(this);
}

NotepadNative::~NotepadNative()
{
    delete ui;
}
*/

void NotepadNative::quit()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle(tr("Notepad"));
    messageBox.setText(tr("Do you really want to quit?"));
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    if (messageBox.exec() == QMessageBox::Yes)
        qApp->quit();
}

void NotepadNative::printText() {
    QString data = textEdit->toPlainText();
    readText->setText(data);
}

void NotepadNative::clear() {
    textEdit->clear();
}

NotepadNative::NotepadNative()
{
    //ui.setupUi(this);

    textEdit = new QTextEdit();
    showText = new QPushButton("&Print");
    clearText = new QPushButton("&Clear");
    quitButton = new QPushButton("&Quit");
    readText = new QLabel("");
    readText->setWordWrap(true);

    connect(showText, SIGNAL(clicked()), this, SLOT(printText()));
    connect(clearText, SIGNAL(clicked()), this, SLOT(clear()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(readText);
    layout->addWidget(showText);
    layout->addWidget(clearText);
    layout->addWidget(quitButton);

    setLayout(layout);

    setWindowTitle(tr("Notepad"));
}
