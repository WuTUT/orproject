#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QUrl>
#include <QWebEngineView>
#include <QWebChannel>
#include <QString>
#include <QMouseEvent>
#include <QPixmap>
class MapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = 0);
    ~MapWidget();
public:
    QWebEngineView* yuquanmap;
    QPixmap p;
    int pixx;
    int pixy;
protected:


signals:

public slots:
    void getpixel(int x,int y);
};

#endif // MAPWIDGET_H
