#include "watermelon_vertical.h"

watermelon_vertical::watermelon_vertical(QWidget *parent):object(parent)
{
    type=24;
}

watermelon_vertical::~watermelon_vertical()
{
    delete label;
    delete button;
}

void watermelon_vertical::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/vertical_watermelon.png"));
    else
        label->setPixmap(QPixmap(":/vertical_watermelon_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
