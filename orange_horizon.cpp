#include "orange_horizon.h"

orange_horizon::orange_horizon(QWidget *parent):object(parent)
{
    type=13;
}

orange_horizon::~orange_horizon()
{
    delete label;
    delete button;
}

void orange_horizon::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/horizon_orange.png"));
    else
        label->setPixmap(QPixmap(":/horizon_orange_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
