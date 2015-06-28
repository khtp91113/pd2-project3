#include "apple_vertical.h"

apple_vertical::apple_vertical(QWidget *parent):object(parent)
{
    type=20;
}

apple_vertical::~apple_vertical()
{
    delete label;
    delete button;
}

void apple_vertical::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/vertical_apple.png"));
    else
        label->setPixmap(QPixmap(":/vertical_apple_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
