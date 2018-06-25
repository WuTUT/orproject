#include "mapwidget.h"
#include <iostream>
using namespace std;
MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{

    yuquanmap=new QWebEngineView(this);

    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject("context", this);
    yuquanmap->page()->setWebChannel(channel);
    yuquanmap->page()->load(QUrl("file:///D:/Documents/QTcode/orproject/baidumap.html"));



    //yuquanmap->setUrl(QUrl("file:///D:/Documents/QTcode/orproject/baidumap.html"));
    yuquanmap->show();
    yuquanmap->setMaximumSize(1000,1000);
    yuquanmap->setMinimumSize(1000,1000);

    pixx=0;
    pixy=0;
}
void MapWidget::getpixel(int x, int y){
    this->pixx=x;
    this->pixy=y;
    cout<<(this->pixx)<<" , "<<(this->pixy)<<endl;
}
MapWidget::~MapWidget(){
    this->disconnect();
}
