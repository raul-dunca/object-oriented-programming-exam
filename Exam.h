#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Exam.h"

class Exam : public QMainWindow
{
    Q_OBJECT

public:
    Exam(QWidget *parent = Q_NULLPTR);

private:
    Ui::ExamClass ui;
};
