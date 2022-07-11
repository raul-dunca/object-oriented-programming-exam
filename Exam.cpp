#include "Exam.h"

Exam::Exam(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}





























// string s= this->ui.WidgetList->currentItem()->text().toStdString();
// stringstream



/*QObject::connect(this->SearchEdit, &QLineEdit::textChanged, this, &FilterGUI::populateGenesList);


void FilterGUI::populateGenesList()
{
	string text;
	text = this->SearchEdit->text().toStdString();
	// clear the list, if there are elements in it

	if (this->coatsList->count() > 0)
	{
		this->coatsList->clear();
	}

	for (auto g : this->serv.get_vector())
	{
		QString itemInList = QString::fromStdString("Coat with size: " + g.getSize() + ", colour: " + g.getColour() + ", price: " + to_string(g.getPrice()) + ", quantity: " + to_string(g.getQuantity()) + " and photo: " + g.getPhoto());
		QFont f{ "Verdana", 15 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		if (itemInList.toStdString().find(text) != std::string::npos || text == "")					//if filter
		{
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			item->setFont(f);
			this->coatsList->addItem(item);
		}
		//this->coatsList->addItem(item);


	}


}

*/
//emit DataChanged(QmodelIndex{},QModelIndex{});
