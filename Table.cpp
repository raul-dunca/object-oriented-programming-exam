#include "Table.h"

Table::Table(Astronomer as,Model* model,QWidget *parent)
	: QWidget(parent),a{as},m{model}
{
	ui.setupUi(this);
	
	this->ui.tableView->setModel(model);
	this->setWindowTitle(QString::fromStdString(this->a.get_name()));
	QApplication::connect(this->ui.addBUtton, &QPushButton::clicked, this, &Table::add);
	QApplication::connect(this->ui.UpdateButton, &QPushButton::clicked, this, &Table::update);
	QApplication::connect(this->ui.checkBox, &QCheckBox::clicked, this, &Table::check_ui);
}


