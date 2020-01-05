#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CalcGUI.h"

class CalcGUI : public QMainWindow
{
	Q_OBJECT

public:
	CalcGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::CalcGUIClass ui;
};
