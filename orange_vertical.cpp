#include "orange_vertical.h"

orange_vertical::orange_vertical(QWidget *parent):object(parent)
{
    type=23;
}

orange_vertical::~orange_vertical()
{
    delete label;
    delete button;
}

void orange_vertical::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/vertical_orange.png"));
    else
        label->setPixmap(QPixmap(":/vertical_orange_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
