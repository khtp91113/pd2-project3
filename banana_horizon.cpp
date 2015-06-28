#include "banana_horizon.h"

banana_horizon::banana_horizon(QWidget *parent):object(parent)
{
    type=11;
}

banana_horizon::~banana_horizon()
{
    delete label;
    delete button;
}

void banana_horizon::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/horizon_banana.png"));
    else
        label->setPixmap(QPixmap(":/horizon_banana_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
