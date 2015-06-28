#include "watermelon_horizon.h"

watermelon_horizon::watermelon_horizon(QWidget *parent):object(parent)
{
    type=14;
}

watermelon_horizon::~watermelon_horizon()
{
    delete label;
    delete button;
}

void watermelon_horizon::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/horizon_watermelon.png"));
    else
        label->setPixmap(QPixmap(":/horizon_watermelon_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
