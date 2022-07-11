#include "Exam.h"
#include <QtWidgets/QApplication>
#include "Table.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    

    Repo r;
    Service s{ r };
    Model* m = new Model{ s };
    for (auto a : s.get_all_astronomers_serv())
    {
        Table* w = new Table{ a,m };
        w->show();
        //Table w{ s.get_all_astronomers_serv()[0],m};
        /*w.show();
        Table ww{ s.get_all_astronomers_serv()[1],m };
        ww.show();*/
        
    }
   
    return a.exec();
}
