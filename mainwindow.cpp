#include "mainwindow.h"
#include <iostream>
#include <string>
#include <QDebug>
#pragma execution_character_set("utf-8")
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(1200,1000);
    setMaximumSize(1200,1000);

    mapw=new MapWidget(this);
    opw=new OptionsWidget(this);

    mainLayout=new QGridLayout();
    mainLayout->addWidget(opw,0,11,5,2);
    mainLayout->addWidget(mapw,0,0,12,10);

    connect(opw->start,&QPushButton::clicked,this,&MainWindow::start_clicked);
    connect(opw->search,&QPushButton::clicked,this,&MainWindow::search_clicked);

    mainLayout->setMargin(0);
    cur_lng=120.130782;
    cur_lat=30.271989;

    this->setLayout(mainLayout);



}

void MainWindow::start_clicked(){

    cout<<"start_clicked"<<endl;
    opw->cur_pos_show->setVisible(true);
    opw->cur_pos_label->setVisible(true);
    opw->search->setVisible(true);
    //this->mapw->p=this->mapw->yuquanmap->grab(QRect(0,0,1000,1000));
    //this->mapw->p.save("a.png","png");
}

void MainWindow::search_clicked(){
    QString tmppos;
    tmppos=QString::number(cur_lng);
    tmppos.append(",");
    tmppos.append(QString::number(cur_lat));
    opw->cur_pos_show->setText(tmppos);
    mapw->yuquanmap->page()->runJavaScript(QString("setPos('%1','%2');").arg(mapw->pixx).arg(mapw->pixy));
}
