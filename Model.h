#pragma once
#include <QAbstractTableModel>
#include "Service.h"

class Model : public QAbstractTableModel
{
private:
	Service& serv;

public:
	Model(Service& s) :serv{ s }
	{

	}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return this->serv.get_all_stars_serv().size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return 5;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		int row = index.row();
		int col = index.column();
		Star current = this->serv.get_all_stars_serv()[row];
		if (role == Qt::DisplayRole || role == Qt::EditRole)
		{
			switch (col)
			{
			case 0:
				return QString::fromStdString(current.get_name());
			case 1:
				return QString::fromStdString(current.get_constelatoin());
			case 2:
				return QString::fromStdString(to_string(current.get_right_asc()));
			case 3:
				return QString::fromStdString(to_string(current.get_declination()));
			case 4:
				return QString::fromStdString(to_string(current.get_diameter()));
			default:
				break;

			}
		}
		return QVariant();
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{
		
	
		if (role == Qt::DisplayRole and orientation==Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString::fromStdString("Name");
			case 1:
				return QString::fromStdString("Constellation");
			case 2:
				return QString::fromStdString("RA");
			case 3:
				return QString::fromStdString("Dec");
			case 4:
				return QString::fromStdString("Diameter");
			default:
				break;

			}
		}
		return QVariant();
	}

	void check(string a)
	{
		this->beginResetModel();
		
		this->endResetModel();


	}
	int adding(Star s)
	{
		int n = this->serv.get_all_stars_serv().size();

		for (auto a : this->serv.get_all_stars_serv())
			if (a.get_name() == s.get_name())
				return 0;

		this->beginInsertRows(QModelIndex{}, n, n);
		this->serv.add_serv(s);
		this->endInsertRows();
		return 1;
	}
	void updateind(string name,Star s)
	{

		this->serv.update_serv(name,s);
		emit dataChanged(QModelIndex{}, QModelIndex{});
	}
	//int  add_model(Idea i);
	//void clearData();
};