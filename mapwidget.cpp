#include "mapwidget.h"

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


}


