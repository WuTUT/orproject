#include "mainwindow.h"

#include <string>
#include <QDebug>
#pragma execution_character_set("utf-8")


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

    qDebug()<<"start clicked";
    opw->cur_pos_show->setVisible(true);
    opw->cur_pos_label->setVisible(true);
    opw->search->setVisible(true);
    //this->mapw->p=this->mapw->yuquanmap->grab(QRect(0,0,1000,1000));
    //this->mapw->p.save("a.png","png");
    int louzuobiao[12][2]={
        {711,	387},
        {676,	497},
        {585,	300},
        {508,	445},
        {466,	274},
        {406,	415},
        {266,	151},
        {233,	382},
        {552,	772},
        {465,	714},
        {850,	410},
        {796,	560},
    };
    int zhandian[5][2]={
        {692,   462},
        {514,   719},
        {529,   401},
        {523,   277},
        {257,   176}
    };
    for (int i=0;i<=5;i++){
     mapw->yuquanmap->page()->runJavaScript(QString("setPos('%1','%2');").arg(zhandian[i][0]).arg(zhandian[i][1]));
    }

}

void MainWindow::search_clicked(){
    QString tmppos;
    tmppos=QString::number(mapw->pixx);
    tmppos.append(",");
    tmppos.append(QString::number(mapw->pixy));
    opw->cur_pos_show->setText(tmppos);
    int louzuobiao[12][2]={
        {711,	387},
        {676,	497},
        {585,	300},
        {508,	445},
        {466,	274},
        {406,	415},
        {266,	151},
        {233,	382},
        {552,	772},
        {465,	714},
        {850,	410},
        {796,	560},
    };
    int zhandian[5][2]={
        {692,   462},
        {514,   719},
        {529,   401},
        {523,   277},
        {257,   176}
    };
    double dis[12];
    for(int i=0;i<12;i++){
        dis[i]=(mapw->pixx-louzuobiao[i][0])*(mapw->pixx-louzuobiao[i][0])+(mapw->pixy-louzuobiao[i][1])*(mapw->pixy-louzuobiao[i][1]);

    }
    /*
    for(int i=0;i<12;i++){
        qDebug()<<dis[i];
    }*/
    int ti=0;
    double mindis=dis[0];
    for(int i=1;i<12;i++){
        if(dis[i]<mindis)
        {mindis=dis[i];
         ti=i;
        }

    }
    //qDebug()<<ti;
    int kn[12]={1,1,4,3,4,3,5,5,2,2,1,1};

    mapw->yuquanmap->page()->runJavaScript(QString("setAni('%1','%2');").arg(zhandian[kn[ti]-1][0]).arg(zhandian[kn[ti]-1][1]));
}
