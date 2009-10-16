#include "qchurchview.h"

#include <QtGui>
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QChurchView w;

    QDir *dir_tmp = new QDir("/tmp/QChurchView");
    if(!dir_tmp->exists())
    	dir_tmp->mkdir("/tmp/QChurchView");
    dir_tmp = new QDir("/tmp/QChurchView/tabApresentacao");
        if(!dir_tmp->exists())
        	dir_tmp->mkdir("/tmp/QChurchView/tabApresentacao");

    w.showMaximized();
    return a.exec();
}
