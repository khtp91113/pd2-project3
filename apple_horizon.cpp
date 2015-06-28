#include "apple_horizon.h"

apple_horizon::apple_horizon(QWidget *parent):object(parent)
{
    type=10;
}

apple_horizon::~apple_horizon()
{
    delete label;
    delete button;
}

void apple_horizon::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/horizon_apple.png"));
    else
        label->setPixmap(QPixmap(":/horizon_apple_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
