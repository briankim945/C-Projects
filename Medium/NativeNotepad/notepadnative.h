#ifndef NOTEPADNATIVE_H
#define NOTEPADNATIVE_H

#include <QMainWindow>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class NotepadNative; }
QT_END_NAMESPACE

class NotepadNative : public QWidget
{
    Q_OBJECT

public:
    //NotepadNative(QWidget *parent = nullptr);
    //~NotepadNative();
    NotepadNative();

private slots:
    void clear();
    void printText();
    void quit();

private:
    Ui::NotepadNative *ui;
    QTextEdit* textEdit;
    QPushButton* showText;
    QPushButton* clearText;
    QPushButton* quitButton;
    QLabel* readText;
};
#endif // NOTEPADNATIVE_H
