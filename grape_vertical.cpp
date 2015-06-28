#include "grape_vertical.h"

grape_vertical::grape_vertical(QWidget *parent):object(parent)
{
    type=22;
}

grape_vertical::~grape_vertical()
{
    delete label;
    delete button;
}

void grape_vertical::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/vertical_grape.png"));
    else
        label->setPixmap(QPixmap(":/vertical_grape_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
