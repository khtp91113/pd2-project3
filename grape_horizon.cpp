#include "grape_horizon.h"

grape_horizon::grape_horizon(QWidget *parent):object(parent)
{
    type=12;
}

grape_horizon::~grape_horizon()
{
    delete label;
    delete button;
}

void grape_horizon::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/horizon_grape.png"));
    else
        label->setPixmap(QPixmap(":/horizon_grape_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
