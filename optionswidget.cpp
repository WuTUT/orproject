#include "optionswidget.h"

OptionsWidget::OptionsWidget(QWidget *parent) : QWidget(parent)
{
    start=new QPushButton(this);
    start->setText(tr("建立站点"));
    search=new QPushButton(this);
    search->setText(tr("搜索最近站点"));
    cur_pos_label=new QLabel("当前位置");
    cur_pos_show=new QLabel("0,0");
    search->setVisible(false);
    cur_pos_label->setVisible(false);
    cur_pos_show->setVisible(false);
    optionsLayout=new QGridLayout();
    optionsLayout->addWidget(start,0,0,1,2);
    optionsLayout->addWidget(cur_pos_label,1,0,1,1);
    optionsLayout->addWidget(cur_pos_show,1,1,1,1);
    optionsLayout->addWidget(search,2,0,1,2);
    optionsLayout->setSpacing(8);

    this->setLayout(optionsLayout);

}
