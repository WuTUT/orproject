#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QUrl>
#include <QWebEngineView>
#include <QWebChannel>
#include <QPaintEvent>
#include <QString>
class MapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = 0);

public:
    QWebEngineView* yuquanmap;


signals:

public slots:

};

#endif // MAPWIDGET_H
