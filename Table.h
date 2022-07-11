#pragma once

#include <QWidget>
#include "ui_Table.h"
#include "Model.h"
#include <QMessageBox>
class Table : public QWidget
{
	Q_OBJECT

public:
	Table(Astronomer s,Model* model,QWidget *parent = Q_NULLPTR);
	void check_ui()
	{
		if (this->ui.checkBox->isChecked())
		{
			this->m->check("all");
		}
		else
		{
			this->m->check("a");
		}
	}
	void add()
	{
		string s1 = (this->ui.nameEdit->text()).toStdString();
		string s2 = (this->ui.RAEdit->text()).toStdString();
		string s3 = (this->ui.decEdit->text()).toStdString();
		string s4 = (this->ui.diameterEdit->text()).toStdString();

		if (s1 == "")
		{
			QMessageBox m;
			m.critical(0, "Error", "Please fill the name line!");
			m.setFixedSize(500, 200);
			return;
		}
		else
		{
			int k;
			k = this->m->adding(Star{s1,this->a.get_constelatoin(),stoi(s2),stoi(s3),stod(s4)});
			if (k == 0)
			{
				QMessageBox m;
				m.critical(0, "Error", "Cant have 2 stars with the same name");
				m.setFixedSize(500, 200);
				return;
			}
		}
	}
	void update()
	{
		string s1 = (this->ui.nameEdit->text()).toStdString();
		string s2 = (this->ui.RAEdit->text()).toStdString();
		string s3 = (this->ui.decEdit->text()).toStdString();
		string s4 = (this->ui.diameterEdit->text()).toStdString();
		//this->ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
		if (s1 == "")
		{
			QMessageBox m;
			m.critical(0, "Error", "Please fill the name line!");
			m.setFixedSize(500, 200);
			return;
		}
		else
		{
			if (stod(s4) <= 10)
			{
				QMessageBox m;
				m.critical(0, "Error", "Diameter must be greater than 10!");
				m.setFixedSize(500, 200);
				return;
			}
			else
			{
				
				this->m->updateind(s1,Star{ s1,this->a.get_constelatoin(),stoi(s2),stoi(s3),stod(s4) });
				
			}

		}
	}
private:
	Ui::Table ui;
	Astronomer a;
	Model* m;
};
