﻿#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        qDebug()<<"Unable to set stylesheet, file not found\n";

    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }


    MainWindow w;
    w.show();


    return a.exec();
}
