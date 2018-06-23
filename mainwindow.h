#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "mapwidget.h"
#include "optionswidget.h"
#include <QLayout>
#include <QString>
class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MapWidget* mapw;
    OptionsWidget* opw;
    QGridLayout* mainLayout;
    double cur_lng;
    double cur_lat;
public:
    MainWindow(QWidget *parent = 0);
public slots:
    void start_clicked();
    void search_clicked();
};

#endif // MAINWINDOW_H
