#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QDebug>
class OptionsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OptionsWidget(QWidget *parent = 0);
    QPushButton* start;
    QPushButton* search;
    QLabel* cur_pos_label;
    QLabel* cur_pos_show;

    QGridLayout* optionsLayout;
signals:

public slots:
};

#endif // OPTIONSWIDGET_H
